//
// Created by joseph on 30/12/15.
//

#ifndef MAMEUISEN_THEME_H
#define MAMEUISEN_THEME_H

#include <string>
#include "../lib/EasyConfigurationFileReadingApi/AbstractConfiguration.h"

class Theme : ecfra::AbstractConfiguration<Theme>
{
	int windowWidth = 800;
	int windowHeight = 600;

	std::string font_path = "../themes/default/ARCADE_R.TTF";
	float font_size_factor = 1.0f;

	int background_red = 0;
	int background_green = 0;
	int background_blue = 0;
	std::string background_image_path = "";
	int background_image_alpha = 255;
	float background_image_size_factor = 255;
	int background_image_x_offset = 0;
	int background_image_y_offset = 0;
	bool background_image_smooth_zoom = true;

	int category_name_x;
	int category_name_y;
	int category_name_size;
	int category_name_color_red = 255;
	int category_name_color_green  =255;
	int category_name_color_blue  = 255;
	int category_name_color_alpha = 255;

	int category_index_x;
	int category_index_y;
	int category_index_size;
	int category_index_color_red = 255;
	int category_index_color_green  =255;
	int category_index_color_blue  = 255;
	int category_index_color_alpha = 255;

	int rom_screenshot_x;
	int rom_screenshot_y;
	float rom_screenshot_size_factor;
	bool rom_screenshot_smooth_zoom = false;

	int rom_manufacturer_x;
	int rom_manufacturer_y;
	int rom_manufacturer_size;
	int rom_manufacturer_color_red = 255;
	int rom_manufacturer_color_green  =255;
	int rom_manufacturer_color_blue  = 255;
	int rom_manufacturer_color_alpha = 255;

	int rom_year_x;
	int rom_year_y;
	int rom_year_size;
	int rom_year_color_red = 255;
	int rom_year_color_green  =255;
	int rom_year_color_blue  = 255;
	int rom_year_color_alpha = 255;

	int rom_name_selected_x;
	int rom_name_selected_y;
	int rom_name_to_display_above_selected;
	int rom_name_to_display_under_selected;
	int rom_name_size;
	int rom_name_margin_size;
	int rom_name_max_length;
	std::string rom_name_suffix_max_length;
	int rom_name_color_red = 255;
	int rom_name_color_green  =255;
	int rom_name_color_blue  = 255;
	int rom_name_color_alpha = 255;

	int rom_index_x;
	int rom_index_y;
	int rom_index_size;
	int rom_index_color_red = 255;
	int rom_index_color_green  =255;
	int rom_index_color_blue  = 255;
	int rom_index_color_alpha = 255;

	int rom_selection_indicator_vertical_margin;
	int rom_selection_indicator_horizontal_margin;
	int rom_selection_indicator_width = -1;
	int rom_selection_indicator_background_red;
	int rom_selection_indicator_background_green;
	int rom_selection_indicator_background_blue;
	int rom_selection_indicator_background_alpha;
	float rom_selection_indicator_border_size;
	int rom_selection_indicator_border_red;
	int rom_selection_indicator_border_green;
	int rom_selection_indicator_border_blue;
	int rom_selection_indicator_border_alpha;

public:
	Theme(const std::string& themeFilePath);

	int getWindowWidth() const
	{
		return windowWidth;
	}

	void setWindowWidth(int windowWidth)
	{
		Theme::windowWidth = windowWidth;
	}

	int getWindowHeight() const
	{
		return windowHeight;
	}

	void setWindowHeight(int windowHeight)
	{
		Theme::windowHeight = windowHeight;
	}

	const std::string& getFont_path() const
	{
		return font_path;
	}

	void setFont_path(const std::string& font_path)
	{
		Theme::font_path = font_path;
	}

	float getFont_size_factor() const
	{
		return font_size_factor;
	}

	void setFont_size_factor(float font_size_factor)
	{
		Theme::font_size_factor = font_size_factor;
	}

	int getBackground_red() const
	{
		return background_red;
	}

	void setBackground_red(int background_red)
	{
		Theme::background_red = background_red;
	}

	int getBackground_green() const
	{
		return background_green;
	}

	void setBackground_green(int background_green)
	{
		Theme::background_green = background_green;
	}

