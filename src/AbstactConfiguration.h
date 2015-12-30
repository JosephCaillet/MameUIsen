//
// Created by joseph on 30/12/15.
//

#ifndef MAMEUISEN_ABSTACTCONFIGURATION_H
#define MAMEUISEN_ABSTACTCONFIGURATION_H

#define COMMENT_CHARACTER '#'

#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include "ConfigDirectiveToFunction.h"

template<class T>
class AbstactConfiguration
{
protected:
	std::vector<ConfigDirectiveToFunction<T>> directiveToFunction;
	std::string configFilePath;

public:
	AbstactConfiguration(const std::string& configFilePath) : configFilePath(configFilePath)
	{ }

	const std::string& getConfigFilePath() const
	{
		return configFilePath;
	}

	void setConfigFilePath(const std::string& configFilePath)
	{
		AbstactConfiguration::configFilePath = configFilePath;
	}

protected:
	virtual void bindDirectivesToSetters() =0;

public:
	void loadConfiguration(T* subClass)
	{
		std::ifstream confFile(configFilePath, std::ios::in);
		if(!confFile)
		{
			std::cerr << "Can't open " << configFilePath << " : " << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			std::string line;
			int numLine = 0;
			while(getline(confFile, line))
			{
				numLine++;
				if(line[0] != COMMENT_CHARACTER)
				{
					for(auto & dtf : directiveToFunction)
					{
						size_t pos = line.find(dtf.getDirective());
						if(pos == 0)
						{
							try
							{
								dtf.callSetter(subClass, line.substr(pos + dtf.getDirective().length() + 1));
							}
							catch(const std::exception& exception)
							{
								std::cerr << "Incorrect value for directive " << dtf.getDirective() << " line " << numLine << ". Default value will be used.\t";
								std::cerr << "Exeption message is: " << exception.what() << std::endl;
							}
							break;
						}
					}
				}
			}
		}
	}
};


#endif //MAMEUISEN_ABSTACTCONFIGURATION_H
