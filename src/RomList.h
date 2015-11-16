//
// Created by joseph on 15/11/15.
//

#ifndef MAMEUISEN_ROMLIST_H
#define MAMEUISEN_ROMLIST_H

#include <string>
#include <vector>
#include "Rom.h"

class RomList
{
private:
	std::string name;
	std::vector<Rom*> romList;

public:
	//Constructor
	RomList(const std::string& name="") : name(name)
	{}

	//Getters
	const std::string& getName() const
	{
		return name;
	}

	const Rom* getRom(int romNumber) const
	{
		return romList[romNumber];
	}

	const unsigned long getRomListSize() const
	{
		return romList.size();
	}

	//Member functions
	bool isEmpty()
	{
		return romList.empty();
	}

	void addRom(Rom* rom)
	{
		romList.push_back(rom);
	}
};


#endif //MAMEUISEN_ROMLIST_H