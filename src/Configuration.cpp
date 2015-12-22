//
// Created by joseph on 20/12/15.
//

#include <fstream>
#include <iostream>
#include <string.h>

#include "Configuration.h"

using namespace std;

Configuration::Configuration()
{
	directiveToFunction.push_back(ConfigDirectiveToFunction("MAME_PATH", &Configuration::setMame_path));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROMS_PATH", &Configuration::setRom_path));
	directiveToFunction.push_back(ConfigDirectiveToFunction("SCREENSHOTS_PATH", &Configuration::setScreenshots_path));
	directiveToFunction.push_back(ConfigDirectiveToFunction("WINDOW_WIDTH", &Configuration::setWindowWidth));
	directiveToFunction.push_back(ConfigDirectiveToFunction("WINDOW_HEIGHT", &Configuration::setWindowHeight));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_SIZE", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_SIZE", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_SCREENSHOT_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_SCREENSHOT_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_SCREENSHOT_SIZE_FACTOR", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_SIZE", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_SIZE", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_SIZE", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_MAX_LENGTH", &Configuration::));
	loadConf();
}

void Configuration::loadConf()
{
	ifstream confFile("../config/general.cfg", ios::in);
	if(!confFile)
	{
		cerr << "Can't open config/general.cfg : " << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		string line;

		while(getline(confFile, line))
		{
			if(line[0] != '#')
			{
				for(auto & dtf : directiveToFunction)
				{
					size_t pos = line.find(dtf.getDirective());
					if(pos != string::npos)
					{
						(this->*dtf.getSetter()) (line.substr(pos + dtf.getDirective().length() + 1));
					}
				}
			}
		}
	}
}