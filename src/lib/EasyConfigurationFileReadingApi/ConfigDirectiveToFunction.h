//
// Created by joseph on 20/12/15.
//

#ifndef MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H
#define MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H


#include <stdexcept>
#include <sstream>

#include "ConfigDirectiveToFunctionBase.h"

template <class T>
class ConfigDirectiveToFunction : ConfigDirectiveToFunctionBase
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

	void callSetter(T* target, std::string value);

	const std::string& getDirective() const
	{
		return directive;
	}
};

#include "ConfigDirectiveToFunction.tpp"

#endif //MAMEUISEN_CONFIGDIRECTIVETOFUNCTION_H