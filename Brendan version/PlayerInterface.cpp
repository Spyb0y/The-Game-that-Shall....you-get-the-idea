#include "PlayerInterface.h"
#include "Player.h"
#include "Equipment.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

PlayerInterface::PlayerInterface()
{
}

PlayerInterface::~PlayerInterface()
{
}

int askForInt(const string& question = "Enter a number: ",
int high = INT_MAX, int low = INT_MIN);

void PlayerInterface::BattlePhase()
{
	do
	{
		string menu = "\nInventory\n-------------\n\n"
			"0 - Quit\n"
			"1 - Attack\n"
			"2 - Use Item\n"
			"3 - Flee\n"
			"Choice: ";
		choice = askForInt(menu, 3, 0);

		switch (choice)
		{
		case 0:
			cout << "Close Menu.\n";
			break;
		case 1:
			cout << "Press A to Attack:\n";
			//mTestPLayer->Attack();
			break;
		case 2:
			cout << "Use Item:\n";
			
			break;
		case 3:
			cout << "Press F to Flee:\n";
			//mTestPlayer->Flee();
			
			break;

		}
	} while (choice != 0);

	//enemy turn

	//if victory

	PostBattlePhase();

			
}

void PlayerInterface::PostBattlePhase()
{
	do
	{
		string menu = "\nBattle\n-------------\n\n"
			"0 - Quit\n"
			"1 - Items\n"
			"2 - Equipment\n"
			"Choice: ";
		choice = askForInt(menu, 2, 0);

		switch (choice)
		{
		case 0:
			cout << "Close Menu.\n";
			break;
		case 1:
			cout << "Use Items:\n";
			break;
		case 2:
			cout << "Equipment:\n";
			/*for (int i = 0; i < EquipLv1.size(); ++i)
			{
				cout << EquipLv1[i] << endl;
				//select item
				//remove selected from vector
				if (Equip)
				{
					delete EquipLv1[i];
					EquipLv1.remove(EquipLv1.begin() + i);
					i--;
				}
			}
			for (int i = 0; i < EquipLv2.size(); ++i)
			{
				cout << EquipLv2[i] << endl;
				//select item
				//remove selected from vector
			}
			for (int i = 0; i < EquipLv3.size(); ++i)
			{
				cout << EquipLv3[i] << endl;
				//select item
				//remove selected from vector
			}

			for (int i = 0; i < EquipLv4.size(); ++i)
			{
				cout << EquipLv4[i] << endl;
				//select item
				//remove selected from vector
			}
			for (int i = 0; i < EquipLv5.size(); ++i)
			{
				cout << EquipLv5[i] << endl;
				//select item
				//remove selected from vector
			}*/
			break;
		
		}
	} while (choice != 0);
}

void PlayerInterface::PlaceTile()
{
	cout << "Place a tile." << endl;
}


int askForInt(const std::string& question, int high, int low)
{
	int ret;
	do
	{
		std::cout << question;
		std::string str;
		std::getline(std::cin, str);
		std::stringstream ss(str);
		ss >> ret;
		if ((ss) && (ret >= low && ret <= high))
		{
			break;
		}
		else
		{
			std::cout << "Try Again." << std::endl;
			continue;
		}

	} while (true);
	return ret;
}

