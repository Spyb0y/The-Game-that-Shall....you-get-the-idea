#pragma once
#include <ctime>
#include "Equipment.h"
#include "Item.h"
#include "Inventory.h"
#include "Enemy.h"

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
	unsigned GetPlayerDefense();
	int GetPlayerAttack();

	std::stringstream DisplayItems();

	void GetEquipment(Player* mHero, Equipment* newItem);
	void GetItem(Item* newItem);
	void UseItem(int i, Player* mHero);
	void ResetStats(int i, Player* mHero);
	void DeleteItem(int i);

};

