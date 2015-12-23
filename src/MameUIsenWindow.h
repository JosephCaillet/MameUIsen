//
// Created by joseph on 21/12/15.
//

#ifndef MAMEUISEN_MAMEUISENWINDOW_H
#define MAMEUISEN_MAMEUISENWINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Configuration.h"
#include "RomListManager.h"

class MameUIsenWindow : sf::RenderWindow
{
private:
	Configuration configuration;
	RomListManager romListManager;

	sf::Sprite screenshot;
	sf::Font font;
	sf::Text categoryName;
	sf::Text categoryIndexProgress;
	sf::Text romYear;
	sf::Text romManufacturer;
	sf::Text romIndexProgress;

public:
	MameUIsenWindow();

private:
	bool loadFontAndInitSprite();
	void lauch();
	void updateCategoryDisplay(const std::string& catName, int catIndex, int catTotal);
};

enum event
{
	NO_EVENT,
	EXIT,
	NEXT_ROM, PREVIOUS_ROM,
	NEXT_CATEGORY, PREVIOUS_CATEGORY
};

#endif //MAMEUISEN_MAMEUISENWINDOW_H