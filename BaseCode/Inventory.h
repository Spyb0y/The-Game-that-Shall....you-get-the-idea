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
	//first item is minotaurs item
	//second item is Stone guardians item
	//third item is Gargoyles item
	//fourth item is Hornet Queen's item
	//fifthitem is Rad Dragon's item
	//sixth  item is stalkers item
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
	//first element is minotaur
	//second element is stone guardian
	//third element is gargoyle
	//fourth element is queen hornet
	//fifth elemnt is rad dragon
	//sixth element is stalker
	void CreateEnemyVectors;
};

