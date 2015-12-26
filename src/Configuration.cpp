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
	using cdtf = ConfigDirectiveToFunction<Configuration>;
	directiveToFunction.push_back(cdtf("MAME_PATH", &Configuration::setMame_path));
	directiveToFunction.push_back(cdtf("MAME_PATH", &Configuration::setMame_path));
	directiveToFunction.push_back(cdtf("ROMS_PATH", &Configuration::setRom_path));
	directiveToFunction.push_back(cdtf("SCREENSHOTS_PATH", &Configuration::setScreenshots_path));
	directiveToFunction.push_back(cdtf("WINDOW_WIDTH", &Configuration::setWindowWidth));
	directiveToFunction.push_back(cdtf("WINDOW_HEIGHT", &Configuration::setWindowHeight));
	directiveToFunction.push_back(cdtf("FULL_SCREEN", &Configuration::setFullscreen));
	directiveToFunction.push_back(cdtf("FONT_PATH", &Configuration::setFont_path));
	directiveToFunction.push_back(cdtf("FONT_SIZE_FACTOR", &Configuration::setFont_size_factor));

	directiveToFunction.push_back(cdtf("CATEGORY_NAME_X", &Configuration::setCategory_name_x));
	directiveToFunction.push_back(cdtf("CATEGORY_NAME_Y", &Configuration::setCategory_name_y));
	directiveToFunction.push_back(cdtf("CATEGORY_NAME_SIZE", &Configuration::setCategory_name_size));
	directiveToFunction.push_back(cdtf("CATEGORY_NAME_COLOR_RED", &Configuration::setCategory_name_color_red));
	directiveToFunction.push_back(cdtf("CATEGORY_NAME_COLOR_GREEN", &Configuration::setCategory_name_color_green));
	directiveToFunction.push_back(cdtf("CATEGORY_NAME_COLOR_BLUE", &Configuration::setCategory_name_color_blue));
	directiveToFunction.push_back(cdtf("CATEGORY_NAME_COLOR_ALPHA", &Configuration::setCategory_name_color_alpha));

	directiveToFunction.push_back(cdtf("CATEGORY_INDEX_X", &Configuration::setCategory_index_x));
	directiveToFunction.push_back(cdtf("CATEGORY_INDEX_Y", &Configuration::setCategory_index_y));
	directiveToFunction.push_back(cdtf("CATEGORY_INDEX_SIZE", &Configuration::setCategory_index_size));
	directiveToFunction.push_back(cdtf("CATEGORY_INDEX_COLOR_RED", &Configuration::setCategory_index_color_red));
	directiveToFunction.push_back(cdtf("CATEGORY_INDEX_COLOR_GREEN", &Configuration::setCategory_index_color_green));
	directiveToFunction.push_back(cdtf("CATEGORY_INDEX_COLOR_BLUE", &Configuration::setCategory_index_color_blue));
	directiveToFunction.push_back(cdtf("CATEGORY_INDEX_COLOR_ALPHA", &Configuration::setCategory_index_color_alpha));

	directiveToFunction.push_back(cdtf("ROM_SCREENSHOT_X", &Configuration::setRom_screenshot_x));
	directiveToFunction.push_back(cdtf("ROM_SCREENSHOT_Y", &Configuration::setRom_screenshot_y));
	directiveToFunction.push_back(cdtf("ROM_SCREENSHOT_SIZE_FACTOR", &Configuration::setRom_screenshot_size_factor));
	directiveToFunction.push_back(cdtf("ROM_SCREENSHOT_SMOOTH_ZOOM", &Configuration::setRom_screenshot_smooth_zoom));

	directiveToFunction.push_back(cdtf("ROM_MANUFACTURER_X", &Configuration::setRom_manufacturer_x));
	directiveToFunction.push_back(cdtf("ROM_MANUFACTURER_Y", &Configuration::setRom_manufacturer_y));
	directiveToFunction.push_back(cdtf("ROM_MANUFACTURER_SIZE", &Configuration::setRom_manufacturer_size));
	directiveToFunction.push_back(cdtf("ROM_MANUFACTURER_COLOR_RED", &Configuration::setRom_manufacturer_color_red));
	directiveToFunction.push_back(cdtf("ROM_MANUFACTURER_COLOR_GREEN", &Configuration::setRom_manufacturer_color_green));
	directiveToFunction.push_back(cdtf("ROM_MANUFACTURER_COLOR_BLUE", &Configuration::setRom_manufacturer_color_blue));
	directiveToFunction.push_back(cdtf("ROM_MANUFACTURER_COLOR_ALPHA", &Configuration::setRom_manufacturer_color_alpha));

	directiveToFunction.push_back(cdtf("ROM_YEAR_X", &Configuration::setRom_year_x));
	directiveToFunction.push_back(cdtf("ROM_YEAR_Y", &Configuration::setRom_year_y));
	directiveToFunction.push_back(cdtf("ROM_YEAR_SIZE", &Configuration::setRom_year_size));
	directiveToFunction.push_back(cdtf("ROM_YEAR_COLOR_RED", &Configuration::setRom_year_color_red));
	directiveToFunction.push_back(cdtf("ROM_YEAR_COLOR_GREEN", &Configuration::setRom_year_color_green));
	directiveToFunction.push_back(cdtf("ROM_YEAR_COLOR_BLUE", &Configuration::setRom_year_color_blue));
	directiveToFunction.push_back(cdtf("ROM_YEAR_COLOR_ALPHA", &Configuration::setRom_year_color_alpha));

	directiveToFunction.push_back(cdtf("ROM_NAME_SELECTED_X", &Configuration::setRom_name_selected_x));
	directiveToFunction.push_back(cdtf("ROM_NAME_SELECTED_Y", &Configuration::setRom_name_selected_y));
	directiveToFunction.push_back(cdtf("ROM_NAME_TO_DISPLAY_ABOVE_SELECTED", &Configuration::setRom_name_to_display_above_selected));
	directiveToFunction.push_back(cdtf("ROM_NAME_TO_DISPLAY_UNDER_SELECTED", &Configuration::setRom_name_to_display_under_selected));
	directiveToFunction.push_back(cdtf("ROM_NAME_SIZE", &Configuration::setRom_name_size));
	directiveToFunction.push_back(cdtf("ROM_NAME_MARGIN_SIZE", &Configuration::setRom_name_margin_size));
	directiveToFunction.push_back(cdtf("ROM_NAME_MAX_LENGTH", &Configuration::setRom_name_max_length));
	directiveToFunction.push_back(cdtf("ROM_NAME_SUFFIX_MAX_LENGTH", &Configuration::setRom_name_suffix_max_length));
	directiveToFunction.push_back(cdtf("ROM_NAME_COLOR_RED", &Configuration::setRom_name_color_red));
	directiveToFunction.push_back(cdtf("ROM_NAME_COLOR_GREEN", &Configuration::setRom_name_color_green));
	directiveToFunction.push_back(cdtf("ROM_NAME_COLOR_BLUE", &Configuration::setRom_name_color_blue));
	directiveToFunction.push_back(cdtf("ROM_NAME_COLOR_ALPHA", &Configuration::setRom_name_color_alpha));

	directiveToFunction.push_back(cdtf("ROM_INDEX_X", &Configuration::setRom_index_x));
	directiveToFunction.push_back(cdtf("ROM_INDEX_Y", &Configuration::setRom_index_y));
	directiveToFunction.push_back(cdtf("ROM_INDEX_SIZE", &Configuration::setRom_index_size));
	directiveToFunction.push_back(cdtf("ROM_INDEX_COLOR_RED", &Configuration::setRom_index_color_red));
	directiveToFunction.push_back(cdtf("ROM_INDEX_COLOR_GREEN", &Configuration::setRom_index_color_green));
	directiveToFunction.push_back(cdtf("ROM_INDEX_COLOR_BLUE", &Configuration::setRom_index_color_blue));
	directiveToFunction.push_back(cdtf("ROM_INDEX_COLOR_ALPHA", &Configuration::setRom_index_color_alpha));

	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_VERTICAL_MARGIN", &Configuration::setRom_selection_indicator_vertical_margin));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_HORIZONTAL_MARGIN", &Configuration::setRom_selection_indicator_horizontal_margin));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BACKGROUND_RED", &Configuration::setRom_selection_indicator_background_red));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BACKGROUND_GREEN", &Configuration::setRom_selection_indicator_background_green));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BACKGROUND_BLUE", &Configuration::setRom_selection_indicator_background_blue));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BACKGROUND_ALPHA", &Configuration::setRom_selection_indicator_background_alpha));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BORDER_SIZE", &Configuration::setRom_selection_indicator_border_size));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BORDER_RED", &Configuration::setRom_selection_indicator_border_red));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BORDER_GREEN", &Configuration::setRom_selection_indicator_border_green));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BORDER_BLUE", &Configuration::setRom_selection_indicator_border_blue));
	directiveToFunction.push_back(cdtf("ROM_SELECTION_INDICATOR_BORDER_ALPHA", &Configuration::setRom_selection_indicator_border_alpha));
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
		int numLine = 0;
		while(getline(confFile, line))
		{
			numLine++;
			if(line[0] != '#')
			{
				for(auto & dtf : directiveToFunction)
				{
					size_t pos = line.find(dtf.getDirective());
					if(pos != string::npos)
					{
						try
						{
							dtf.callSetter(this, line.substr(pos + dtf.getDirective().length() + 1));
						}
						catch(...)
						{
							cerr << "Incorrect value for directive " << dtf.getDirective() << " line " << numLine << ". Default value will be used." << endl;
						}
						break;
					}
				}
			}
		}
	}
}