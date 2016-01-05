//
// Created by joseph on 31/12/15.
//

#ifndef MAMEUISEN_CONFIGDIRECTIVETOFUNCTIONBASE_H
#define MAMEUISEN_CONFIGDIRECTIVETOFUNCTIONBASE_H

#include <string>

namespace ecfra
{
	class ConfigDirectiveToFunctionBase
	{
	protected:
		static std::string stringForBoolTrue;
		static std::string stringForBoolFalse;

	public:
		static const std::string& getStringForBoolTrue()
		{
			return stringForBoolTrue;
		}

		static void setStringForBoolTrue(const std::string& stringForBoolTrue)
		{
			ConfigDirectiveToFunctionBase::stringForBoolTrue = stringForBoolTrue;
		}

		static const std::string& getStringForBoolFalse()
		{
			return stringForBoolFalse;
		}

		static void setStringForBoolFalse(const std::string& stringForBoolFalse)
		{
			ConfigDirectiveToFunctionBase::stringForBoolFalse = stringForBoolFalse;
		}
	};
}

#endif //MAMEUISEN_CONFIGDIRECTIVETOFUNCTIONBASE_H
