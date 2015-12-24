//
// Created by joseph on 21/12/15.
//

#include "MameUIsenWindow.h"
#include <sstream>

using namespace std;

MameUIsenWindow::MameUIsenWindow() : RenderWindow(), configuration(), romListManager()
{
	romListManager.loadTextures(configuration);
	if(!loadFontAndInitSprite())
	{
		exit(EXIT_FAILURE);
	}
	romListManager.initText(configuration, font);
	create(sf::VideoMode(configuration.getWindowWidth(), configuration.getWindowHeight()), "MameUIsen", sf::Style::Titlebar | sf::Style::Close);
	setVerticalSyncEnabled(true);
	display();
	lauch();
}


bool MameUIsenWindow::loadFontAndInitSprite()
{
	if(!font.loadFromFile(configuration.getFont_path()))
	{
		return false;
	}

	//Font
	categoryName.setFont(font);
	categoryIndexProgress.setFont(font);
	romYear.setFont(font);
	romManufacturer.setFont(font);
	romIndexProgress.setFont(font);

	//Size
	categoryName.setCharacterSize(configuration.getCategory_name_size());
	categoryIndexProgress.setCharacterSize(configuration.getCategory_index_size());
	romYear.setCharacterSize(configuration.getRom_year_size());
	romManufacturer.setCharacterSize(configuration.getRom_manufacturer_size());
	romIndexProgress.setCharacterSize(configuration.getRom_index_size());

	//Position
	categoryName.setPosition(configuration.getCategory_name_x(),configuration.getCategory_name_y());
	categoryIndexProgress.setPosition(configuration.getCategory_index_x(), configuration.getCategory_index_y());
	romYear.setPosition(configuration.getRom_year_x(), configuration.getRom_year_y());
	romManufacturer.setPosition(configuration.getRom_manufacturer_x(), configuration.getRom_manufacturer_y());
	romIndexProgress.setPosition(configuration.getRom_index_x(), configuration.getRom_index_y());
	screenshot.setPosition(configuration.getRom_screenshot_x(), configuration.getRom_screenshot_y());

	//Color
	categoryName.setColor(sf::Color(configuration.getCategory_name_color_red(),
									configuration.getCategory_name_color_green(),
									configuration.getCategory_name_color_blue(),
									configuration.getCategory_name_color_alpha()));
	categoryIndexProgress.setColor(sf::Color(configuration.getCategory_index_color_red(),
											 configuration.getCategory_index_color_green(),
											 configuration.getCategory_index_color_blue(),
											 configuration.getCategory_index_color_alpha()));
	romYear.setColor(sf::Color(configuration.getRom_year_color_red(),
							   configuration.getRom_year_color_green(),
							   configuration.getRom_year_color_blue(),
							   configuration.getRom_year_color_alpha()));
	romManufacturer.setColor(sf::Color(configuration.getRom_manufacturer_color_red(),
									   configuration.getRom_manufacturer_color_green(),
									   configuration.getRom_manufacturer_color_blue(),
									   configuration.getRom_manufacturer_color_alpha()));
	romIndexProgress.setColor(sf::Color(configuration.getRom_index_color_red(),
										configuration.getRom_index_color_green(),
										configuration.getRom_index_color_blue(),
										configuration.getRom_index_color_alpha()));

	return true;
}

void MameUIsenWindow::lauch()
{
	RomList* romList = romListManager.getNextRomList();
	Rom* rom = romList->getRom(1);
	rebaseRomNamesPosition(*romList);
	unsigned int numRom = 1;

	while(isOpen())
	{
		event e = getEvent();
		switch(e)
		{
			case NO_EVENT:
				break;
			case NEXT_ROM:
				if(numRom != romList->getRomListSize())
				{
					rom = romList->getRom(++numRom);
				}
				break;
			case PREVIOUS_ROM:
				if(numRom != 1)
				{
					rom = romList->getRom(--numRom);
				}
				break;
			case NEXT_CATEGORY:
				romList = romListManager.getNextRomList();
				numRom = 1;
				rom = romList->getRom(1);
				rebaseRomNamesPosition(*romList);
				break;
			case PREVIOUS_CATEGORY:
				romList = romListManager.getPreviousRomList();
				numRom = 1;
				rom = romList->getRom(1);
				rebaseRomNamesPosition(*romList);
				break;
			case LAUNCH_ROM:
			{
				string cmd(configuration.getMame_path() + " -rompath " + configuration.getRom_path() + " ");
				cmd += rom->getFilename();
				system(cmd.c_str());
				break;
			}
			case EXIT:
				close();
		}
		updateAllDisplay(*romList, *rom, numRom);
		displayAll(numRom, *romList);
	}
}

