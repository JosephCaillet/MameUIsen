#include <iostream>
#include "RomListManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	RomListManager romListManager;

	int choice = 0;
	RomList romList = romListManager.getNextRomList();

	//Choosing category
	while(choice != -42)
	{
		cout << "Category : " << romList.getName() << "(" << romListManager.getCurrentRomSetIndex() << "/" << romListManager.getRomSetNumber() << ")" << endl;
		cout << "Categories menu :\n";
		cout << "\t -1 : previous category\n";
		cout << "\t +1 : next category\n";
		cout << "\t  0 : choose category\n";
		cout << "\t-42 : exit\n";
		cout << "Your choice : ";
		cin >> choice;

		switch(choice)
		{
			case -1:
			{
				romList = romListManager.getPreviousRomList();
				break;
			}
			case 1:
			{
				romList = romListManager.getNextRomList();
				break;
			}
			case 0:
			{
				//Choosing rom
				while(choice != -10)
				{
					cout << "\nRoms in category " << romList.getName() << " :\n";
					for(unsigned int i = 0; i < romList.getRomListSize(); i++)
					{
						Rom* rom = romList.getRom(i);
						cout << "\t" << i + 1 << "/" << romList.getRomListSize() << " : " << rom->getDescription() << endl;
					}

					cout << "Roms menu (" << romList.getName() << "):\n";
					cout << "\tNumber from 1 to " << romList.getRomListSize() << " : select a rom\n";
					cout << "\t-10 : go back to category menu\n";
					cout << "\t-42 : exit\n";
					cout << "Your choice : ";
					cin >> choice;

					//Viewing rom details and launch mame whit it
					switch(choice)
					{
						case -42:
						{
							return 0;
						}
						case -10:
							break;
						default:
						{
							if(choice > 0 && choice <= (int) romList.getRomListSize())
							{
								Rom* rom = romList.getRom(choice-1);
								cout << "\tYou are about to play : " << rom->getDescription();
								cout << ", realised in " << rom->getYear() << " by " << rom->getManufacturer() << "." << endl;

								cout << "Launch this rom ? (1 means yes, anything else means no) : ";
								cin >> choice;

								if(choice == 1)
								{
									string cmd("mame -rompath ../roms ");
									cmd += rom->getFilename();
									system(cmd.c_str());
								}
							}
							else
							{
								cout << choice;
								cout << "Incorect input.\n";
							}
						}
					}
				}
				break;
			}
			case -42:
			{
				break;
			}
			default:
			{
				cout << "Incorect input.\n";
			}
		}
	}

	return 0;
}