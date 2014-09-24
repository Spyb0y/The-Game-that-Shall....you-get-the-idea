#pragma once
#include "Equipment.h"
#include "Enemy.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
	//array of level 1 equipment
	std::vector<Equipment*> EquipLv1;
	//array of level 2 equipment
	std::vector<Equipment*> EquipLv2;
	//array of level 3 equipment
	std::vector<Equipment*> EquipLv3;
	//array of level 4 equipment
	std::vector<Equipment*> EquipLv4;
	//array of level 5 equipment
	std::vector<Equipment*> EquipLv5;
	//array to hold boss iterm
	//first item is stalkers item
	//second item is minotaurs item
	//third item is Stone guardians item
	//fourth item is Gargoyles item
	//fifth item is Hornet Queen's item
	//sixth item is Rad Dragon's item
	std::vector<Equipment*> BossItems;
	void createItemArrays();
	Equipment* SelectItem(int);
};

