#pragma once
#include "Equipment.h"
#include "Item.h"

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
	unsigned mMaxHandSize;


	void AddPlayerStats(Player* mHero, Equipment* newItem);
	void DeletePlayerStats(Player* mHero, Equipment* newItem);
	
public:
	std::vector<Equipment*> armourInventory;
	std::vector<Equipment*> weaponInventory;
	std::vector<Equipment*> accessoryInventory;
	std::vector<Item*> playerHand;


	Player();

	~Player(void);

	void Update(float dt);

	void Attack(Enemy*);

	int GetPlayerHealth();
	void SetPlayerHealth(int);
	int GetPlayerEvade();

	//test code
	int GetPlayerAttack();

	void GetEquipment(Player* mHero, Equipment* newItem);
	void GetItem(Item* newItem);

};

