//
// Created by joseph on 30/12/15.
//

#include "Theme.h"
#include <iostream>

using namespace std;

Theme::Theme(const std::string& themeFilePath) : AbstractConfiguration(themeFilePath)
{
	if(themeFilePath != "")
	{
		bindDirectivesToSetters();
		loadConfiguration();
	}
	else
	{
		cerr << "Uncepecified theme file. Will use default values." << endl;
	}
}

void Theme::bindDirectivesToSetters()
{
	bind("WINDOW_WIDTH", &Theme::setWindowWidth);
	bind("WINDOW_HEIGHT", &Theme::setWindowHeight);

	bind("FONT_PATH", &Theme::setFont_path);
	bind("FONT_SIZE_FACTOR", &Theme::setFont_size_factor);

	bind("BACKGROUND_RED", &Theme::setBackground_red);
	bind("BACKGROUND_GREEN", &Theme::setBackground_green);
	bind("BACKGROUND_BLUE", &Theme::setBackground_blue);
	bind("BACKGROUND_IMAGE_PATH", &Theme::setBackground_image_path);
	bind("BACKGROUND_IMAGE_ALPHA", &Theme::setBackground_image_alpha);
	bind("BACKGROUND_IMAGE_SIZE_FACTOR", &Theme::setBackground_image_size_factor);
	bind("BACKGROUND_IMAGE_X_OFFSET", &Theme::setBackground_image_x_offset);
	bind("BACKGROUND_IMAGE_Y_OFFSET", &Theme::setBackground_image_y_offset);
	bind("BACKGROUND_IMAGE_SMOOTH_ZOOM", &Theme::setBackground_image_smooth_zoom);

	bind("CATEGORY_NAME_X", &Theme::setCategory_name_x);
	bind("CATEGORY_NAME_Y", &Theme::setCategory_name_y);
	bind("CATEGORY_NAME_SIZE", &Theme::setCategory_name_size);
	bind("CATEGORY_NAME_COLOR_RED", &Theme::setCategory_name_color_red);
	bind("CATEGORY_NAME_COLOR_GREEN", &Theme::setCategory_name_color_green);
	bind("CATEGORY_NAME_COLOR_BLUE", &Theme::setCategory_name_color_blue);
	bind("CATEGORY_NAME_COLOR_ALPHA", &Theme::setCategory_name_color_alpha);

	bind("CATEGORY_INDEX_X", &Theme::setCategory_index_x);
	bind("CATEGORY_INDEX_Y", &Theme::setCategory_index_y);
	bind("CATEGORY_INDEX_SIZE", &Theme::setCategory_index_size);
	bind("CATEGORY_INDEX_COLOR_RED", &Theme::setCategory_index_color_red);
	bind("CATEGORY_INDEX_COLOR_GREEN", &Theme::setCategory_index_color_green);
	bind("CATEGORY_INDEX_COLOR_BLUE", &Theme::setCategory_index_color_blue);
	bind("CATEGORY_INDEX_COLOR_ALPHA", &Theme::setCategory_index_color_alpha);

	bind("ROM_SCREENSHOT_X", &Theme::setRom_screenshot_x);
	bind("ROM_SCREENSHOT_Y", &Theme::setRom_screenshot_y);
	bind("ROM_SCREENSHOT_SIZE_FACTOR", &Theme::setRom_screenshot_size_factor);
	bind("ROM_SCREENSHOT_SMOOTH_ZOOM", &Theme::setRom_screenshot_smooth_zoom);

	bind("ROM_MANUFACTURER_X", &Theme::setRom_manufacturer_x);
	bind("ROM_MANUFACTURER_Y", &Theme::setRom_manufacturer_y);
	bind("ROM_MANUFACTURER_SIZE", &Theme::setRom_manufacturer_size);
	bind("ROM_MANUFACTURER_COLOR_RED", &Theme::setRom_manufacturer_color_red);
	bind("ROM_MANUFACTURER_COLOR_GREEN", &Theme::setRom_manufacturer_color_green);
	bind("ROM_MANUFACTURER_COLOR_BLUE", &Theme::setRom_manufacturer_color_blue);
	bind("ROM_MANUFACTURER_COLOR_ALPHA", &Theme::setRom_manufacturer_color_alpha);

	bind("ROM_YEAR_X", &Theme::setRom_year_x);
	bind("ROM_YEAR_Y", &Theme::setRom_year_y);
	bind("ROM_YEAR_SIZE", &Theme::setRom_year_size);
	bind("ROM_YEAR_COLOR_RED", &Theme::setRom_year_color_red);
	bind("ROM_YEAR_COLOR_GREEN", &Theme::setRom_year_color_green);
	bind("ROM_YEAR_COLOR_BLUE", &Theme::setRom_year_color_blue);
	bind("ROM_YEAR_COLOR_ALPHA", &Theme::setRom_year_color_alpha);

	bind("ROM_NAME_SELECTED_X", &Theme::setRom_name_selected_x);
	bind("ROM_NAME_SELECTED_Y", &Theme::setRom_name_selected_y);
	bind("ROM_NAME_TO_DISPLAY_ABOVE_SELECTED", &Theme::setRom_name_to_display_above_selected);
	bind("ROM_NAME_TO_DISPLAY_UNDER_SELECTED", &Theme::setRom_name_to_display_under_selected);
	bind("ROM_NAME_SIZE", &Theme::setRom_name_size);
	bind("ROM_NAME_MARGIN_SIZE", &Theme::setRom_name_margin_size);
	bind("ROM_NAME_MAX_LENGTH", &Theme::setRom_name_max_length);
	bind("ROM_NAME_SUFFIX_MAX_LENGTH", &Theme::setRom_name_suffix_max_length);
	bind("ROM_NAME_COLOR_RED", &Theme::setRom_name_color_red);
	bind("ROM_NAME_COLOR_GREEN", &Theme::setRom_name_color_green);
	bind("ROM_NAME_COLOR_BLUE", &Theme::setRom_name_color_blue);
	bind("ROM_NAME_COLOR_ALPHA", &Theme::setRom_name_color_alpha);

	bind("ROM_INDEX_X", &Theme::setRom_index_x);
	bind("ROM_INDEX_Y", &Theme::setRom_index_y);
	bind("ROM_INDEX_SIZE", &Theme::setRom_index_size);
	bind("ROM_INDEX_COLOR_RED", &Theme::setRom_index_color_red);
	bind("ROM_INDEX_COLOR_GREEN", &Theme::setRom_index_color_green);
	bind("ROM_INDEX_COLOR_BLUE", &Theme::setRom_index_color_blue);
	bind("ROM_INDEX_COLOR_ALPHA", &Theme::setRom_index_color_alpha);

	bind("ROM_SELECTION_INDICATOR_VERTICAL_MARGIN", &Theme::setRom_selection_indicator_vertical_margin);
	bind("ROM_SELECTION_INDICATOR_HORIZONTAL_MARGIN", &Theme::setRom_selection_indicator_horizontal_margin);
	bind("ROM_SELECTION_INDICATOR_WIDTH", &Theme::setRom_selection_indicator_width);
	bind("ROM_SELECTION_INDICATOR_BACKGROUND_RED", &Theme::setRom_selection_indicator_background_red);
	bind("ROM_SELECTION_INDICATOR_BACKGROUND_GREEN", &Theme::setRom_selection_indicator_background_green);
	bind("ROM_SELECTION_INDICATOR_BACKGROUND_BLUE", &Theme::setRom_selection_indicator_background_blue);
	bind("ROM_SELECTION_INDICATOR_BACKGROUND_ALPHA", &Theme::setRom_selection_indicator_background_alpha);
	bind("ROM_SELECTION_INDICATOR_BORDER_SIZE", &Theme::setRom_selection_indicator_border_size);
	bind("ROM_SELECTION_INDICATOR_BORDER_RED", &Theme::setRom_selection_indicator_border_red);
	bind("ROM_SELECTION_INDICATOR_BORDER_GREEN", &Theme::setRom_selection_indicator_border_green);
	bind("ROM_SELECTION_INDICATOR_BORDER_BLUE", &Theme::setRom_selection_indicator_border_blue);
	bind("ROM_SELECTION_INDICATOR_BORDER_ALPHA", &Theme::setRom_selection_indicator_border_alpha);
}