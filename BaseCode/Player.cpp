#include <vector>
#include "Player.h"
#include "Sprite.h"
#include "Enemy.h"
#include "Equipment.h"


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
	return mHealth;
}

void Player::SetPlayerHealth(int PlayerHealth)
{
	mHealth = PlayerHealth;
}

int Player::GetPlayerEvade()
{
	return mEvade;
}

//testCode
int Player::GetPlayerAttack()
{
	return mDamage;
}


void Player::GetEquipment(Player* mHero, Equipment* newItem)
{
	if (newItem->isArmor)
	{
		armourInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		//if (armourInventory.size >= mMaxArmourSlots)
		//{
			//ask player to remove an item
		//	DeletePlayerStats(/*removeditem*/);
		//	delete armourInventory[/*removeditem*/];
		//}
	}
	if (newItem->isWeapon)
	{
		weaponInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		//if (armourInventory.size >= mMaxAccessorySlots)
		//{
			//ask player to remove an item
		//	DeletePlayerStats(/*removeditem*/);
		//	delete weaponInventory[/*removeditem*/];
		//}
	}
	if (newItem->isAccessory)
	{
		accessoryInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		//if (armourInventory.size >= mMaxAccessorySlots)
		//{
			//ask player to remove an item
		//	DeletePlayerStats(/*removeditem*/);
		//	delete accessoryInventory[/*removeditem*/];
		//}
	}
}

void Player::AddPlayerStats(Player* mHero, Equipment* newItem)
{
	//need player
	//mHero->mSpeed = mPlayer.mSpeed + newItem->Speed;
	//mPlayer.mHealth = mPlayer.mHealth + newItem->HP;
	mHero->mDamage = mHero->mDamage + newItem->Attack;
	//mPlayer.mEvade = mPlayer.mEvade + newItem->Evasion;
	//mPlayer.mDefense = mPlayer.mDefense + newItem->Defence;
}

void Player::DeletePlayerStats(Equipment* newItem)
{
	//need player
	//mPlayer.mSpeed = mPlayer.mSpeed - newItem->Speed;
	//mPlayer.mHealth = mPlayer.mHealth - newItem->HP;
	//mPlayer.mDamage = mPlayer.mDamage - newItem->Attack;
	//mPlayer.mEvade = mPlayer.mEvade - newItem->Evasion;
	//mPlayer.mDefense = mPlayer.mDefense - newItem->Defence;
}


//when item is gained
//GetEpuipment();

