//
// Created by joseph on 21/12/15.
//

#include "MameUIsenWindow.h"

using namespace std;

MameUIsenWindow::MameUIsenWindow(const std::string& configFilePath)
		: RenderWindow(), configuration(configFilePath), theme(configuration.getTheme_path()),
		  romListManager(configuration)
{
	romListManager.loadTextures(configuration, theme);
	if(!loadFontAndInitSprite())
	{
		exit(EXIT_FAILURE);
	}

	if(theme.getBackground_image_path() != "")
	{
		backgroundImageTexture = new sf::Texture;
		backgroundImageTexture->loadFromFile(theme.getBackground_image_path());
		backgroundImageTexture->setSmooth(theme.isBackground_image_smooth_zoom());
		backgroundImageSprite.setTexture(*backgroundImageTexture);
		backgroundImageSprite.setPosition(theme.getWindowWidth()/2 + theme.getBackground_image_x_offset(),
										  theme.getWindowHeight()/2 + theme.getBackground_image_y_offset());
		backgroundImageSprite.setScale(theme.getBackground_image_size_factor(), theme.getBackground_image_size_factor());
		centerElement(backgroundImageSprite);
		backgroundImageSprite.setColor(sf::Color(255, 255, 255, theme.getBackground_image_alpha()));
	}

	romListManager.initText(theme, font);
	int sfmlVideoFlags = sf::Style::Titlebar | sf::Style::Close;
	if(configuration.isFullscreen())
	{
		sfmlVideoFlags |= sf::Style::Fullscreen;
	}

	create(sf::VideoMode(theme.getWindowWidth(), theme.getWindowHeight()), "MameUIsen", sfmlVideoFlags);
	setFramerateLimit(configuration.getFps_rate());
	setMouseCursorVisible(false);
}


MameUIsenWindow::~MameUIsenWindow()
{
	delete backgroundImageTexture;
}

bool MameUIsenWindow::loadFontAndInitSprite()
{
	if(!font.loadFromFile(theme.getFont_path()))
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
	categoryName.setCharacterSize(theme.getCategory_name_size());
	categoryIndexProgress.setCharacterSize(theme.getCategory_index_size());
	romYear.setCharacterSize(theme.getRom_year_size());
	romManufacturer.setCharacterSize(theme.getRom_manufacturer_size());
	romIndexProgress.setCharacterSize(theme.getRom_index_size());
	selectedRomIndicator.setOutlineThickness(theme.getRom_selection_indicator_border_size());

	//Position
	categoryName.setPosition(theme.getCategory_name_x(),theme.getCategory_name_y());
	categoryIndexProgress.setPosition(theme.getCategory_index_x(), theme.getCategory_index_y());
	romYear.setPosition(theme.getRom_year_x(), theme.getRom_year_y());
	romManufacturer.setPosition(theme.getRom_manufacturer_x(), theme.getRom_manufacturer_y());
	romIndexProgress.setPosition(theme.getRom_index_x(), theme.getRom_index_y());
	screenshot.setPosition(theme.getRom_screenshot_x(), theme.getRom_screenshot_y());
	selectedRomIndicator.setPosition(theme.getRom_name_selected_x(), theme.getRom_name_selected_y());

	//Color
	categoryName.setColor(sf::Color(theme.getCategory_name_color_red(),
									theme.getCategory_name_color_green(),
									theme.getCategory_name_color_blue(),
									theme.getCategory_name_color_alpha()));
	categoryIndexProgress.setColor(sf::Color(theme.getCategory_index_color_red(),
											 theme.getCategory_index_color_green(),
											 theme.getCategory_index_color_blue(),
											 theme.getCategory_index_color_alpha()));
	romYear.setColor(sf::Color(theme.getRom_year_color_red(),
							   theme.getRom_year_color_green(),
							   theme.getRom_year_color_blue(),
							   theme.getRom_year_color_alpha()));
	romManufacturer.setColor(sf::Color(theme.getRom_manufacturer_color_red(),
									   theme.getRom_manufacturer_color_green(),
									   theme.getRom_manufacturer_color_blue(),
									   theme.getRom_manufacturer_color_alpha()));
	romIndexProgress.setColor(sf::Color(theme.getRom_index_color_red(),
										theme.getRom_index_color_green(),
										theme.getRom_index_color_blue(),
										theme.getRom_index_color_alpha()));
	selectedRomIndicator.setFillColor(sf::Color(theme.getRom_selection_indicator_background_red(),
												theme.getRom_selection_indicator_background_green(),
												theme.getRom_selection_indicator_background_blue(),
												theme.getRom_selection_indicator_background_alpha()));
	selectedRomIndicator.setOutlineColor(sf::Color(theme.getRom_selection_indicator_border_red(),
												theme.getRom_selection_indicator_border_green(),
												theme.getRom_selection_indicator_border_blue(),
												theme.getRom_selection_indicator_border_alpha()));
	return true;
}

