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
				//removing .zip
				romDirName.erase(pos);
				romNameList.push_back(romDirName);

				//asking mame for xml file info corresponding to the game
				string s = configuration.getMame_path() + " -listxml " + romDirName + " > " + romDirName + ".xml";
				system(s.c_str());

				//doing somme things with
				cout << romDirName << " found."<< endl;

				//delete xml file
				s = romDirName + ".xml";
				remove(s.c_str());
			}
		}
	}

	closedir(romDir);
}
