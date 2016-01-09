#include <iostream>
#include "MameUIsenWindow.h"
#include "Configuration/BasicRomConfigurationCreator.h"
#include "Configuration/CommandLineOptionsParser.h"

using namespace std;

int main(int argc, char** argv)
{
	ecfra::ConfigDirectiveToFunctionBase::setStringForBoolTrue("yes");
	ecfra::ConfigDirectiveToFunctionBase::setStringForBoolFalse("no");

	CommandLineOptionsParser clop(argc, argv);

	if(clop.isBuildingCategoriesAndRomsAsked())
	{
		BasicRomConfigurationCreator basicRomConfigurationCreator(clop.getConfigFilePath());
		basicRomConfigurationCreator.createCategoriesAndGamesConfiguration(clop.getLinkingCategoriesToRomFilePath());
	}
	else
	{
		MameUIsenWindow isenWindow(clop.getConfigFilePath());
		isenWindow.launch();
	}

	return 0;
}