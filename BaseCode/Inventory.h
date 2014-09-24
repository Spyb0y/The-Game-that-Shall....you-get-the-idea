#pragma once
#include "Equipment.h"
#include "Item.h"
#include "Enemy.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
	//vector of level 1 equipment
	std::vector<Equipment*> EquipLv1;
	//vector of level 2 equipment
	std::vector<Equipment*> EquipLv2;
	//vector of level 3 equipment
	std::vector<Equipment*> EquipLv3;
	//vector of level 4 equipment
	std::vector<Equipment*> EquipLv4;
	//vector of level 5 equipment
	std::vector<Equipment*> EquipLv5;
	//vector to hold boss iterm
	//first item is stalkers item
	//second item is minotaurs item
	//third item is Stone guardians item
	//fourth item is Gargoyles item
	//fifth item is Hornet Queen's item
	//sixth item is Rad Dragon's item
	std::vector<Equipment*> BossEquip;
	void createItemArraysVectors();
	Equipment* SelectItem(int);
	//level 1 item vector
	std::Vector<Item*> ItemLv1;
	//level 2 item vector
	std::Vector<Item*> ItemLv2;
	//level 3 item vector
	std::Vector<Item*> ItemLv3;
	//level 4 item vector
	std::Vector<Item*> ItemLv4;
	//level 5 item vector
	std::Vector<Item*> ItemLv5;
};

