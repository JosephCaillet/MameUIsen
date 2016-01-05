//
// Created by joseph on 20/12/15.
//

#include "Configuration.h"

using namespace std;


Configuration::Configuration(const std::string& configFilePath) : AbstractConfiguration(configFilePath)
{
	if(configFilePath != "")
	{
		bindDirectivesToSetters();
		loadConfiguration();
	}
	else
	{
		cerr << "Uncepecified configuration file. Will use default values." << endl;
	}
}

void Configuration::bindDirectivesToSetters()
{
	bind("MAME_PATH", &Configuration::setMame_path);
	bind("MAME_PATH", &Configuration::setMame_path);
	bind("ROMS_PATH", &Configuration::setRom_path);
	bind("SCREENSHOTS_PATH", &Configuration::setScreenshots_path);
	bind("FULL_SCREEN", &Configuration::setFullscreen);
	bind("ALL_ROMS_CATEGORY_NAME", &Configuration::setAll_roms_category_name);
	bind("THEME_PATH", &Configuration::setTheme_path);
}