void MameUIsenWindow::updateAllDisplay(const RomList& romList, const Rom& rom, int currentRomIndex)
{
	updateCategoryDisplay(romList);
	updateRomInfosDisplay(rom, currentRomIndex, romList.getRomListSize());
	updateScreenshotDisplay(rom);
	updateRomsNamesDisplay(romList);
}

void MameUIsenWindow::displayAll(const int currentRomIndex, const RomList& romList)
{
	clear(sf::Color::Black);
	displayCategory();
	displayRomInfos();
	displayScreenshot();
	displayRomsNames(romList, currentRomIndex);
	display();
}

void MameUIsenWindow::updateCategoryDisplay(const RomList& romList)
{
	categoryName.setString(romList.getName());

	stringstream categoryIndex;
	categoryIndex << romListManager.getCurrentRomSetIndex() << "/" << romListManager.getRomSetNumber();
	categoryIndexProgress.setString(categoryIndex.str());
}

void MameUIsenWindow::displayCategory()
{
	draw(categoryName);
	draw(categoryIndexProgress);
}

void MameUIsenWindow::updateRomInfosDisplay(const Rom& rom, int romIndex, int romTotal)
{
	romYear.setString(rom.getYear());

	romManufacturer.setString(rom.getManufacturer());

	stringstream romIndexString;
	romIndexString << romIndex << "/" << romTotal;
	romIndexProgress.setString(romIndexString.str());
}


void MameUIsenWindow::displayRomInfos()
{
	draw(romYear);
	draw(romManufacturer);
	draw(romIndexProgress);
}

void MameUIsenWindow::updateScreenshotDisplay(const Rom& rom)
{
	screenshot.setTexture(rom.getTexture(), true);
}

void MameUIsenWindow::displayScreenshot()
{
	draw(screenshot);
}

void MameUIsenWindow::updateRomsNamesDisplay(const RomList& romList)
{

}

void MameUIsenWindow::displayRomsNames(const RomList& romList, int currentRomIndex)
{
	int aboveLimit = currentRomIndex - configuration.getRom_name_to_display_above_selected();
	int underLimit = configuration.getRom_name_to_display_under_selected() + currentRomIndex;

	if(aboveLimit < 1)
	{
		aboveLimit = 1;
	}
	if(underLimit > romList.getRomListSize())
	{
		underLimit = romList.getRomListSize();
	}

	Rom* rom = romList.getRom(aboveLimit);

	sf::View romNameView = getDefaultView();
	int offset = (currentRomIndex - 1) * (configuration.getRom_name_size() + configuration.getRom_name_margin_size());
	romNameView.move(0, offset);
	setView(romNameView);
	for(int i = aboveLimit; i <= underLimit; i++, rom = romList.getRom(i))
	{
		draw(rom->getTextSprite());
	}
	setView(getDefaultView());
}

void MameUIsenWindow::rebaseRomNamesPosition(RomList& romList)
{
	int x = configuration.getRom_name_selected_x();
	int y = configuration.getRom_name_selected_y();

	Rom* rom = romList.getRom(1);
	for(int i = 1; i <= romList.getRomListSize(); i++, rom = romList.getRom(i))
	{
		rom->getTextSprite().setPosition(x,y);
		y += configuration.getRom_name_size() + configuration.getRom_name_margin_size();
	}
}

event MameUIsenWindow::getEvent()
{
	sf::Event event;
	pollEvent(event);

	switch(event.type)
	{
		case sf::Event::Closed:
			return EXIT;
		case sf::Event::KeyPressed:
			switch(event.key.code)
			{
				case sf::Keyboard::Escape:
					return EXIT;
				case sf::Keyboard::Up:
					return PREVIOUS_ROM;
				case sf::Keyboard::Down:
					return NEXT_ROM;
				case sf::Keyboard::Left:
					return PREVIOUS_CATEGORY;
				case sf::Keyboard::Right:
					return NEXT_CATEGORY;
				case sf::Keyboard::Return:
					return LAUNCH_ROM;
				default:
					return NO_EVENT;
			}
		default:
			return NO_EVENT;
	}
}