	int getBackground_blue() const
	{
		return background_blue;
	}

	void setBackground_blue(int background_blue)
	{
		Theme::background_blue = background_blue;
	}

	const std::string& getBackground_image_path() const
	{
		return background_image_path;
	}

	void setBackground_image_path(const std::string& background_image_path)
	{
		Theme::background_image_path = background_image_path;
	}

	int getBackground_image_alpha() const
	{
		return background_image_alpha;
	}

	void setBackground_image_alpha(int background_image_alpha)
	{
		Theme::background_image_alpha = background_image_alpha;
	}

	float getBackground_image_size_factor() const
	{
		return background_image_size_factor;
	}

	void setBackground_image_size_factor(float background_image_size_factor)
	{
		Theme::background_image_size_factor = background_image_size_factor;
	}

	int getBackground_image_x_offset() const
	{
		return background_image_x_offset;
	}

	void setBackground_image_x_offset(int background_image_x_offset)
	{
		Theme::background_image_x_offset = background_image_x_offset;
	}

	int getBackground_image_y_offset() const
	{
		return background_image_y_offset;
	}

	void setBackground_image_y_offset(int background_image_y_offset)
	{
		Theme::background_image_y_offset = background_image_y_offset;
	}

	bool isBackground_image_smooth_zoom() const
	{
		return background_image_smooth_zoom;
	}

	void setBackground_image_smooth_zoom(bool background_image_smooth_zoom)
	{
		Theme::background_image_smooth_zoom = background_image_smooth_zoom;
	}

	int getCategory_name_x() const
	{
		return category_name_x;
	}

	void setCategory_name_x(int category_name_x)
	{
		Theme::category_name_x = category_name_x;
	}

	int getCategory_name_y() const
	{
		return category_name_y;
	}

	void setCategory_name_y(int category_name_y)
	{
		Theme::category_name_y = category_name_y;
	}

	int getCategory_name_size() const
	{
		return category_name_size;
	}

	void setCategory_name_size(int category_name_size)
	{
		Theme::category_name_size = getFont_size_factor() * category_name_size;
	}

	int getCategory_name_color_red() const
	{
		return category_name_color_red;
	}

	void setCategory_name_color_red(int category_name_color_red)
	{
		Theme::category_name_color_red = category_name_color_red;
	}

	int getCategory_name_color_green() const
	{
		return category_name_color_green;
	}

	void setCategory_name_color_green(int category_name_color_green)
	{
		Theme::category_name_color_green = category_name_color_green;
	}

	int getCategory_name_color_blue() const
	{
		return category_name_color_blue;
	}

	void setCategory_name_color_blue(int category_name_color_blue)
	{
		Theme::category_name_color_blue = category_name_color_blue;
	}

	int getCategory_name_color_alpha() const
	{
		return category_name_color_alpha;
	}

	void setCategory_name_color_alpha(int category_name_color_alpha)
	{
		Theme::category_name_color_alpha = category_name_color_alpha;
	}

	int getCategory_index_x() const
	{
		return category_index_x;
	}

	void setCategory_index_x(int category_index_x)
	{
		Theme::category_index_x = category_index_x;
	}

	int getCategory_index_y() const
	{
		return category_index_y;
	}

	void setCategory_index_y(int category_index_y)
	{
		Theme::category_index_y = category_index_y;
	}

	int getCategory_index_size() const
	{
		return category_index_size;
	}

	void setCategory_index_size(int category_index_size)
	{
		Theme::category_index_size = getFont_size_factor() * category_index_size;
	}

	int getCategory_index_color_red() const
	{
		return category_index_color_red;
	}

	void setCategory_index_color_red(int category_index_color_red)
	{
		Theme::category_index_color_red = category_index_color_red;
	}

	int getCategory_index_color_green() const
	{
		return category_index_color_green;
	}

	void setCategory_index_color_green(int category_index_color_green)
	{
		Theme::category_index_color_green = category_index_color_green;
	}

	int getCategory_index_color_blue() const
	{
		return category_index_color_blue;
	}

	void setCategory_index_color_blue(int category_index_color_blue)
	{
		Theme::category_index_color_blue = category_index_color_blue;
	}

	int getCategory_index_color_alpha() const
	{
		return category_index_color_alpha;
	}

