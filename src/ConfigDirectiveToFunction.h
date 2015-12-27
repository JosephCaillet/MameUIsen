//
// Created by joseph on 20/12/15.
//

#ifndef MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H
#define MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H

#define STRING_FOR_BOOL_TRUE "yes"
#define STRING_FOR_BOOL_FALSE "no"

#include <stdexcept>
#include <sstream>
#include "Configuration.h"

class Configuration;

//typedef void (Configuration:: * S)(const std::string&);// S represent a pointer on a getter method member of a Configuration object
//typedef void (Configuration:: * I)(const int&);
//typedef void (Configuration:: * F)(const float &);
//typedef void (Configuration:: * B)(const bool &);

template <class T>
class ConfigDirectiveToFunction
{
private:
	using S = void (T::* )(const std::string&);
	using I = void (T::* )(const int);
	using F = void (T::* )(const float);
	using B = void (T::* )(const bool);

	enum ValueType
	{
		STRING, INT, FLOAT, BOOL
	};

	ValueType valueType;
	std::string directive;

	union
	{
		S setterS;
		I setterI;
		F setterF;
		B setterB;
	};

public:

	ConfigDirectiveToFunction()
	{ }

	ConfigDirectiveToFunction(const std::string& directive, S setter) : valueType(ValueType::STRING), directive(directive), setterS(setter)
	{ }

	ConfigDirectiveToFunction(const std::string& directive, I setter) : valueType(ValueType::INT), directive(directive), setterI(setter)
	{ }

	ConfigDirectiveToFunction(const std::string& directive, F setter) : valueType(ValueType::FLOAT), directive(directive), setterF(setter)
	{ }

	ConfigDirectiveToFunction(const std::string& directive, B setter) : valueType(ValueType::BOOL), directive(directive), setterB(setter)
	{ }

	void callSetter(Configuration* target, std::string value)
	{
		switch(valueType)
		{
			case ValueType::STRING:
				(target->*setterS)(value);
				break;
			case ValueType::INT:
				(target->*setterI)(std::stoi(value));
				break;
			case ValueType::FLOAT:
				(target->*setterF)(std::stof(value));
				break;
			case ValueType::BOOL:
				if(value == STRING_FOR_BOOL_TRUE)
				{
					(target->*setterB)(true);
				}
				else if(value == STRING_FOR_BOOL_FALSE)
				{
					(target->*setterB)(false);
				}
				else
				{
					std::stringstream error_msg;
					error_msg << "Cannot convert \"" << value << "\" to boolean, is neither " << STRING_FOR_BOOL_TRUE <<"(true) or " << STRING_FOR_BOOL_FALSE << "(false).";
					throw std::invalid_argument(error_msg.str());
				}
				break;
		}
	}

	const std::string& getDirective() const
	{
		return directive;
	}
};


#endif //MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H