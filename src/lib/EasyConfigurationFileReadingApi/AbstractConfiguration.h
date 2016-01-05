//
// Created by joseph on 30/12/15.
//

#ifndef MAMEUISEN_ABSTRACTCONFIGURATION_H
#define MAMEUISEN_ABSTRACTCONFIGURATION_H

#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include "ConfigDirectiveToFunction.h"

template<class T>
class AbstractConfiguration
{
private:
	using S = void (T::* )(const std::string&);
	using I = void (T::* )(const int);
	using F = void (T::* )(const float);
	using B = void (T::* )(const bool);

protected:
	std::vector<ConfigDirectiveToFunction<T>> directiveToFunction;
	std::string configFilePath;

public:
	AbstractConfiguration(const std::string& configFilePath) : configFilePath(configFilePath)
	{ }

	const std::string& getConfigFilePath() const
	{
		return configFilePath;
	}

	void setConfigFilePath(const std::string& configFilePath)
	{
		AbstractConfiguration::configFilePath = configFilePath;
	}

protected:
	virtual void bindDirectivesToSetters() =0;
	void bind(const std::string& directive, S setter);
	void bind(const std::string& directive, I setter);
	void bind(const std::string& directive, F setter);
	void bind(const std::string& directive, B setter);

public:
	void loadConfiguration(char commentCharacter = '#');
};

#include "AbstractConfiguration.tpp"

#endif //MAMEUISEN_ABSTRACTCONFIGURATION_H