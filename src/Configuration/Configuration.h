//
// Created by joseph on 20/12/15.
//

#ifndef MAMEUISEN_CONFIGURATION_H
#define MAMEUISEN_CONFIGURATION_H

#include <string>
#include <iostream>
#include "../lib/EasyConfigurationFileReadingApi/AbstractConfiguration.h"

class Configuration : AbstractConfiguration<Configuration>
{
private:
	std::string mame_path = "mame";
	std::string rom_path = "../roms";
	std::string screenshots_path = "../screenshots";
	std::string theme_path = "../themes/default/default.theme";
	bool fullscreen = false;

public:
	Configuration(const std::string& configFilePath);

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

	const std::string& getTheme_path() const
	{
		return theme_path;
	}

	void setTheme_path(const std::string& theme_path)
	{
		Configuration::theme_path = theme_path;
	}

	const std::string& getScreenshots_path() const
	{
		return screenshots_path;
	}

	void setScreenshots_path(const std::string& screenshots_path)
	{
		Configuration::screenshots_path = screenshots_path;
	}

	bool isFullscreen() const
	{
		return fullscreen;
	}

	void setFullscreen(bool fullscreen)
	{
		Configuration::fullscreen = fullscreen;
	}

private:
	virtual void bindDirectivesToSetters();
};


#endif //MAMEUISEN_CONFIGURATION_H