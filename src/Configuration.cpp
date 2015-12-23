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

	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_X", &Configuration::setCategory_name_x));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_Y", &Configuration::setCategory_name_y));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_SIZE", &Configuration::setCategory_name_size));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_COLOR_RED", &Configuration::setCategory_name_color_red));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_COLOR_GREEN", &Configuration::setCategory_name_color_green));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_COLOR_BLUE", &Configuration::setCategory_name_color_blue));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_NAME_COLOR_ALPHA", &Configuration::setCategory_name_color_alpha));

	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_X", &Configuration::setCategory_index_x));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_Y", &Configuration::setCategory_index_y));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_SIZE", &Configuration::setCategory_index_size));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_COLOR_RED", &Configuration::setCategory_index_color_red));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_COLOR_GREEN", &Configuration::setCategory_index_color_green));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_COLOR_BLUE", &Configuration::setCategory_index_color_blue));
	directiveToFunction.push_back(ConfigDirectiveToFunction("CATEGORY_INDEX_COLOR_ALPHA", &Configuration::setCategory_index_color_alpha));

	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_SCREENSHOT_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_SCREENSHOT_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_SCREENSHOT_SIZE_FACTOR", &Configuration::));

	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_SIZE", &Configuration::));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_COLOR_RED", &Configuration::setRom_manufacturer_color_red));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_COLOR_GREEN", &Configuration::setRom_manufacturer_color_green));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_COLOR_BLUE", &Configuration::setRom_manufacturer_color_blue));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_MANUFACTURER_COLOR_ALPHA", &Configuration::setRom_manufacturer_color_alpha));

	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_SIZE", &Configuration::));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_COLOR_RED", &Configuration::setRom_year_color_red));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_COLOR_GREEN", &Configuration::setRom_year_color_green));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_COLOR_BLUE", &Configuration::setRom_year_color_blue));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_YEAR_COLOR_ALPHA", &Configuration::setRom_year_color_alpha));

	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_SIZE", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_MARGIN_SIZE", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_MAX_LENGTH", &Configuration::));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_COLOR_RED", &Configuration::setRom_name_color_red));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_COLOR_GREEN", &Configuration::setRom_name_color_green));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_COLOR_BLUE", &Configuration::setRom_name_color_blue));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_NAME_COLOR_ALPHA", &Configuration::setRom_name_color_alpha));

	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_INDEX_X", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_INDEX_Y", &Configuration::));
	//directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_INDEX_SIZE_FACTOR", &Configuration::));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_INDEX_COLOR_RED", &Configuration::setRom_index_color_red));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_INDEX_COLOR_GREEN", &Configuration::setRom_index_color_green));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_INDEX_COLOR_BLUE", &Configuration::setRom_index_color_blue));
	directiveToFunction.push_back(ConfigDirectiveToFunction("ROM_INDEX_COLOR_ALPHA", &Configuration::setRom_index_color_alpha));

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