//
// Created by joseph on 20/12/15.
//

#ifndef MAMEUISEN_CONFIGURATION_H
#define MAMEUISEN_CONFIGURATION_H

#include <string>
#include <iostream>
#include "../lib/EasyConfigurationFileReadingApi/AbstractConfiguration.h"

class Configuration : ecfra::AbstractConfiguration<Configuration>
{
private:
	std::string mame_path = "mame";
	std::string rom_path = "../roms";
	std::string screenshots_path = "../screenshots";
	std::string theme_path = "../themes/default/default.theme";
	std::string all_roms_category_name = "All";
	std::string categories_config_path = "../config/categories.cfg";
	std::string games_config_path = "../config/games.cfg";
	bool fullscreen = false;
	int fps_rate = 20;

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

	const std::string& getAll_roms_category_name() const
	{
		return all_roms_category_name;
	}

	void setAll_roms_category_name(const std::string& all_roms_category_name)
	{
		Configuration::all_roms_category_name = all_roms_category_name;
	}

	const std::string& getScreenshots_path() const
	{
		return screenshots_path;
	}

	void setScreenshots_path(const std::string& screenshots_path)
	{
		Configuration::screenshots_path = screenshots_path;
	}

	const std::string& getCategories_config_path() const
	{
		return categories_config_path;
	}

	void setCategories_config_path(const std::string& categories_config_path)
	{
		Configuration::categories_config_path = categories_config_path;
	}

	const std::string& getGames_config_path() const
	{
		return games_config_path;
	}

	void setGames_config_path(const std::string& games_config_path)
	{
		Configuration::games_config_path = games_config_path;
	}

	bool isFullscreen() const
	{
		return fullscreen;
	}

	void setFullscreen(bool fullscreen)
	{
		Configuration::fullscreen = fullscreen;
	}

	int getFps_rate() const
	{
		return fps_rate;
	}

	void setFps_rate(int fps_rate)
	{
		Configuration::fps_rate = fps_rate;
	}

private:
	virtual void bindDirectivesToSetters();
};


#endif //MAMEUISEN_CONFIGURATION_H