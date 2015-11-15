//
// Created by joseph on 15/11/15.
//

#ifndef MAMEUISEN_ROMSET_H
#define MAMEUISEN_ROMSET_H

#include <string>
#include "Rom.h"

class RomSet
{
private:
	std::string name;
	std::vector<Rom*> romList;

public:
	//Constructor
	RomSet(const std::string& name) : name(name)
	{ }

	//Getters
	const std::string& getName() const
	{
		return name;
	}

	const std::vector<Rom*>& getRomList() const
	{
		return romList;
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


#endif //MAMEUISEN_ROMSET_H