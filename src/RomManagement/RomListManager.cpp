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
RomListManager::RomListManager(const Configuration& configuration)
{
	loadCategories(configuration);
	loadRoms(configuration);
	sortRomsList();
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
void RomListManager::loadTextures(const Configuration& configuration, const Theme& theme)
{
	for(auto & rom : roms)
	{
		bool loadingOk = rom.getTexture().loadFromFile(configuration.getScreenshots_path() + "/" + rom.getFilename() + ".png");
		if(loadingOk)
		{
			rom.setIsTextureCorrectlyLoaded(true);
			rom.getTexture().setSmooth(theme.isRom_screenshot_smooth_zoom());
		}
	}
}

void RomListManager::initText(const Theme& theme, const sf::Font& font)
{
	for(auto & rom : roms)
	{
		sf::Text& text = rom.getTextSprite();
		text.setFont(font);
		text.setColor(sf::Color(theme.getRom_name_color_red(),
								theme.getRom_name_color_green(),
								theme.getRom_name_color_blue(),
								theme.getRom_name_color_alpha()));
		text.setCharacterSize(theme.getRom_name_size());

		if((int)rom.getDescription().length() > theme.getRom_name_max_length())
		{
			text.setString(rom.getDescription().substr(0, theme.getRom_name_max_length()) + theme.getRom_name_suffix_max_length());
		}
		else
		{
			text.setString(rom.getDescription());
		}
	}
}

void RomListManager::loadCategories(const Configuration& configuration)
{
	ifstream categoriesConfFile(configuration.getCategories_config_path(), ios::in);
	if(!categoriesConfFile)
	{
		cerr << "Can't open \"" << configuration.getCategories_config_path() << "\" : " << strerror(errno) << endl;
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

void RomListManager::loadRoms(const Configuration& configuration)
{
	ifstream romsConfFile(configuration.getGames_config_path(), ios::in);
	if(!romsConfFile)
	{
		cerr << "Can't open \"" << configuration.getGames_config_path() << "\" : " << strerror(errno) << endl;
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

void RomListManager::sortRomsList()
{
	for(unsigned int i = 0; i < romListsArray.size(); i++)
	{
		romListsArray[i].sort();
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