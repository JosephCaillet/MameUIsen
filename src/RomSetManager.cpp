//
// Created by joseph on 16/11/15.
//

#include "RomSetManager.h"

RomListManager::RomListManager()
{
	loadCategories();
	loadGames();
}

RomList& RomListManager::getPreviousRomList()
{
	updateCurrentRomSetIndex('-');
	return romSets[currentRomSetIndex-1];
}

RomList& RomListManager::getNextRomList()
{
	updateCurrentRomSetIndex('-');
	return romSets[currentRomSetIndex-1];
}

void RomListManager::loadCategories()
{

}

void RomListManager::loadGames()
{

}

void RomListManager::updateCurrentRomSetIndex(char sign)
{
	if(sign == '+')
	{
		if(currentRomSetIndex + 1 > romSets.size())
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
			currentRomSetIndex = romSets.size();
		}
		else
		{
			currentRomSetIndex = 0;
		}
	}
}