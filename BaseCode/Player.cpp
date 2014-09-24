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
	if (newItem->isArmor == true)
	{
		armourInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		if (armourInventory.size() + 1 > mMaxArmourSlots)
		{
			//ask player to remove an item
			//DeletePlayerStats(mHero, armourInventory[0]);
			delete armourInventory[armourInventory.size() - 1];
		}
	}
	if (newItem->isWeapon == true)
	{
		weaponInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		if (weaponInventory.size() + 1 > mMaxWeaponSlots)
		{
			//ask player to remove an item
			//DeletePlayerStats(mHero, weaponInventory[0]);
			delete weaponInventory[weaponInventory.size() - 1];
		}
	}
	if (newItem->isAccessory == true)
	{
		accessoryInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		if (accessoryInventory.size() + 1 > mMaxAccessorySlots)
		{
			//ask player to remove an item
			//DeletePlayerStats(mHero, accessoryInventory[0]);
			delete accessoryInventory[accessoryInventory.size() - 1];
		}
	}
}

void Player::GetItem(Item* newItem)
{
	playerHand.push_back(newItem);
	if (playerHand.size() + 1 > 5)
	{
		//ask player to choose an item
		delete playerHand[playerHand.size() - 1];
	}
}

void Player::AddPlayerStats(Player* mHero, Equipment* newItem)
{
	mHero->mSpeed = mHero->mSpeed + newItem->Speed;
	mHero->mHealth = mHero->mHealth + newItem->HP;
	mHero->mDamage = mHero->mDamage + newItem->Attack;
	mHero->mEvade = mHero->mEvade + newItem->Evasion;
	mHero->mDefense = mHero->mDefense + newItem->Defence;
}

void Player::DeletePlayerStats(Player* mHero, Equipment* newItem)
{
	mHero->mSpeed = mHero->mSpeed - newItem->Speed;
	mHero->mHealth = mHero->mHealth - newItem->HP;
	mHero->mDamage = mHero->mDamage - newItem->Attack;
	mHero->mEvade = mHero->mEvade - newItem->Evasion;
	mHero->mDefense = mHero->mDefense - newItem->Defence;
}


//when item is gained
//GetEpuipment();

