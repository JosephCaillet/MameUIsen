//
// Created by joseph on 21/12/15.
//

#ifndef MAMEUISEN_MAMEUISENWINDOW_H
#define MAMEUISEN_MAMEUISENWINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Configuration.h"
#include "RomListManager.h"

enum event
{
	NO_EVENT,
	EXIT,
	LAUNCH_ROM,
	NEXT_ROM, PREVIOUS_ROM,
	NEXT_CATEGORY, PREVIOUS_CATEGORY
};

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
	sf::RectangleShape selectedRomIndicator;
	sf::View romNameView;
	sf::Texture* backgroundImageTexture = nullptr;
	sf::Sprite backgroundImageSprite;

public:
	MameUIsenWindow();
	~MameUIsenWindow();

private:
	bool loadFontAndInitSprite();
	void launch();

	void updateAllDisplay(const RomList& romList, const Rom& rom, int currentRomIndex);
	void displayAll(const int currentRomIndex, const RomList& romList);

	void displayBackgroundImage();

	void updateCategoryDisplay(const RomList& romList);
	void displayCategory();

	void updateRomInfosDisplay(const Rom& rom, int romIndex, int romTotal);
	void displayRomInfos();

	void updateScreenshotDisplay(const Rom& rom);
	void displayScreenshot();

	void updateSelectedRomIndicator(const Rom& rom);
	void displaySelectedRomIndicator();

	void updateRomsNamesDisplay(const int currentRomIndex);
	void displayRomsNames(const RomList& romList, int currentRomIndex);
	void rebaseRomNamesPosition(RomList& romList);

	event getEvent();
	void centerElement(sf::Sprite& sprite);
	void centerElement(sf::Text& text);
	void centerElement(sf::RectangleShape& rectangleShape);
};

#endif //MAMEUISEN_MAMEUISENWINDOW_H