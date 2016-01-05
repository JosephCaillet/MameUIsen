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
	cout << "-> Listing existing roms..." << endl;

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
	cout << "-> Asking mame for roms list in a temporary file..." << endl;

	string s = configuration.getMame_path() + " -listxml > " + XML_ROM_LIST_MAME;
	system(s.c_str());
}

void BasicRomConfigurationCreator::deleteMameRomsXMLFile()
{
	cout << "-> Deleting temporary file..." << endl;
	remove(XML_ROM_LIST_MAME);
}

void BasicRomConfigurationCreator::parseXML()
{
	cout << "-> Loading roms list file..." << endl;

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

	cout << "-> Parsing roms list file..." << endl;

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
			romsList.insert(Rom(
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
	askMameForRomsXMLFile();
	parseXML();
	bool multipleCategories = true;
	if(catlistFilePath == "")
	{
		multipleCategories = false;
	}
	writeCategoriesConfig(multipleCategories);
	writeGamesConfig(multipleCategories);
	deleteMameRomsXMLFile();
}

void BasicRomConfigurationCreator::writeCategoriesConfig(bool multipleCategories)
{
	cout << "-> Writing category configuration file..." << endl;

	ofstream catConfFile("../config/categories.cfg", ios::trunc);
	if(!catConfFile)
	{
		cerr << "Can't open config/categories.cfg : " << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}
	catConfFile << "0 " << configuration.getAll_roms_category_name() << endl;
}

void BasicRomConfigurationCreator::writeGamesConfig(bool multipleCategories)
{
	cout << "-> Writing roms configuration file (with single category option)..." << endl;

	ofstream gamesConfFile("../config/games.cfg", ios::trunc);
	if(!gamesConfFile)
	{
		cerr << "Can't open config/games.cfg : " << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}

	for(const auto& rom : romsList)
	{
		gamesConfFile << rom.getDescription() << ";" << rom.getFilename() << ";" <<  rom.getManufacturer()<< ";" << rom.getYear() << ";" << "0" << endl;
	}
}

void BasicRomConfigurationCreator::disp()
{
	for (set<Rom>::iterator i = romsList.begin(); i != romsList.end(); i++) {
		cout << i->getFilename() << endl;
	}
	std::cout << std::endl;
}
