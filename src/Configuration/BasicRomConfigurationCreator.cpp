//
// Created by joseph on 02/01/16.
//

#include <dirent.h>
#include "BasicRomConfigurationCreator.h"

using namespace std;

BasicRomConfigurationCreator::BasicRomConfigurationCreator(const std::string configFilePath) : configuration(configFilePath)
{ }

void BasicRomConfigurationCreator::listRoms()
{
	DIR* romDir = nullptr;
	romDir = opendir(configuration.getRom_path().c_str());

	if(romDir == nullptr)
	{
		cerr << "Can't open \"" << configuration.getRom_path() << "\" : " << strerror(errno) << std::endl;
	}

	dirent* currentRomFile = nullptr;

	while((currentRomFile = readdir(romDir)) != nullptr)
	{
		string romDirName(currentRomFile->d_name);
		if(romDirName != "." && romDirName != "..")
		{
			size_t pos = romDirName.find(".zip");
			if(pos != string::npos)
			{
				romDirName.erase(pos);
			}
			cout << romDirName << endl;
		}
	}

	closedir(romDir);
}
