#pragma once
#include "Equipment.h"

class Enemy;

class Player
{
protected:
	unsigned mSpeed;
	int mHealth;
	unsigned mDamage;
	unsigned mEvade;
	unsigned mDefense;
	unsigned mMaxAccessorySlots;
	unsigned mMaxArmourSlots;
	unsigned mMaxWeaponSlots;


	//void GetEquipment(Equipment* newItem);
	//void AddPlayerStats(Equipment* newItem);
	//void DeletePlayerStats(Equipment* newItem);
	
public:
	//std::vector<Equipment*> armourInventory;
	//std::vector<Equipment*> weaponInventory;
	//std::vector<Equipment*> accessoryInventory;


	Player();

	~Player(void);

	void Update(float dt);

	void Attack(Enemy*);

	int GetPlayerHealth();
	void SetPlayerHealth(int);

};

