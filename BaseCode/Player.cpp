#include <vector>
#include "Player.h"
#include "Equipment.h"
#include "Sprite.h"
#include "Enemy.h"



Player::~Player(void)
{
}

Player::Player()
{
	mSpeed = 1;
	mHealth = 10;
	mDamage = 2;
	mEvade = 5;
	mDefense = 0;
	mMaxAccessorySlots = 1;
	mMaxArmourSlots = 2;
	mMaxWeaponSlots = 2;
}

void Player::Update(float dt)
{

}

void Player::Attack(Enemy* enemy)
{
	int enemyHealth = enemy->GetEnemyHealth();
	enemyHealth = enemyHealth - mDamage;
	enemy->SetEnemyHealth(enemyHealth);
}

int Player::GetPlayerHealth()
{
	int PlayerHealth = mHealth;
	return PlayerHealth;
}

void Player::SetPlayerHealth(int PlayerHealth)
{
	mHealth = PlayerHealth;
}
/*
void Player::GetEquipment(Equipment* newItem)
{
	if (newItem->isArmor)
	{
		armourInventory.push_back(newItem);
		AddPlayerStats(newItem);
		if (armourInventory.size >= mMaxArmourSlots)
		{
			//ask player to remove an item
			DeletePlayerStats(/*removeditem);
			delete armourInventory[/*removeditem];
		}
	}
	if (newItem->isWeapon)
	{
		weaponInventory.push_back(newItem);
		AddPlayerStats(newItem);
		if (armourInventory.size >= mMaxAccessorySlots)
		{
			//ask player to remove an item
			DeletePlayerStats(/*removeditem);
			delete weaponInventory[/*removeditem];
		}
	}
	if (newItem->isAccessory)
	{
		accessoryInventory.push_back(newItem);
		AddPlayerStats(newItem);
		if (armourInventory.size >= mMaxAccessorySlots)
		{
			//ask player to remove an item
			DeletePlayerStats(/*removeditem);
			delete accessoryInventory[/*removeditem];
		}
	}
}

void Player::AddPlayerStats(Equipment* newItem)
{
	//need player
	mHero->mSpeed = mPlayer.mSpeed + newItem->Speed;
	mPlayer.mHealth = mPlayer.mHealth + newItem->HP;
	mPlayer.mDamage = mPlayer.mDamage + newItem->Attack;
	mPlayer.mEvade = mPlayer.mEvade + newItem->Evasion;
	mPlayer.mDefense = mPlayer.mDefense + newItem->Defence;
}

void Player::DeletePlayerStats(Equipment* newItem)
{
	//need player
	mPlayer.mSpeed = mPlayer.mSpeed - newItem->Speed;
	mPlayer.mHealth = mPlayer.mHealth - newItem->HP;
	mPlayer.mDamage = mPlayer.mDamage - newItem->Attack;
	mPlayer.mEvade = mPlayer.mEvade - newItem->Evasion;
	mPlayer.mDefense = mPlayer.mDefense - newItem->Defence;
}*/


//when item is gained
//GetEpuipment();