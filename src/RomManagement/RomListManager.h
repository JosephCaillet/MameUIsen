//
// Created by joseph on 16/11/15.
//

#ifndef MAMEUISEN_ROMLISTMANAGER_H
#define MAMEUISEN_ROMLISTMANAGER_H

#include <vector>
#include "Rom.h"
#include "RomList.h"
#include "../Configuration/Configuration.h"
#include "../Configuration/Theme.h"

class RomListManager
{
private:
	std::vector<Rom> roms;
	std::vector<RomList> romListsArray;
	int currentRomSetIndex = 0;//begin at 1, but set to zero, because the first get method called will be getNEXTRomlist().

public:
	//Constructor
	RomListManager();

	//Getters
	RomList* getPreviousRomList();
	RomList* getNextRomList();
	int getCurrentRomSetIndex();
	int getRomSetNumber();
	//Member functions
	void loadTextures(const Configuration& configuration, const Theme& theme);
	void initText(const Theme& theme, const sf::Font&);

private:
	void loadCategories();
	void loadRoms();
	void sortRomsList();
	void updateCurrentRomSetIndex(char sign);
};


#endif //MAMEUISEN_ROMLISTMANAGER_H