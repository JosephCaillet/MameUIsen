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
	int sfmlVideoFlags = sf::Style::Titlebar | sf::Style::Close;
	if(configuration.isFullscreen())
	{
		sfmlVideoFlags |= sf::Style::Fullscreen;
	}
	create(sf::VideoMode(configuration.getWindowWidth(), configuration.getWindowHeight()), "MameUIsen", sfmlVideoFlags);
	setVerticalSyncEnabled(true);
	display();
	launch();
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

void MameUIsenWindow::launch()
{
	RomList* romList = romListManager.getNextRomList();
	Rom* rom = romList->getRom(1);
	rebaseRomNamesPosition(*romList);
	unsigned int currentRomIndex = 1;
	screenshot.setScale(configuration.getRom_screenshot_size_factor(), configuration.getRom_screenshot_size_factor());
	updateAllDisplay(*romList, *rom, currentRomIndex);
	while(isOpen())
	{
		event e = getEvent();
		switch(e)
		{
			case NO_EVENT:
				break;
			case NEXT_ROM:
				if(currentRomIndex != romList->getRomListSize())
				{
					rom = romList->getRom(++currentRomIndex);
					updateRomInfosDisplay(*rom, currentRomIndex, romList->getRomListSize());
					updateScreenshotDisplay(*rom);
					updateRomsNamesDisplay(currentRomIndex);
				}
				break;
			case PREVIOUS_ROM:
				if(currentRomIndex != 1)
				{
					rom = romList->getRom(--currentRomIndex);
					updateRomInfosDisplay(*rom, currentRomIndex, romList->getRomListSize());
					updateScreenshotDisplay(*rom);
					updateRomsNamesDisplay(currentRomIndex);
				}
				break;
			case NEXT_CATEGORY:
				romList = romListManager.getNextRomList();
				currentRomIndex = 1;
				rom = romList->getRom(1);
				rebaseRomNamesPosition(*romList);
				updateAllDisplay(*romList, *rom, currentRomIndex);
				break;
			case PREVIOUS_CATEGORY:
				romList = romListManager.getPreviousRomList();
				currentRomIndex = 1;
				rom = romList->getRom(1);
				rebaseRomNamesPosition(*romList);
				updateAllDisplay(*romList, *rom, currentRomIndex);
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
		displayAll(currentRomIndex, *romList);
	}
}

void MameUIsenWindow::updateAllDisplay(const RomList& romList, const Rom& rom, int currentRomIndex)
{
	updateCategoryDisplay(romList);
	updateRomInfosDisplay(rom, currentRomIndex, romList.getRomListSize());
	updateScreenshotDisplay(rom);
	updateRomsNamesDisplay(currentRomIndex);
}

void MameUIsenWindow::displayAll(const int currentRomIndex, const RomList& romList)
{
	clear(sf::Color::Black);
	displayScreenshot();
	displayCategory();
	displayRomInfos();
	displayRomsNames(romList, currentRomIndex);
	display();
}

void MameUIsenWindow::updateCategoryDisplay(const RomList& romList)
{
	categoryName.setString(romList.getName());

	stringstream categoryIndex;
	categoryIndex << romListManager.getCurrentRomSetIndex() << "/" << romListManager.getRomSetNumber();
	categoryIndexProgress.setString(categoryIndex.str());

	centerElement(categoryName);
	centerElement(categoryIndexProgress);
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

	centerElement(romYear);
	centerElement(romManufacturer);
	centerElement(romIndexProgress);
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
	centerElement(screenshot);
}

void MameUIsenWindow::displayScreenshot()
{
	draw(screenshot);
}

void MameUIsenWindow::updateRomsNamesDisplay(const int currentRomIndex)
{
	romNameView = getDefaultView();
	int offset = (currentRomIndex - 1) * (configuration.getRom_name_size() + configuration.getRom_name_margin_size());
	romNameView.move(0, offset);
}

void MameUIsenWindow::displayRomsNames(const RomList& romList, int currentRomIndex)
{
	int aboveLimit = currentRomIndex - configuration.getRom_name_to_display_above_selected();
	int underLimit = configuration.getRom_name_to_display_under_selected() + currentRomIndex;

	if(aboveLimit < 1)
	{
		aboveLimit = 1;
	}
	if(underLimit > (int)romList.getRomListSize())
	{
		underLimit = romList.getRomListSize();
	}

	Rom* rom = romList.getRom(aboveLimit);

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
	for(int i = 1; i <= (int)romList.getRomListSize(); i++, rom = romList.getRom(i))
	{
		rom->getTextSprite().setPosition(x,y);
		y += configuration.getRom_name_size() + configuration.getRom_name_margin_size();
		centerElement(rom->getTextSprite());
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

void MameUIsenWindow::centerElement(sf::Sprite& sprite)
{
	sf::FloatRect fr = sprite.getLocalBounds();
	sprite.setOrigin(fr.width/2.0f, fr.height/2.0f);
}

void MameUIsenWindow::centerElement(sf::Text& text)
{
	sf::FloatRect fr = text.getLocalBounds();
	text.setOrigin(fr.width/2.0f, fr.height/2.0f);
}