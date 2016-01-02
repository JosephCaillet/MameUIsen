//
// Created by joseph on 02/01/16.
//

#ifndef MAMEUISEN_BASICROMCONFIGURATIONCREATOR_H
#define MAMEUISEN_BASICROMCONFIGURATIONCREATOR_H

#include <vector>
#include "Configuration.h"

typedef struct dirent dirent;

class BasicRomConfigurationCreator
{
private:
	Configuration configuration;
	std::vector<std::string> romNameList;

public:
	BasicRomConfigurationCreator(const std::string);
	void listRoms();
};


#endif //MAMEUISEN_BASICROMCONFIGURATIONCREATOR_H
