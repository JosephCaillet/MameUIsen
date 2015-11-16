//
// Created by joseph on 16/11/15.
//

#ifndef MAMEUISEN_ROMLISTMANAGER_H
#define MAMEUISEN_ROMLISTMANAGER_H

#include <vector>
#include "Rom.h"
#include "RomList.h"

class RomListManager
{
private:
	std::vector<Rom> roms;
	std::vector<RomList> romListsArray;
	int currentRomSetIndex;//begin at 1

public:
	//Constructor
	RomListManager();

	//Getters
	RomList& getPreviousRomList();
	RomList& getNextRomList();

private:
	//Member functions
	void loadCategories();
	void loadGames();
	void updateCurrentRomSetIndex(char sign);
};


#endif //MAMEUISEN_ROMLISTMANAGER_H