//
// Created by joseph on 02/01/16.
//

#ifndef MAMEUISEN_BASICROMCONFIGURATIONCREATOR_H
#define MAMEUISEN_BASICROMCONFIGURATIONCREATOR_H

#define XML_ROM_LIST_MAME "temporary_mame_roms_info.xml"

#include <queue>
#include <set>
#include "Configuration.h"
#include "../RomManagement/Rom.h"
#include "../RomManagement/RomWithCategories.h"

typedef struct dirent dirent;

class BasicRomConfigurationCreator
{
private:
	Configuration configuration;
	std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> romsNamesList;
	std::vector<std::string> categoriesList;
	std::set<RomWithCategories> romsList;

public:
	BasicRomConfigurationCreator(const std::string);
	void listsRoms();
	void askMameForRomsXMLFile();
	void deleteMameRomsXMLFile();
	void parseXML();
	void createCategoriesAndGamesConfiguration(const std::string& catlistFilePath = "");
	void linkRomsToCategories(const std::string& catlistFilePath);
	void writeCategoriesConfig();
	void writeGamesConfig();
	void disp();
};


#endif //MAMEUISEN_BASICROMCONFIGURATIONCREATOR_H
