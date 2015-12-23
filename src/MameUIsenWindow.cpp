//
// Created by joseph on 21/12/15.
//

#include "MameUIsenWindow.h"
#include <iostream>
#include <sstream>

using namespace std;

MameUIsenWindow::MameUIsenWindow() : RenderWindow(), configuration(), romListManager()
{
	romListManager.loadTextures(configuration);
	if(!loadFontAndInitSprite())
	{
		exit(EXIT_FAILURE);
	}
	create(sf::VideoMode(configuration.getWindowWidth(), configuration.getWindowHeight()), "MameUIsen", sf::Style::Titlebar | sf::Style::Close	);
	display();
	lauch();
}


bool MameUIsenWindow::loadFontAndInitSprite()
{
	if(!font.loadFromFile(configuration.getFont_path()))
	{
		return false;
	}

	categoryName.setFont(font);
	categoryIndexProgress.setFont(font);
	romYear.setFont(font);
	romManufacturer.setFont(font);
	romIndexProgress.setFont(font);

	categoryName.setCharacterSize(configuration.getCategory_name_size());
	categoryIndexProgress.setCharacterSize(configuration.getCategory_index_size());
	romYear.setCharacterSize(configuration.getRom_year_size());
	romManufacturer.setCharacterSize(configuration.getRom_manufacturer_size());
	romIndexProgress.setCharacterSize(configuration.getRom_index_size());

	categoryName.setPosition(configuration.getCategory_name_x(),configuration.getCategory_name_y());
	categoryIndexProgress.setPosition(configuration.getCategory_index_x(), configuration.getCategory_index_y());
	romYear.setPosition(configuration.getRom_year_x(), configuration.getRom_year_y());
	romManufacturer.setPosition(configuration.getRom_manufacturer_x(), configuration.getRom_manufacturer_y());
	romIndexProgress.setPosition(configuration.getRom_index_x(), configuration.getRom_index_y());

	return true;
}

void MameUIsenWindow::lauch()
{
	RomList& romList = romListManager.getNextRomList();
	cout << romList.getName() << endl;
	romList = romListManager.getNextRomList();
	cout << romList.getName() << endl;
	romList = romListManager.getPreviousRomList();
	cout << romList.getName() << endl;
	romList = romListManager.getNextRomList();
	cout << romList.getName() << endl;
	romList = romListManager.getNextRomList();
	cout << romList.getName() << endl;
	romList = romListManager.getNextRomList();
	cout << romList.getName() << endl;
	clear(sf::Color::Black);
	display();
	clear(sf::Color::Black);
	display();
	updateCategoryDisplay(romList.getName(), romListManager.getCurrentRomSetIndex(), romListManager.getRomSetNumber());
	display();
	std::system("sleep 5");
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

void MameUIsenWindow::updateCategoryDisplay(const string& catName, int catIndex, int catTotal)
{
	categoryName.setString(catName);
	draw(categoryName);

	stringstream categoryIndex;
	categoryIndex << catIndex << "/" << catTotal;
	categoryIndexProgress.setString(categoryIndex.str());
	draw(categoryIndexProgress);
}