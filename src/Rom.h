//
// Created by joseph on 15/11/15.
//

#ifndef MAMEUISEN_ROM_H
#define MAMEUISEN_ROM_H

#include <string>

class Rom
{
private:
	std::string description;
	std::string filename;
	std::string manufacturer;
	int year;

public:
	//Constructor
	Rom(const std::string& description, const std::string& filename, const std::string& manufacturer, int year)
			: description(description), filename(filename), manufacturer(manufacturer), year(year)
	{}

	//Getters
	const std::string& getDescription() const
	{
		return description;
	}

	const std::string& getFilename() const
	{
		return filename;
	}

	const std::string& getManufacturer() const
	{
		return manufacturer;
	}

	int getYear() const
	{
		return year;
	}
};


#endif //MAMEUISEN_ROM_H