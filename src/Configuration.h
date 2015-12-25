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
	std::string font_path = "../rsc/04B_30__.TTF";
	float font_size_factor = 1.0f;

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

	std::vector<ConfigDirectiveToFunction> directiveToFunction;

private:
	void loadConf();

public:
	Configuration();

	//General
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

	const std::string& getFont_path() const
	{
		return font_path;
	}

	void setFont_path(const std::string& font_path)
	{
		Configuration::font_path = font_path;
	}

	float getFont_size_factor() const
	{
		return font_size_factor;
	}

	void setFont_size_factor(const std::string& font_size_factor)
	{
		Configuration::font_size_factor = std::stof(font_size_factor);
	}

//Category name
	int getCategory_name_x() const
	{
		return category_name_x;
	}

	void setCategory_name_x(const std::string& category_name_x)
	{
		Configuration::category_name_x = std::stoi(category_name_x);
	}

	int getCategory_name_y() const
	{
		return category_name_y;
	}

	void setCategory_name_y(const std::string& category_name_y)
	{
		Configuration::category_name_y = std::stoi(category_name_y);
	}

	int getCategory_name_size() const
	{
		return category_name_size;
	}

	void setCategory_name_size(const std::string& category_name_size)
	{
		Configuration::category_name_size = getFont_size_factor() * std::stoi(category_name_size);
	}

	int getCategory_name_color_red() const
	{
		return category_name_color_red;
	}

	void setCategory_name_color_red(const std::string& category_name_color_red)
	{
		Configuration::category_name_color_red = std::stoi(category_name_color_red);
	}

	int getCategory_name_color_green() const
	{
		return category_name_color_green;
	}

	void setCategory_name_color_green(const std::string& category_name_color_green)
	{
		Configuration::category_name_color_green = std::stoi(category_name_color_green);
	}

	int getCategory_name_color_blue() const
	{
		return category_name_color_blue;
	}

	void setCategory_name_color_blue(const std::string& category_name_color_blue)
	{
		Configuration::category_name_color_blue = std::stoi(category_name_color_blue);
	}

	int getCategory_name_color_alpha() const
	{
		return category_name_color_alpha;
	}

	void setCategory_name_color_alpha(const std::string& category_name_color_alpha)
	{
		Configuration::category_name_color_alpha = std::stoi(category_name_color_alpha);
	}

	//Category index
	int getCategory_index_x() const
	{
		return category_index_x;
	}

	void setCategory_index_x(const std::string& category_index_x)
	{
		Configuration::category_index_x = std::stoi(category_index_x);
	}

	int getCategory_index_y() const
	{
		return category_index_y;
	}

	void setCategory_index_y(const std::string& category_index_y)
	{
		Configuration::category_index_y = std::stoi(category_index_y);
	}

	int getCategory_index_size() const
	{
		return category_index_size;
	}

	void setCategory_index_size(const std::string& category_index_size)
	{
		Configuration::category_index_size = getFont_size_factor() * std::stoi(category_index_size);
	}

	int getCategory_index_color_red() const
	{
		return category_index_color_red;
	}

	void setCategory_index_color_red(const std::string& category_index_color_red)
	{
		Configuration::category_index_color_red = std::stoi(category_index_color_red);
	}

	int getCategory_index_color_green() const
	{
		return category_index_color_green;
	}

	void setCategory_index_color_green(const std::string& category_index_color_green)
	{
		Configuration::category_index_color_green = std::stoi(category_index_color_green);
	}

	int getCategory_index_color_blue() const
	{
		return category_index_color_blue;
	}

	void setCategory_index_color_blue(const std::string& category_index_color_blue)
	{
		Configuration::category_index_color_blue = std::stoi(category_index_color_blue);
	}

	int getCategory_index_color_alpha() const
	{
		return category_index_color_alpha;
	}

	void setCategory_index_color_alpha(const std::string& category_index_color_alpha)
	{
		Configuration::category_index_color_alpha = std::stoi(category_index_color_alpha);
	}

	//Rom screenshot
	int getRom_screenshot_x() const
	{
		return rom_screenshot_x;
	}

	void setRom_screenshot_x(const std::string& rom_screenshot_x)
	{
		Configuration::rom_screenshot_x = std::stoi(rom_screenshot_x);
	}

	int getRom_screenshot_y() const
	{
		return rom_screenshot_y;
	}

	void setRom_screenshot_y(const std::string& rom_screenshot_y)
	{
		Configuration::rom_screenshot_y = std::stoi(rom_screenshot_y);
	}

	float getRom_screenshot_size_factor() const
	{
		return rom_screenshot_size_factor;
	}

	void setRom_screenshot_size_factor(const std::string& rom_screenshot_size_factor)
	{
		Configuration::rom_screenshot_size_factor = std::stof(rom_screenshot_size_factor);
	}

	//Rom manufacturer
	int getRom_manufacturer_x() const
	{
		return rom_manufacturer_x;
	}

	void setRom_manufacturer_x(const std::string& rom_manufacturer_x)
	{
		Configuration::rom_manufacturer_x = std::stoi(rom_manufacturer_x);
	}

	int getRom_manufacturer_y() const
	{
		return rom_manufacturer_y;
	}

	void setRom_manufacturer_y(const std::string& rom_manufacturer_y)
	{
		Configuration::rom_manufacturer_y = std::stoi(rom_manufacturer_y);
	}

	int getRom_manufacturer_size() const
	{
		return rom_manufacturer_size;
	}

	void setRom_manufacturer_size(const std::string& rom_manufacturer_size)
	{
		Configuration::rom_manufacturer_size = getFont_size_factor() * std::stoi(rom_manufacturer_size);
	}

	int getRom_manufacturer_color_red() const
	{
		return rom_manufacturer_color_red;
	}

	void setRom_manufacturer_color_red(const std::string& rom_manufacturer_color_red)
	{
		Configuration::rom_manufacturer_color_red = std::stoi(rom_manufacturer_color_red);
	}

	int getRom_manufacturer_color_green() const
	{
		return rom_manufacturer_color_green;
	}

	void setRom_manufacturer_color_green(const std::string& rom_manufacturer_color_green)
	{
		Configuration::rom_manufacturer_color_green = std::stoi(rom_manufacturer_color_green);
	}

	int getRom_manufacturer_color_blue() const
	{
		return rom_manufacturer_color_blue;
	}

	void setRom_manufacturer_color_blue(const std::string& rom_manufacturer_color_blue)
	{
		Configuration::rom_manufacturer_color_blue = std::stoi(rom_manufacturer_color_blue);
	}

	int getRom_manufacturer_color_alpha() const
	{
		return rom_manufacturer_color_alpha;
	}

	void setRom_manufacturer_color_alpha(const std::string& rom_manufacturer_color_alpha)
	{
		Configuration::rom_manufacturer_color_alpha = std::stoi(rom_manufacturer_color_alpha);
	}

	//Rom year
	int getRom_year_x() const
	{
		return rom_year_x;
	}

	void setRom_year_x(const std::string& rom_year_x)
	{
		Configuration::rom_year_x = std::stoi(rom_year_x);
	}

	int getRom_year_y() const
	{
		return rom_year_y;
	}

	void setRom_year_y(const std::string& rom_year_y)
	{
		Configuration::rom_year_y = std::stoi(rom_year_y);
	}

	int getRom_year_size() const
	{
		return rom_year_size;
	}

	void setRom_year_size(const std::string& rom_year_size)
	{
		Configuration::rom_year_size = getFont_size_factor() * std::stoi(rom_year_size);
	}

	int getRom_year_color_red() const
	{
		return rom_year_color_red;
	}

	void setRom_year_color_red(const std::string& rom_year_color_red)
	{
		Configuration::rom_year_color_red = std::stoi(rom_year_color_red);
	}

	int getRom_year_color_green() const
	{
		return rom_year_color_green;
	}

	void setRom_year_color_green(const std::string& rom_year_color_green)
	{
		Configuration::rom_year_color_green = std::stoi(rom_year_color_green);
	}

	int getRom_year_color_blue() const
	{
		return rom_year_color_blue;
	}

	void setRom_year_color_blue(const std::string& rom_year_color_blue)
	{
		Configuration::rom_year_color_blue = std::stoi(rom_year_color_blue);
	}

	int getRom_year_color_alpha() const
	{
		return rom_year_color_alpha;
	}

	void setRom_year_color_alpha(const std::string& rom_year_color_alpha)
	{
		Configuration::rom_year_color_alpha = std::stoi(rom_year_color_alpha);
	}

	//Rom name
	int getRom_name_selected_x() const
	{
		return rom_name_selected_x;
	}

	void setRom_name_selected_x(const std::string& rom_name_x)
	{
		Configuration::rom_name_selected_x = std::stoi(rom_name_x);
	}

	int getRom_name_selected_y() const
	{
		return rom_name_selected_y;
	}

	void setRom_name_selected_y(const std::string& rom_name_y)
	{
		Configuration::rom_name_selected_y = std::stoi(rom_name_y);
	}

	int getRom_name_to_display_above_selected() const
	{
		return rom_name_to_display_above_selected;
	}

	void setRom_name_to_display_above_selected(const std::string& rom_name_to_display_above_selected)
	{
		Configuration::rom_name_to_display_above_selected = std::stoi(rom_name_to_display_above_selected);
	}

	int getRom_name_to_display_under_selected() const
	{
		return rom_name_to_display_under_selected;
	}

	void setRom_name_to_display_under_selected(const std::string& rom_name_to_display_under_selected)
	{
		Configuration::rom_name_to_display_under_selected = std::stoi(rom_name_to_display_under_selected);
	}

	int getRom_name_size() const
	{
		return rom_name_size;
	}

	void setRom_name_size(const std::string& rom_name_size)
	{
		Configuration::rom_name_size = getFont_size_factor() * std::stoi(rom_name_size);
	}

	int getRom_name_margin_size() const
	{
		return rom_name_margin_size;
	}

	void setRom_name_margin_size(const std::string& rom_name_margin_size)
	{
		Configuration::rom_name_margin_size = std::stoi(rom_name_margin_size);
	}

	int getRom_name_max_length() const
	{
		return rom_name_max_length;
	}

	const std::string& getRom_name_suffix_max_length() const
	{
		return rom_name_suffix_max_length;
	}

	void setRom_name_suffix_max_length(const std::string& rom_name_suffix_max_length)
	{
		if(rom_name_suffix_max_length == "UnicornTrololoHamtaro")
		{
			Configuration::rom_name_suffix_max_length.clear();
		}
		else
		{
			Configuration::rom_name_suffix_max_length = rom_name_suffix_max_length;
		}
	}

	void setRom_name_max_length(const std::string& rom_name_max_length)
	{
		Configuration::rom_name_max_length = std::stoi(rom_name_max_length);
	}

	int getRom_name_color_red() const
	{
		return rom_name_color_red;
	}

	void setRom_name_color_red(const std::string& rom_name_color_red)
	{
		Configuration::rom_name_color_red = std::stoi(rom_name_color_red);
	}

	int getRom_name_color_green() const
	{
		return rom_name_color_green;
	}

	void setRom_name_color_green(const std::string& rom_name_color_green)
	{
		Configuration::rom_name_color_green = std::stoi(rom_name_color_green);
	}

	int getRom_name_color_blue() const
	{
		return rom_name_color_blue;
	}

	void setRom_name_color_blue(const std::string& rom_name_color_blue)
	{
		Configuration::rom_name_color_blue = std::stoi(rom_name_color_blue);
	}

	int getRom_name_color_alpha() const
	{
		return rom_name_color_alpha;
	}

	void setRom_name_color_alpha(const std::string& rom_name_color_alpha)
	{
		Configuration::rom_name_color_alpha = std::stoi(rom_name_color_alpha);
	}

	//Rom index
	int getRom_index_x() const
	{
		return rom_index_x;
	}

	void setRom_index_x(const std::string& rom_index_x)
	{
		Configuration::rom_index_x = std::stoi(rom_index_x);
	}

	int getRom_index_size() const
	{
		return rom_index_size;
	}

	void setRom_index_size(const std::string& rom_index_size)
	{
		Configuration::rom_index_size = getFont_size_factor() * std::stoi(rom_index_size);
	}

	int getRom_index_y() const
	{
		return rom_index_y;
	}

	void setRom_index_y(const std::string& rom_index_y)
	{
		Configuration::rom_index_y = std::stoi(rom_index_y);
	}

	int getRom_index_color_red() const
	{
		return rom_index_color_red;
	}

	void setRom_index_color_red(const std::string& rom_index_color_red)
	{
		Configuration::rom_index_color_red = std::stoi(rom_index_color_red);
	}

	int getRom_index_color_green() const
	{
		return rom_index_color_green;
	}

	void setRom_index_color_green(const std::string& rom_index_color_green)
	{
		Configuration::rom_index_color_green = std::stoi(rom_index_color_green);
	}

	int getRom_index_color_blue() const
	{
		return rom_index_color_blue;
	}

	void setRom_index_color_blue(const std::string& rom_index_color_blue)
	{
		Configuration::rom_index_color_blue = std::stoi(rom_index_color_blue);
	}

	int getRom_index_color_alpha() const
	{
		return rom_index_color_alpha;
	}

	void setRom_index_color_alpha(const std::string& rom_index_color_alpha)
	{
		Configuration::rom_index_color_alpha = std::stoi(rom_index_color_alpha);
	}
};


#endif //MAMEUISEN_CONFIGURATION_H