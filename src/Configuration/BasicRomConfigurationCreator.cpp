//
// Created by joseph on 02/01/16.
//

#include <dirent.h>
#include <iomanip>
#include <fstream>
#include "BasicRomConfigurationCreator.h"
#include "../lib/tinyxml2/tinyxml2.h"

using namespace std;

BasicRomConfigurationCreator::BasicRomConfigurationCreator(const std::string configFilePath) : configuration(configFilePath)
{ }

void BasicRomConfigurationCreator::listsRoms()
{
	cout << endl << "-> Listing existing roms..." << endl;

	DIR* romDir = nullptr;
	romDir = opendir(configuration.getRom_path().c_str());

	if(romDir == nullptr)
	{
		cerr << "Can't open \"" << configuration.getRom_path() << "\" : " << strerror(errno) << std::endl;
	}

	dirent* currentRomFile = nullptr;

	cout << "Found roms are :" << endl;

	while((currentRomFile = readdir(romDir)) != nullptr)
	{
		string romDirName(currentRomFile->d_name);

		if(romDirName != "." && romDirName != "..")
		{
			size_t pos = romDirName.find(".zip");
			if(pos != string::npos)
			{
				//removing .zip
				romDirName.erase(pos);
				romsNamesList.push(romDirName);

				cout << romDirName << endl;
			}
		}
	}

	closedir(romDir);
}

void BasicRomConfigurationCreator::askMameForRomsXMLFile()
{
	cout << endl << "-> Asking mame for roms list in a temporary file..." << endl;

	string s = configuration.getMame_path() + " -listxml > " + XML_ROM_LIST_MAME;
	system(s.c_str());
}

void BasicRomConfigurationCreator::deleteMameRomsXMLFile()
{
	cout << endl << "-> Deleting temporary file..." << endl;
	remove(XML_ROM_LIST_MAME);
}

void BasicRomConfigurationCreator::parseXML()
{
	cout << endl << "-> Loading roms list file..." << endl;

	tinyxml2::XMLDocument xmlMameRomsDocument;
	xmlMameRomsDocument.LoadFile(XML_ROM_LIST_MAME);

	if(xmlMameRomsDocument.ErrorID() != tinyxml2::XML_NO_ERROR)
	{
		string s;
		s = s + "Error while opening \"" + XML_ROM_LIST_MAME + "\" : " + xmlMameRomsDocument.ErrorName();
		cerr << s;
		exit(EXIT_FAILURE);
	}

	tinyxml2::XMLElement* game = nullptr;
	game = xmlMameRomsDocument.FirstChildElement("mame")->FirstChildElement("game");
	if(game == nullptr)
	{
		cerr << "Error while parsing\"" << XML_ROM_LIST_MAME << ", no <game> element find in a root <mame> element.";
		exit(EXIT_FAILURE);
	}

	cout << endl << "-> Parsing roms list file..." << endl;

	cout << "Found roms infos are :" << endl;

	while(game != nullptr)
	{
		if(game->Attribute("isdevice") != nullptr)//<game> representing a rom does not have this attribute, and mame sorts all <game> with this attribute, that's why we stop parsing when reading it.
		{
			break;
		}

		tinyxml2::XMLElement* description = nullptr;
		tinyxml2::XMLElement* year = nullptr;
		tinyxml2::XMLElement* manufacturer = nullptr;

		description = game->FirstChildElement("description");
		year = game->FirstChildElement("year");
		manufacturer = game->FirstChildElement("manufacturer");

		if(strcmp(game->Attribute("name"), romsNamesList.top().c_str()) == 0)
		{
			romsNamesList.pop();
			romsList.insert(RomWithCategories(
					string(description->GetText()),
					string(game->Attribute("name")),
					string(manufacturer->GetText()),
					string(year->GetText())
			));
			cout << right << setw(10) << game->Attribute("name") << setw(50) << description->GetText() << setw(6) << year->GetText() << setw(30) << manufacturer->GetText() << endl;
		}

		game = game->NextSiblingElement();
	}
}

