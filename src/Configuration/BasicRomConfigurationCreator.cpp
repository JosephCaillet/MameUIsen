//
// Created by joseph on 02/01/16.
//

#include <dirent.h>
#include "BasicRomConfigurationCreator.h"

using namespace std;

BasicRomConfigurationCreator::BasicRomConfigurationCreator(const std::string configFilePath) : configuration(configFilePath)
{ }

void BasicRomConfigurationCreator::listsRoms()
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

				cout << romDirName << " found."<< endl;
			}
		}
	}

	closedir(romDir);
}

void BasicRomConfigurationCreator::askMameForRomsXMLFile()
{
	string s = configuration.getMame_path() + " -listxml > " + XML_ROM_LIST_MAME;
	system(s.c_str());
}

void BasicRomConfigurationCreator::deleteMameRomsXMLFile()
{
	remove(XML_ROM_LIST_MAME);
}

void BasicRomConfigurationCreator::parseXML()
{

}