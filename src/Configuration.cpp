//
// Created by joseph on 20/12/15.
//

#include <fstream>
#include <iostream>
#include <string.h>

#include "Configuration.h"

using namespace std;

Configuration::Configuration()
{
	directiveToFunction[0] = ConfigDirectiveToFunction("MAME_PATH", &Configuration::setMame_path);
	directiveToFunction[1] = ConfigDirectiveToFunction("ROMS_PATH", &Configuration::setRom_path);
	directiveToFunction[2] = ConfigDirectiveToFunction("SCREENSHOTS_PATH", &Configuration::setScreenshots_path);
	directiveToFunction[3] = ConfigDirectiveToFunction("WINDOW_WIDTH", &Configuration::setWindowWidth);
	directiveToFunction[4] = ConfigDirectiveToFunction("WINDOW_HEIGHT", &Configuration::setWindowHeight);
	loadConf();
}

void Configuration::loadConf()
{
	ifstream confFile("../config/general.cfg", ios::in);
	if(!confFile)
	{
		cerr << "Can't open config/general.cfg : " << strerror(errno) << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		string line;

		while(getline(confFile, line))
		{
			if(line[0] != '#')
			{
				for(auto & dtf : directiveToFunction)
				{
					size_t pos = line.find(dtf.getDirective());
					if(pos != string::npos)
					{
						(this->*dtf.getSetter()) (line.substr(pos + dtf.getDirective().length()));
					}
				}
			}
		}
	}
}