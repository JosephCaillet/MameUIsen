//
// Created by joseph on 16/11/15.
//

#include <fstream>
#include <iostream>
#include <string.h>
#include "RomListManager.h"

using namespace std;

//Constructors
RomListManager::RomListManager()
{
	loadCategories();
	loadGames();
}

//Getters
RomList& RomListManager::getPreviousRomList()
{
	updateCurrentRomSetIndex('-');
	return romListsArray[currentRomSetIndex - 1];
}

RomList& RomListManager::getNextRomList()
{
	updateCurrentRomSetIndex('-');
	return romListsArray[currentRomSetIndex - 1];
}

//Member Functions
void RomListManager::loadCategories()
{
	ifstream categoriesConfFile("../config/categories.cfg", ios::in);
	if(!categoriesConfFile)
	{
		cerr << "Can't open config/categories.cfg  : " << strerror(errno) << endl;
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
				romListsArray[categoryNumber-1] = RomList(line.substr(*pos, string::npos));
				delete pos;
			}

		}
	}
}

void RomListManager::loadGames()
{

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
			currentRomSetIndex = 0;
		}
	}
}