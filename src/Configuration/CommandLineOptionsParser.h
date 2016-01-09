//
// Created by joseph on 09/01/16.
//

#ifndef MAMEUISEN_COMMANDLINEOPTIONSPARSER_H
#define MAMEUISEN_COMMANDLINEOPTIONSPARSER_H


#include <string>
#include <vector>
#include <iostream>

#define DEFAULT_CONF_FILE_PATH "../config/general.cfg"
#define DEFAULT_LINKING_CATEGORIES_TO_ROMS_FILE_PATH ""

class CommandLineOptionsParser
{
private:
	std::string configFilePath = DEFAULT_CONF_FILE_PATH;
	bool buildingCategoriesAndRomsAsked = false;
	std::string linkingCategoriesToRomFilePath = DEFAULT_LINKING_CATEGORIES_TO_ROMS_FILE_PATH;

	std::vector<std::string> optionsList;

public:
	CommandLineOptionsParser(int argc, char** argv)
	{
		for(int i=0; i<argc; i++)
		{
			optionsList.push_back(argv[i]);
		}
		parseOptions();
	}


	const std::string& getConfigFilePath() const
	{
		return configFilePath;
	}

	bool isBuildingCategoriesAndRomsAsked() const
	{
		return buildingCategoriesAndRomsAsked;
	}

	const std::string& getLinkingCategoriesToRomFilePath() const
	{
		return linkingCategoriesToRomFilePath;
	}

private:
	void parseOptions()
	{
		for(unsigned int i=1; i<optionsList.size(); i++)
		{
			if(optionsList[i] == "-cf" || optionsList[i] == "--config-file")
			{
				if(i < optionsList.size() - 1)
				{
					configFilePath = optionsList[i+1];
					i++;
				}
				else
				{
					showHelp();
				}
			}
			else if((optionsList[i] == "-b" || optionsList[i] == "--build-category-rom-config-files" ) )
			{
				buildingCategoriesAndRomsAsked = true;

				if(i < optionsList.size() - 1)
				{
					linkingCategoriesToRomFilePath = optionsList[i+1];
					i++;
				}
			}
			else
			{
				showHelp();
			}
		}
	}

	void showHelp()
	{
		using namespace std;
		cout << "MameUIsen, a Mame frontend writen by Joseph Caillet, for Club Elec, ISEN Brest." << endl << endl;
		cout << "The MIT License (MIT)\n"
				 "\n"
				 "Copyright (c) 2015 Joseph Caillet\n"
				 "\n"
				 "Permission is hereby granted, free of charge, to any person obtaining a copy "
				 "of this software and associated documentation files (the \"Software\"), to deal "
				 "in the Software without restriction, including without limitation the rights "
				 "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell "
				 "copies of the Software, and to permit persons to whom the Software is "
				 "furnished to do so, subject to the following conditions:"
				 "\n"
				 "The above copyright notice and this permission notice shall be included in all "
				 "copies or substantial portions of the Software."
				 "\n"
				 "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR "
				 "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, "
				 "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE "
				 "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
				 "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, "
				 "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE "
				 "SOFTWARE." << endl << endl;
		cout << "Usage : " << endl;
		cout << "MameUIsen [ [-h | --help] | [ [-cf | --config-file] config_file_path] [ [-b | --build-category-rom-config-files] [bindingCatRomFile] ] ]" << endl;
		cout << "See readme for more details." << endl;
		exit(EXIT_SUCCESS);
	}
};


#endif //MAMEUISEN_COMMANDLINEOPTIONSPARSER_H