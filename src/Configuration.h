//
// Created by joseph on 20/12/15.
//

#ifndef MAMEUISEN_CONFIGURATION_H
#define MAMEUISEN_CONFIGURATION_H

#include <string>
#include "ConfigDirectiveToFunction.h"

#define DIRECTIVE_NUMBER 3

class Configuration
{
private:
	std::string mame_path;
	std::string rom_path;
	std::string screenshots_path;
	ConfigDirectiveToFunction directiveToFunction[DIRECTIVE_NUMBER];

private:
	void loadConf();

public:
	Configuration();

	const std::string& getMame_path() const
	{
		return mame_path;
	}

	void setMame_path(const std::string& mame_path)
	{
		Configuration::mame_path = mame_path;
	}

	const std::string& getRom_path() const
	{
		return rom_path;
	}

	void setRom_path(const std::string& rom_path)
	{
		Configuration::rom_path = rom_path;
	}

	const std::string& getScreenshots_path() const
	{
		return screenshots_path;
	}

	void setScreenshots_path(const std::string& screenshots_path)
	{
		Configuration::screenshots_path = screenshots_path;
	}
};


#endif //MAMEUISEN_CONFIGURATION_H
