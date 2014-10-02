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
	mMaxHandSize = 5;
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
		if (armourInventory.size() > mMaxArmourSlots)
		{
			float XPosItem = 0.0f;
			//ask player to remove an item
			for (unsigned i = 0; i < armourInventory.size(); i++)
			{
				std::stringstream ss;
				ss << armourInventoy[i];
				string s = ss.str();
				mFont->DrawFont(md3dImmediateContext, XMVectorSet(x, 200.0f, 0.0f, 0.0f), 50, 50, 15, s);
				XPosItem += 10;
			}
			//DeletePlayerStats(mHero, armourInventory[armourInventory.size() - 1]);
			//delete armourInventory[armourInventory.size() - 1];
			armourInventory.erase(armourInventory.begin() + armourInventory.size() - 1);
		}
	}
	if (newItem->isWeapon == true)
	{
		weaponInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		if (weaponInventory.size() > mMaxWeaponSlots)
		{
			//ask player to remove an item
			for (unsigned i = 0; i < weaponInventory.size(); i++)
			{
				std::stringstream ss;
				ss << weaponInventoy[i];
			}
			//DeletePlayerStats(mHero, weaponInventory[weaponInventory.size() - 1]);
			//delete weaponInventory[weaponInventory.size() - 1];
			weaponInventory.erase(weaponInventory.begin() + weaponInventory.size() - 1);
		}
	}
	if (newItem->isAccessory == true)
	{
		accessoryInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		if (accessoryInventory.size() > mMaxAccessorySlots)
		{
			//ask player to remove an item
			DeletePlayerStats(mHero, accessoryInventory[accessoryInventory.size() - 1]);
			//delete accessoryInventory[accessoryInventory.size() - 1];
			accessoryInventory.erase(accessoryInventory.begin() + accessoryInventory.size() - 1);
		}
	}
}

void Player::GetItem(Item* newItem)
{
	playerHand.push_back(newItem);
	if (playerHand.size() > mMaxHandSize)
	{
		//ask player to choose an item
		//delete playerHand[playerHand.size() - 1];
		playerHand.erase(playerHand.begin() + playerHand.size() - 1);
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

