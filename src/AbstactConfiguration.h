//
// Created by joseph on 30/12/15.
//

#ifndef MAMEUISEN_ABSTACTCONFIGURATION_H
#define MAMEUISEN_ABSTACTCONFIGURATION_H

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
	void loadConfiguration(T* subClass, char commentCharacter = '#');
};

#include "AbstactConfiguration.tpp"

#endif //MAMEUISEN_ABSTACTCONFIGURATION_H