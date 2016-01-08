#include <iostream>
#include "MameUIsenWindow.h"
#include "Configuration/BasicRomConfigurationCreator.h"

using namespace std;

int main()
{
	ecfra::ConfigDirectiveToFunctionBase::setStringForBoolTrue("yes");
	ecfra::ConfigDirectiveToFunctionBase::setStringForBoolFalse("no");

	BasicRomConfigurationCreator basicRomConfigurationCreator("../config/general.cfg");
	basicRomConfigurationCreator.createCategoriesAndGamesConfiguration("../config/Catlist.ini");

	MameUIsenWindow isenWindow;
	isenWindow.launch();

	return 0;
}