//
// Created by joseph on 21/12/15.
//

#include "MameUIsenWindow.h"


MameUIsenWindow::MameUIsenWindow() : RenderWindow(), configuration(), romListManager()
{
	create(sf::VideoMode(configuration.getWindowWidth(), configuration.getWindowHeight()), "MameUIsen", sf::Style::Titlebar | sf::Style::Close	);
	display();
}
