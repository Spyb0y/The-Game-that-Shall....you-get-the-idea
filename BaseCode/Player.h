#pragma once
#include <vector>

class Player
{
private:
	unsigned speed = 1;
	int health = 10;
	unsigned damage = 2;
	unsigned evade = 5;
	unsigned defense = 0;
	unsigned maxAccessorySlots = 1;
	unsigned maxArmourSlots = 2;
	unsigned maxWeaponSlots = 2;


	void GetEquipment(Equipment* newItem);
	void AddPlayerStats(Equipment* newItem);
	void DeletePlayerStats(Equipment* newItem);
	
public:
	std::vector<Equipment*> armourInventory;
	std::vector<Equipment*> weaponInventory;
	std::vector<Equipment*> accessoryInventory;

	Player(void)
	{}

	Player(unsigned Speed, int Health, unsigned Damage, unsigned Evade, unsigned Defense, const unsigned MaxAccessorySlots, const unsigned MaxArmourSlots, unsigned MaxWeaponSlots)
	{
	}

	~Player(void);

};

