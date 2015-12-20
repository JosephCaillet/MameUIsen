//
// Created by joseph on 20/12/15.
//

#ifndef MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H
#define MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H

#include "Configuration.h"

class Configuration;

typedef void (Configuration:: * T)(const std::string&);// T represent a pointer on a getter method member of a Configuration object

class ConfigDirectiveToFunction
{
private:
	std::string directive;
	T setter;

public:

	ConfigDirectiveToFunction()
	{ }

	ConfigDirectiveToFunction(const std::string& directive, T setter) : directive(directive), setter(setter)
	{ }

	const std::string& getDirective() const
	{
		return directive;
	}

	T getSetter() const
	{
		return setter;
	}
};


#endif //MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H