	void setCategory_index_color_alpha(int category_index_color_alpha)
	{
		Theme::category_index_color_alpha = category_index_color_alpha;
	}

	int getRom_screenshot_x() const
	{
		return rom_screenshot_x;
	}

	void setRom_screenshot_x(int rom_screenshot_x)
	{
		Theme::rom_screenshot_x = rom_screenshot_x;
	}

	int getRom_screenshot_y() const
	{
		return rom_screenshot_y;
	}

	void setRom_screenshot_y(int rom_screenshot_y)
	{
		Theme::rom_screenshot_y = rom_screenshot_y;
	}

	float getRom_screenshot_size_factor() const
	{
		return rom_screenshot_size_factor;
	}

	void setRom_screenshot_size_factor(float rom_screenshot_size_factor)
	{
		Theme::rom_screenshot_size_factor = rom_screenshot_size_factor;
	}

	bool isRom_screenshot_smooth_zoom() const
	{
		return rom_screenshot_smooth_zoom;
	}

	void setRom_screenshot_smooth_zoom(bool rom_screenshot_smooth_zoom)
	{
		Theme::rom_screenshot_smooth_zoom = rom_screenshot_smooth_zoom;
	}

	int getRom_manufacturer_x() const
	{
		return rom_manufacturer_x;
	}

	void setRom_manufacturer_x(int rom_manufacturer_x)
	{
		Theme::rom_manufacturer_x = rom_manufacturer_x;
	}

	int getRom_manufacturer_y() const
	{
		return rom_manufacturer_y;
	}

	void setRom_manufacturer_y(int rom_manufacturer_y)
	{
		Theme::rom_manufacturer_y = rom_manufacturer_y;
	}

	int getRom_manufacturer_size() const
	{
		return rom_manufacturer_size;
	}

	void setRom_manufacturer_size(int rom_manufacturer_size)
	{
		Theme::rom_manufacturer_size = getFont_size_factor() * rom_manufacturer_size;
	}

	int getRom_manufacturer_color_red() const
	{
		return rom_manufacturer_color_red;
	}

	void setRom_manufacturer_color_red(int rom_manufacturer_color_red)
	{
		Theme::rom_manufacturer_color_red = rom_manufacturer_color_red;
	}

	int getRom_manufacturer_color_green() const
	{
		return rom_manufacturer_color_green;
	}

	void setRom_manufacturer_color_green(int rom_manufacturer_color_green)
	{
		Theme::rom_manufacturer_color_green = rom_manufacturer_color_green;
	}

	int getRom_manufacturer_color_blue() const
	{
		return rom_manufacturer_color_blue;
	}

	void setRom_manufacturer_color_blue(int rom_manufacturer_color_blue)
	{
		Theme::rom_manufacturer_color_blue = rom_manufacturer_color_blue;
	}

	int getRom_manufacturer_color_alpha() const
	{
		return rom_manufacturer_color_alpha;
	}

	void setRom_manufacturer_color_alpha(int rom_manufacturer_color_alpha)
	{
		Theme::rom_manufacturer_color_alpha = rom_manufacturer_color_alpha;
	}

	int getRom_year_x() const
	{
		return rom_year_x;
	}

	void setRom_year_x(int rom_year_x)
	{
		Theme::rom_year_x = rom_year_x;
	}

	int getRom_year_y() const
	{
		return rom_year_y;
	}

	void setRom_year_y(int rom_year_y)
	{
		Theme::rom_year_y = rom_year_y;
	}

	int getRom_year_size() const
	{
		return rom_year_size;
	}

	void setRom_year_size(int rom_year_size)
	{
		Theme::rom_year_size = getFont_size_factor() * rom_year_size;
	}

	int getRom_year_color_red() const
	{
		return rom_year_color_red;
	}

	void setRom_year_color_red(int rom_year_color_red)
	{
		Theme::rom_year_color_red = rom_year_color_red;
	}

	int getRom_year_color_green() const
	{
		return rom_year_color_green;
	}

	void setRom_year_color_green(int rom_year_color_green)
	{
		Theme::rom_year_color_green = rom_year_color_green;
	}

	int getRom_year_color_blue() const
	{
		return rom_year_color_blue;
	}