void BasicRomConfigurationCreator::createCategoriesAndGamesConfiguration(const std::string& catlistFilePath)
{
	listsRoms();
	//askMameForRomsXMLFile();
	parseXML();
	linkRomsToCategories(catlistFilePath);
	writeCategoriesConfig();
	writeGamesConfig();
	//deleteMameRomsXMLFile();
}

void BasicRomConfigurationCreator::linkRomsToCategories(const string& catlistFilePath)
{
	categoriesList.push_back(configuration.getAll_roms_category_name());
	for(auto& rom : romsList)
	{
		//std::set iterators are always const to avoid changing datas used to sort the set.
		//But as addCategoryNumber() do not change a data used to sort, i need to force the reference to be non const.
		//I could have set datas changed by addCategoryNumber() mutable, but in this case i have to declare
		//addCategoryNumber() const (to be able to call id here, anI do not want to do that, because
		// this function is not really const, as it updates members.
		RomWithCategories& r = const_cast<RomWithCategories&>(rom);
		r.addCategoryNumber(0);
	}

	if(catlistFilePath != "")
	{
		cout << endl << "-> Reading file associating categories and roms..." << endl;

		ifstream romsCategoriesFile(catlistFilePath, ios::in);
		if(!romsCategoriesFile)
		{
			cerr << "Can't open \"" << catlistFilePath << "\" : " << strerror(errno) << endl;
			exit(EXIT_FAILURE);
		}

		string line;
		string categoryName;
		int categoryIndex = 1;
		bool romFoundInCurrentCategory = false;

		while(getline(romsCategoriesFile, line))
		{
			if(line.empty())
			{
				continue;
			}

			if(line[0] == '[')
			{
				if(romFoundInCurrentCategory)
				{
					romFoundInCurrentCategory = false;
					categoryIndex++;
					categoriesList.push_back(categoryName);
				}

				categoryName = line.substr(1, line.length()-2);
				cout << "Exploring category " << categoryName << "..." << endl;
				continue;
			}

			std::set<RomWithCategories>::iterator romwcIterator;
			romwcIterator = romsList.find(RomWithCategories(line));
			if(romwcIterator != romsList.end())
			{
				cout << "\tFound : " << line << endl;
				const RomWithCategories& romFoundConst = *romwcIterator;
				RomWithCategories& romFound = const_cast<RomWithCategories&>(romFoundConst);//see comment above
				romFound.addCategoryNumber(categoryIndex);
				romFoundInCurrentCategory = true;
			}
		}
	}
}

void BasicRomConfigurationCreator::writeCategoriesConfig()
{
	cout << endl << "-> Writing category configuration file..." << endl;

	ofstream catConfFile("../config/categories.cfg", ios::trunc);
	if(!catConfFile)
	{
		cerr << "Can't open config/categories.cfg : " << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}

	for(unsigned int i=0; i<categoriesList.size(); i++)
	{
		catConfFile << i << " " << categoriesList[i] << endl;
	}
}

void BasicRomConfigurationCreator::writeGamesConfig()
{
	cout << endl << "-> Writing roms configuration file..." << endl;

	ofstream gamesConfFile("../config/games.cfg", ios::trunc);
	if(!gamesConfFile)
	{
		cerr << "Can't open config/games.cfg : " << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}

	for(const auto& rom : romsList)
	{
		gamesConfFile << rom.getDescription() << ";" << rom.getFilename() << ";" <<  rom.getManufacturer()<< ";" << rom.getYear() << ";" << rom.getCategoryNubers() << endl;
	}
}

void BasicRomConfigurationCreator::disp()
{
	for (set<RomWithCategories>::iterator i = romsList.begin(); i != romsList.end(); i++) {
		cout << i->getFilename() << endl;
	}
	std::cout << std::endl;
}
