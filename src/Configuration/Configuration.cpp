//
// Created by joseph on 20/12/15.
//

#include "Configuration.h"

using namespace std;


Configuration::Configuration(const std::string& configFilePath) : AbstactConfiguration(configFilePath)
{
	if(configFilePath != "")
	{
		bindDirectivesToSetters();
		loadConfiguration(this);
	}
	else
	{
		cerr << "Uncepecified configuration file. Will use default values." << endl;
	}
}

void Configuration::bindDirectivesToSetters()
{
	using cdtf = ConfigDirectiveToFunction<Configuration>;

	directiveToFunction.push_back(cdtf("MAME_PATH", &Configuration::setMame_path));
	directiveToFunction.push_back(cdtf("MAME_PATH", &Configuration::setMame_path));
	directiveToFunction.push_back(cdtf("ROMS_PATH", &Configuration::setRom_path));
	directiveToFunction.push_back(cdtf("SCREENSHOTS_PATH", &Configuration::setScreenshots_path));
	directiveToFunction.push_back(cdtf("FULL_SCREEN", &Configuration::setFullscreen));
	directiveToFunction.push_back(cdtf("THEME_PATH", &Configuration::setTheme_path));
}