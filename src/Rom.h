//
// Created by joseph on 15/11/15.
//

#ifndef MAMEUISEN_ROM_H
#define MAMEUISEN_ROM_H

#include <string>
#include <vector>

class Rom
{
private:
	std::string description;
	std::string filename;
	std::string manufacturer;
	int year;
	std::vector* categories<int> = nullptr;

public:
	//Constructor
	Rom(const std::string& description, const std::string& filename, const std::string& manufacturer, int year)
			: description(description), filename(filename), manufacturer(manufacturer), year(year)
	{
		categories = new std::vector<int>(0,0);
	}

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

	std::vector* getCategories() const
	{
		return categories;
	}

	//Member functions
	void addCategory(int categoryNumber)
	{
		categories->push_back(categoryNumber);
	}

	void freeCategories()
	{
		delete categories;
	}
};


#endif //MAMEUISEN_ROM_H