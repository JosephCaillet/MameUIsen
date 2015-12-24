//
// Created by joseph on 16/11/15.
//

#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>
#include "RomListManager.h"

using namespace std;

//Constructors
RomListManager::RomListManager()
{
	loadCategories();
	loadRoms();
}

//Getters
RomList* RomListManager::getPreviousRomList()
{
	updateCurrentRomSetIndex('-');
	return &romListsArray[currentRomSetIndex-1];
}

RomList* RomListManager::getNextRomList()
{
	updateCurrentRomSetIndex('+');
	return &romListsArray[currentRomSetIndex-1];
}

int RomListManager::getCurrentRomSetIndex()
{
	return currentRomSetIndex;
}

int RomListManager::getRomSetNumber()
{
	return (int) romListsArray.size();
}

//Member Functions
void RomListManager::loadTextures(const Configuration& configuration)
{
	for(auto & rom : roms)
	{
		bool loadingOk = rom.getTexture().loadFromFile(configuration.getScreenshots_path() + "/" + rom.getFilename() + ".png");
		if(loadingOk)
		{
			rom.setIsTextureCorrectlyLoaded(true);
		}
	}
}

void RomListManager::initText(const Configuration& configuration, const sf::Font& font)
{
	for(auto & rom : roms)
	{
		sf::Text& text = rom.getTextSprite();
		text.setFont(font);
		text.setColor(sf::Color(configuration.getRom_name_color_red(),
								configuration.getRom_name_color_green(),
								configuration.getRom_name_color_blue(),
								configuration.getRom_name_color_alpha()));
		text.setCharacterSize(configuration.getRom_name_size());

		if(rom.getDescription().length() > configuration.getRom_name_max_length())
		{
			text.setString(rom.getDescription().substr(0, configuration.getRom_name_max_length()) + configuration.getRom_name_suffix_max_length());
		}
		else
		{
			text.setString(rom.getDescription());
		}
	}
}

void RomListManager::loadCategories()
{
	ifstream categoriesConfFile("../config/categories.cfg", ios::in);
	if(!categoriesConfFile)
	{
		cerr << "Can't open config/categories.cfg : " << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		int nbLines = 0;
		string line;

		while(getline(categoriesConfFile, line))
		{
			if(line[0] != '#')
			{
				nbLines++;
			}
		}

		romListsArray.resize((unsigned long) nbLines);
		categoriesConfFile.clear();
		categoriesConfFile.seekg(0);

		while(getline(categoriesConfFile, line))
		{
			if(line[0] != '#')
			{
				size_t* pos = new size_t;
				int categoryNumber = stoi(line, pos);
				romListsArray[categoryNumber] = RomList(line.substr(*pos+1, string::npos));
				delete pos;
			}
		}
	}
}

void RomListManager::loadRoms()
{
	ifstream romsConfFile("../config/games.cfg", ios::in);
	if(!romsConfFile)
	{
		cerr << "Can't open config/games.cfg : " << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		string line;

		int nbLines = 0;

		while(getline(romsConfFile, line))
		{
			if(line[0] != '#')
			{
				nbLines++;
			}
		}

		//Set final vector capacity, because we will use pointer on it's content, so we don't want it's content moved in memory.
		roms.resize((unsigned long) nbLines);
		romsConfFile.clear();
		romsConfFile.seekg(0);

		string romProp;
		nbLines = 0;
		while(getline(romsConfFile, line))
		{
			vector<string> romProperties;
			if(line[0] != '#')
			{
				istringstream iss(line);
				while(getline(iss, romProp, ';'))//String tokenizer
				{
					romProperties.push_back(romProp);
				}

				if(romProperties.size() < 4)
				{
					cerr << "Syntax error in file config/games.cfg with line : " << line;
					exit(EXIT_FAILURE);
				}

				Rom rom(romProperties[0], romProperties[1], romProperties[2], romProperties[3]);
				roms[nbLines] = rom;
				for(unsigned int i=4; i<romProperties.size(); i++)
				{
					romListsArray[atoi(romProperties[i].c_str())].addRom(&roms[nbLines]);//Adding loaded rom pointer to a category
				}
				nbLines++;
			}
		}
	}
}

void RomListManager::updateCurrentRomSetIndex(char sign)
{
	if(sign == '+')
	{
		if(currentRomSetIndex + 1 > (int) romListsArray.size())
		{
			currentRomSetIndex = 1;
		}
		else
		{
			currentRomSetIndex++;
		}
	}
	else if(sign == '-')
	{
		if(currentRomSetIndex - 1 < 1)
		{
			currentRomSetIndex = (int) romListsArray.size();
		}
		else
		{
			currentRomSetIndex--;
		}
	}
}