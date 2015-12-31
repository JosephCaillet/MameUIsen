#include <iostream>
#include "MameUIsenWindow.h"

using namespace std;

int main()
{
	ConfigDirectiveToFunctionBase::setStringForBoolTrue("yes");
	ConfigDirectiveToFunctionBase::setStringForBoolFalse("no");

	MameUIsenWindow isenWindow;
	isenWindow.launch();

	return 0;
}