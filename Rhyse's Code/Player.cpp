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

	//test code
	Item* FireBall = new Item(0, 5, 0, Item::Type::_FireBall);
	playerHand.push_back(FireBall);
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

unsigned Player::GetPlayerDefense()
{
	return mDefense;
}

//testCode
int Player::GetPlayerAttack()
{
	return mDamage;
}

std::stringstream Player::DisplayItems()
{
	std::stringstream ss;
	int i = 0;
	while (i < playerHand.size())
	{
		if (playerHand[i]->GetItemType() == Item::Type::_Potion)
		{
			ss << "Select " << i << " to use your Small Health Potion";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_MPotion)
		{
			ss << "Select " << i << " to use your Medium Health Potion";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_FireBall)
		{
			ss << "Select " << i << " to use your Fireball";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_LPotion)
		{
			ss << "Select " << i << " to use your Large Health Potion";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_Flaggon)
		{
			ss << "Select " << i << " to use your Flagon of Mead";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_Maiden)
		{
			ss << "Select " << i << " to use your Voluptuous Maiden";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_SPPotion)
		{
			ss << "Select " << i << " to use your Super Health Potion";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_BloodR)
		{
			ss << "Select " << i << " to use your Blood of the Righteous";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_UPPotion)
		{
			ss << "Select " << i << " to use your Ultra Health Potion";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_BloodD)
		{
			ss << "Select " << i << " to use your Blood of the Damned";
		}
		else
		{
			ss << "error";
		}
		++i;
	}
	return ss;
}

void Player::UseItem(int i, Player* mHero)
{
	mHero->mHealth = mHero->mHealth + playerHand[i]->GetItemHeal();
	mHero->mDamage = mHero->mDamage + playerHand[i]->GetItemDamage();
	mHero->mEvade = mHero->mEvade + playerHand[i]->GetItemEvade();
}

void Player::ResetStats(int i, Player* mHero)
{
	mHero->mHealth = mHero->mHealth - playerHand[i]->GetItemHeal();
	mHero->mDamage = mHero->mDamage - playerHand[i]->GetItemDamage();
	mHero->mEvade = mHero->mEvade - playerHand[i]->GetItemEvade();
}

void Player::DeleteItem(int i)
{
	playerHand.erase(playerHand.begin() + i);
}

void Player::GetEquipment(Player* mHero, Equipment* newItem)
{
	if (newItem->isArmor == true)
	{
		armourInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		if (armourInventory.size() > mMaxArmourSlots)
		{
			//ask player to remove an item
			DeletePlayerStats(mHero, armourInventory[armourInventory.size() - 1]);
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
			DeletePlayerStats(mHero, weaponInventory[weaponInventory.size() - 1]);
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

