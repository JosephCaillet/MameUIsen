//
// Created by joseph on 31/12/15.
//

#include "AbstractConfiguration.h"

template<class T>
void ConfigDirectiveToFunction<T>::callSetter(T* target, std::string value)
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
			if(value == stringForBoolTrue)
			{
				(target->*setterB)(true);
			}
			else if(value == stringForBoolFalse)
			{
				(target->*setterB)(false);
			}
			else
			{
				std::stringstream error_msg;
				error_msg << "Cannot convert \"" << value << "\" to boolean, is neither " << stringForBoolTrue <<"(true) or " << stringForBoolFalse << "(false).";
				throw std::invalid_argument(error_msg.str());
			}
			break;
	}
}