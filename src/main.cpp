#include <iostream>
#include "RomListManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	RomListManager romListManager;
	for(int i = 0; i < romListManager.getRomSetNumber(); i++)
	{
		RomList romList = romListManager.getNextRomList();
		cout << "Category : " << romList.getName() << "(" << romListManager.getCurrentRomSetIndex() << "/" << romListManager.getRomSetNumber() << ")" << endl;

		for(unsigned int j=0; j < romList.getRomListSize(); j++)
		{
			Rom* rom = romList.getRom(j);
			cout << "\tRom : " << rom->getDescription() << " - (" << j+1 << "/" << romList.getRomListSize() << ")";
			cout << "\tRealised in " << rom->getYear() << " by " << rom->getManufacturer() << endl;
		}
	}
	return 0;
}