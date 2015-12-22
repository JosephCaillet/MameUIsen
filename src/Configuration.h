//
// Created by joseph on 20/12/15.
//

#ifndef MAMEUISEN_CONFIGURATION_H
#define MAMEUISEN_CONFIGURATION_H

#include <string>
#include <vector>
#include "ConfigDirectiveToFunction.h"

class Configuration
{
private:
	std::string mame_path = "mame";
	std::string rom_path = "../roms";
	std::string screenshots_path = "../screenshots";
	int windowWidth = 800;
	int windowHeight = 600;
	std::vector<ConfigDirectiveToFunction> directiveToFunction;

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

	int getWindowWidth() const
	{
		return windowWidth;
	}

	void setWindowWidth(const std::string& windowWidth)
	{
		Configuration::windowWidth = std::stoi(windowWidth);
	}

	int getWindowHeight() const
	{
		return windowHeight;
	}

	void setWindowHeight(const std::string& windowHeight)
	{
		Configuration::windowHeight = std::stoi(windowHeight);
	}
};


#endif //MAMEUISEN_CONFIGURATION_H