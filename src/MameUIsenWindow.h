//
// Created by joseph on 21/12/15.
//

#ifndef MAMEUISEN_MAMEUISENWINDOW_H
#define MAMEUISEN_MAMEUISENWINDOW_H

#include <SFML/Graphics.hpp>
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
	void lauch();
};


#endif //MAMEUISEN_MAMEUISENWINDOW_H