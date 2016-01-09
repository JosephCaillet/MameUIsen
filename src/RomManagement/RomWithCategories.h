//
// Created by joseph on 07/01/16.
//

#ifndef MAMEUISEN_ROMWITHCATEGORIES_H
#define MAMEUISEN_ROMWITHCATEGORIES_H

#include <sstream>
#include "Rom.h"

class RomWithCategories : public Rom
{
private:
	std::vector<int> categoryNumbers;

public:
	RomWithCategories(const std::string& description, const std::string& filename, const std::string& manufacturer, const std::string year)
			: Rom(description, filename, manufacturer, year)
	{ }

	RomWithCategories(const std::string& filename="") : Rom("", filename, "", "")
	{ }

	void addCategoryNumber(const int num)
	{
		categoryNumbers.push_back(num);
	}

	std::string getCategoryNubers() const
	{
		std::stringstream s;
		for(unsigned int i = 0; i < categoryNumbers.size(); i++)
		{
			s << categoryNumbers[i];
			if(i+1 != categoryNumbers.size())
			{
				s << ";";
			}
		}

		return s.str();
	}

	//Operators
	friend bool operator<(const RomWithCategories& r1, const RomWithCategories& r2)
	{
		return r1.filename < r2.filename;
	}

	friend bool operator==(const RomWithCategories& r1, const RomWithCategories& r2)
	{
		return r1.filename == r2.filename;
	}
};


#endif //MAMEUISEN_ROMWITHCATEGORIES_H