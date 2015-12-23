//
// Created by joseph on 15/11/15.
//

#ifndef MAMEUISEN_ROM_H
#define MAMEUISEN_ROM_H

#include <string>
#include <SFML/Graphics.hpp>

class Rom
{
private:
	std::string description;
	std::string filename;
	std::string manufacturer;
	std::string year;
	sf::Texture texture;
	sf::Text textSprite;
	bool isTextureCorrectlyLoaded = false;


public:
	//Constructor
	Rom(const std::string& description="", const std::string& filename="", const std::string& manufacturer="", const std::string year="")
			: description(description), filename(filename), manufacturer(manufacturer), year(year), texture(), textSprite()
	{}

	//Getters
	const std::string& getDescription() const
	{
		return description;
	}

	const std::string& getFilename() const
	{
		return filename;
	}

	const std::string& getManufacturer() const
	{
		return manufacturer;
	}

	const std::string getYear() const
	{
		return year;
	}

	sf::Texture& getTexture() const
	{
		return (sf::Texture&) texture;
	}

	sf::Text& getTextSprite() const
	{
		return (sf::Text&) textSprite;
	}

	bool isIsTextureCorrectlyLoaded() const
	{
		return isTextureCorrectlyLoaded;
	}

	//Setter
	void setIsTextureCorrectlyLoaded(bool isTextureCorrectlyLoaded)
	{
		Rom::isTextureCorrectlyLoaded = isTextureCorrectlyLoaded;
	}
};


#endif //MAMEUISEN_ROM_H