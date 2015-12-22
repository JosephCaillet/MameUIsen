//
// Created by joseph on 21/12/15.
//

#include "MameUIsenWindow.h"


MameUIsenWindow::MameUIsenWindow() : RenderWindow(), configuration(), romListManager()
{
	create(sf::VideoMode(configuration.getWindowWidth(), configuration.getWindowHeight()), "MameUIsen", sf::Style::Titlebar | sf::Style::Close	);
	display();
}

void MameUIsenWindow::lauch()
{
	//Get the first category
	//Display category name and quantity
	//Display games titles
	//Display image and info about the selected game
	//If event change current game
	//	update game list
	//	Display category name and quantity
	//	Display games titles
	//	Display image and info about the selected game
	//If event change category
	//	update category
	//	update game list
	//	Display category name and quantity
	//	Display games titles
	//	Display image and info about the selected game
	//If exit
	//	quit
}