	void setRom_year_color_blue(int rom_year_color_blue)
	{
		Theme::rom_year_color_blue = rom_year_color_blue;
	}

	int getRom_year_color_alpha() const
	{
		return rom_year_color_alpha;
	}

	void setRom_year_color_alpha(int rom_year_color_alpha)
	{
		Theme::rom_year_color_alpha = rom_year_color_alpha;
	}

	int getRom_name_selected_x() const
	{
		return rom_name_selected_x;
	}

	void setRom_name_selected_x(int rom_name_selected_x)
	{
		Theme::rom_name_selected_x = rom_name_selected_x;
	}

	int getRom_name_selected_y() const
	{
		return rom_name_selected_y;
	}

	void setRom_name_selected_y(int rom_name_selected_y)
	{
		Theme::rom_name_selected_y = rom_name_selected_y;
	}

	int getRom_name_to_display_above_selected() const
	{
		return rom_name_to_display_above_selected;
	}

	void setRom_name_to_display_above_selected(int rom_name_to_display_above_selected)
	{
		Theme::rom_name_to_display_above_selected = rom_name_to_display_above_selected;
	}

	int getRom_name_to_display_under_selected() const
	{
		return rom_name_to_display_under_selected;
	}

	void setRom_name_to_display_under_selected(int rom_name_to_display_under_selected)
	{
		Theme::rom_name_to_display_under_selected = rom_name_to_display_under_selected;
	}

	int getRom_name_size() const
	{
		return rom_name_size;
	}

	void setRom_name_size(int rom_name_size)
	{
		Theme::rom_name_size = getFont_size_factor() * rom_name_size;
	}

	int getRom_name_margin_size() const
	{
		return rom_name_margin_size;
	}

	void setRom_name_margin_size(int rom_name_margin_size)
	{
		Theme::rom_name_margin_size = rom_name_margin_size;
	}

	int getRom_name_max_length() const
	{
		return rom_name_max_length;
	}

	void setRom_name_max_length(int rom_name_max_length)
	{
		Theme::rom_name_max_length = rom_name_max_length;
	}

	const std::string& getRom_name_suffix_max_length() const
	{
		return rom_name_suffix_max_length;
	}

	void setRom_name_suffix_max_length(const std::string& rom_name_suffix_max_length)
	{
		Theme::rom_name_suffix_max_length = rom_name_suffix_max_length;
	}

	int getRom_name_color_red() const
	{
		return rom_name_color_red;
	}

	void setRom_name_color_red(int rom_name_color_red)
	{
		Theme::rom_name_color_red = rom_name_color_red;
	}

	int getRom_name_color_green() const
	{
		return rom_name_color_green;
	}

	void setRom_name_color_green(int rom_name_color_green)
	{
		Theme::rom_name_color_green = rom_name_color_green;
	}

	int getRom_name_color_blue() const
	{
		return rom_name_color_blue;
	}

	void setRom_name_color_blue(int rom_name_color_blue)
	{
		Theme::rom_name_color_blue = rom_name_color_blue;
	}

	int getRom_name_color_alpha() const
	{
		return rom_name_color_alpha;
	}

	void setRom_name_color_alpha(int rom_name_color_alpha)
	{
		Theme::rom_name_color_alpha = rom_name_color_alpha;
	}

	int getRom_index_x() const
	{
		return rom_index_x;
	}

	void setRom_index_x(int rom_index_x)
	{
		Theme::rom_index_x = rom_index_x;
	}

	int getRom_index_y() const
	{
		return rom_index_y;
	}

	void setRom_index_y(int rom_index_y)
	{
		Theme::rom_index_y = rom_index_y;
	}

	int getRom_index_size() const
	{
		return rom_index_size;
	}

	void setRom_index_size(int rom_index_size)
	{
		Theme::rom_index_size = getFont_size_factor() * rom_index_size;
	}

	int getRom_index_color_red() const
	{
		return rom_index_color_red;
	}

	void setRom_index_color_red(int rom_index_color_red)
	{
		Theme::rom_index_color_red = rom_index_color_red;
	}

	int getRom_index_color_green() const
	{
		return rom_index_color_green;
	}

	void setRom_index_color_green(int rom_index_color_green)
	{
		Theme::rom_index_color_green = rom_index_color_green;
	}

