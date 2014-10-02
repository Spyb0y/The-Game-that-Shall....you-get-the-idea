#pragma once
#include <vector>
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
	//vector to hold boss items
	//first item is stalkers item
	//second item is minotaurs item
	//third item is Stone guardians item
	//fourth item is Gargoyles item
	//fifth item is Hornet Queen's item
	//sixth item is Rad Dragon's item
	
	std::vector<Equipment*> BossEquip;
	void createItemVectors();
	Equipment* SelectEquip(int);
	//level 1 item vector
	std::vector<Item*> ItemsLv1;
	//level 2 item vector
	std::vector<Item*> ItemsLv2;
	//level 3 item vector
	std::vector<Item*> ItemsLv3;
	//level 4 item vector
	std::vector<Item*> ItemsLv4;
	//level 5 item vector
	std::vector<Item*> ItemsLv5;
	Item* SelectItem(int);

	//create enemy vectors
	//castle enemies
	std::vector<Enemy*> CastleEnemies;
	//forest enemies
	std::vector<Enemy*> ForestEnemies;
	//mountain enemies
	std::vector<Enemy*> MountainEnemies;
	//swamp enemies
	std::vector<Enemy*> SwampEnemies;
	//boss enemies
	std::vector<Enemy*> BossEnemies;
	//first element is stalker
	//second element is minotaur
	//third element is stone guardian
	//fourth element is gargoyle
	//fifth element is queen hornet
	//sixth elemnt is rad dragon
	void CreateEnemyVectors;

	int GetForestSize();
	int GetCastleSize();
	int GetSwampSize();
	int GetMountainSize();
};

