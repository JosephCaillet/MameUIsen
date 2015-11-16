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
	std::vector<RomList> romSets;
	int currentRomSet;

public:

};


#endif //MAMEUISEN_ROMLISTMANAGER_H
