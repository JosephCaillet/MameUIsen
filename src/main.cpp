#include <iostream>
#include "MameUIsenWindow.h"
#include "Configuration/BasicRomConfigurationCreator.h"

using namespace std;

int main()
{
	ConfigDirectiveToFunctionBase::setStringForBoolTrue("yes");
	ConfigDirectiveToFunctionBase::setStringForBoolFalse("no");

	BasicRomConfigurationCreator basicRomConfigurationCreator("../config/general.cfg");
	basicRomConfigurationCreator.listsRoms();

	//MameUIsenWindow isenWindow;
	//isenWindow.launch();

	return 0;
}