	int getRom_index_color_blue() const
	{
		return rom_index_color_blue;
	}

	void setRom_index_color_blue(int rom_index_color_blue)
	{
		Theme::rom_index_color_blue = rom_index_color_blue;
	}

	int getRom_index_color_alpha() const
	{
		return rom_index_color_alpha;
	}

	void setRom_index_color_alpha(int rom_index_color_alpha)
	{
		Theme::rom_index_color_alpha = rom_index_color_alpha;
	}

	int getRom_selection_indicator_vertical_margin() const
	{
		return rom_selection_indicator_vertical_margin;
	}

	void setRom_selection_indicator_vertical_margin(int rom_selection_indicator_vertical_margin)
	{
		Theme::rom_selection_indicator_vertical_margin = rom_selection_indicator_vertical_margin;
	}

	int getRom_selection_indicator_horizontal_margin() const
	{
		return rom_selection_indicator_horizontal_margin;
	}

	void setRom_selection_indicator_horizontal_margin(int rom_selection_indicator_horizontal_margin)
	{
		Theme::rom_selection_indicator_horizontal_margin = rom_selection_indicator_horizontal_margin;
	}

	int getRom_selection_indicator_width() const
	{
		return rom_selection_indicator_width;
	}

	void setRom_selection_indicator_width(int rom_selection_indicator_width)
	{
		Theme::rom_selection_indicator_width = rom_selection_indicator_width;
	}

	int getRom_selection_indicator_background_red() const
	{
		return rom_selection_indicator_background_red;
	}

	void setRom_selection_indicator_background_red(int rom_selection_indicator_background_red)
	{
		Theme::rom_selection_indicator_background_red = rom_selection_indicator_background_red;
	}

	int getRom_selection_indicator_background_green() const
	{
		return rom_selection_indicator_background_green;
	}

	void setRom_selection_indicator_background_green(int rom_selection_indicator_background_green)
	{
		Theme::rom_selection_indicator_background_green = rom_selection_indicator_background_green;
	}

	int getRom_selection_indicator_background_blue() const
	{
		return rom_selection_indicator_background_blue;
	}

	void setRom_selection_indicator_background_blue(int rom_selection_indicator_background_blue)
	{
		Theme::rom_selection_indicator_background_blue = rom_selection_indicator_background_blue;
	}

	int getRom_selection_indicator_background_alpha() const
	{
		return rom_selection_indicator_background_alpha;
	}

	void setRom_selection_indicator_background_alpha(int rom_selection_indicator_background_alpha)
	{
		Theme::rom_selection_indicator_background_alpha = rom_selection_indicator_background_alpha;
	}

	float getRom_selection_indicator_border_size() const
	{
		return rom_selection_indicator_border_size;
	}

	void setRom_selection_indicator_border_size(float rom_selection_indicator_border_size)
	{
		Theme::rom_selection_indicator_border_size = rom_selection_indicator_border_size;
	}

	int getRom_selection_indicator_border_red() const
	{
		return rom_selection_indicator_border_red;
	}

	void setRom_selection_indicator_border_red(int rom_selection_indicator_border_red)
	{
		Theme::rom_selection_indicator_border_red = rom_selection_indicator_border_red;
	}

	int getRom_selection_indicator_border_green() const
	{
		return rom_selection_indicator_border_green;
	}

	void setRom_selection_indicator_border_green(int rom_selection_indicator_border_green)
	{
		Theme::rom_selection_indicator_border_green = rom_selection_indicator_border_green;
	}

	int getRom_selection_indicator_border_blue() const
	{
		return rom_selection_indicator_border_blue;
	}

	void setRom_selection_indicator_border_blue(int rom_selection_indicator_border_blue)
	{
		Theme::rom_selection_indicator_border_blue = rom_selection_indicator_border_blue;
	}

	int getRom_selection_indicator_border_alpha() const
	{
		return rom_selection_indicator_border_alpha;
	}

	void setRom_selection_indicator_border_alpha(int rom_selection_indicator_border_alpha)
	{
		Theme::rom_selection_indicator_border_alpha = rom_selection_indicator_border_alpha;
	}

private:
	virtual void bindDirectivesToSetters();
};


#endif //MAMEUISEN_THEME_H