void MameUIsenWindow::launch()
{
	RomList* romList = romListManager.getNextRomList();
	Rom* rom = romList->getRom(1);
	rebaseRomNamesPosition(*romList);
	unsigned int currentRomIndex = 1;
	screenshot.setScale(theme.getRom_screenshot_size_factor(), theme.getRom_screenshot_size_factor());
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
					updateSelectedRomIndicator(*rom);
				}
				break;
			case PREVIOUS_ROM:
				if(currentRomIndex != 1)
				{
					rom = romList->getRom(--currentRomIndex);
					updateRomInfosDisplay(*rom, currentRomIndex, romList->getRomListSize());
					updateScreenshotDisplay(*rom);
					updateRomsNamesDisplay(currentRomIndex);
					updateSelectedRomIndicator(*rom);
				}
				break;
			case NEXT_CATEGORY:
				romList->setLastViewedRomIndex(currentRomIndex);
				romList = romListManager.getNextRomList();
				currentRomIndex = romList->getLastViewedRomIndex();
				rom = romList->getRom(currentRomIndex);
				rebaseRomNamesPosition(*romList);
				updateAllDisplay(*romList, *rom, currentRomIndex);
				break;
			case PREVIOUS_CATEGORY:
				romList->setLastViewedRomIndex(currentRomIndex);
				romList = romListManager.getPreviousRomList();
				currentRomIndex = romList->getLastViewedRomIndex();
				rom = romList->getRom(currentRomIndex);
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
	updateSelectedRomIndicator(rom);
}

void MameUIsenWindow::displayAll(const int currentRomIndex, const RomList& romList)
{
	clear(sf::Color(theme.getBackground_red(), theme.getBackground_green(), theme.getBackground_blue()));
	displayBackgroundImage();
	displayScreenshot();
	displayCategory();
	displayRomInfos();
	displaySelectedRomIndicator();
	displayRomsNames(romList, currentRomIndex);
	display();
}

void MameUIsenWindow::displayBackgroundImage()
{
	draw(backgroundImageSprite);
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

void MameUIsenWindow::updateSelectedRomIndicator(const Rom& rom)
{
	sf::Text& text = rom.getTextSprite();
	float width = theme.getRom_selection_indicator_width();
	float height = text.getLocalBounds().height + 2 * theme.getRom_selection_indicator_horizontal_margin();
	if(width == -1)
	{
		width = text.getLocalBounds().width + 2 * theme.getRom_selection_indicator_vertical_margin();
	}
	selectedRomIndicator.setSize(sf::Vector2f(width, height));
	centerElement(selectedRomIndicator);
}

void MameUIsenWindow::displaySelectedRomIndicator()
{
	draw(selectedRomIndicator);
}

void MameUIsenWindow::updateRomsNamesDisplay(const int currentRomIndex)
{
	romNameView = getDefaultView();
	int offset = (currentRomIndex - 1) * (theme.getRom_name_size() + theme.getRom_name_margin_size());
	romNameView.move(0, offset);
}

void MameUIsenWindow::displayRomsNames(const RomList& romList, int currentRomIndex)
{
	int aboveLimit = currentRomIndex - theme.getRom_name_to_display_above_selected();
	int underLimit = theme.getRom_name_to_display_under_selected() + currentRomIndex;

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
	int x = theme.getRom_name_selected_x();
	int y = theme.getRom_name_selected_y();

	Rom* rom = romList.getRom(1);
	for(int i = 1; i <= (int)romList.getRomListSize(); i++, rom = romList.getRom(i))
	{
		rom->getTextSprite().setPosition(x,y);
		y += theme.getRom_name_size() + theme.getRom_name_margin_size();
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
	sprite.setOrigin(fr.left + fr.width/2.0f, fr.top + fr.height/2.0f);
}

void MameUIsenWindow::centerElement(sf::Text& text)
{
	sf::FloatRect fr = text.getLocalBounds();
	text.setOrigin(fr.left + fr.width/2.0f, fr.top + fr.height/2.0f);
}

void MameUIsenWindow::centerElement(sf::RectangleShape& rectangleShape)
{
	sf::FloatRect fr = rectangleShape.getLocalBounds();
	rectangleShape.setOrigin(fr.left + fr.width/2.0f, fr.top + fr.height/2.0f);
}