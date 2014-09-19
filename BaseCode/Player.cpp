#include "Player.h"
#include "Equipment.h"



Player::~Player(void)
{
}

Player::Player(unsigned Speed, int Health, unsigned Damage, unsigned Evade, unsigned Defense, const unsigned MaxAccessorySlots, const unsigned MaxArmourSlots, unsigned MaxWeaponSlots)
{
	
}

void Player::GetEquipment(Equipment* newItem)
{
	if (newItem->isArmor)
	{
		armourInventory.push_back(newItem);
		AddPlayerStats(newItem);
		if (armourInventory.size >= maxArmourSlots)
		{
			//ask player to remove an item
			DeletePlayerStats(/*removeditem*/);
		}
	}
	if (newItem->isWeapon)
	{
		weaponInventory.push_back(newItem);
		AddPlayerStats(newItem);
		if (armourInventory.size >= maxAccessorySlots)
		{
			//ask player to remove an item
			DeletePlayerStats(/*removeditem*/);
		}
	}
	if (newItem->isAccessory)
	{
		accessoryInventory.push_back(newItem);
		AddPlayerStats(newItem);
		if (armourInventory.size >= maxAccessorySlots)
		{
			//ask player to remove an item
			DeletePlayerStats(/*removeditem*/);
		}
	}
}

void Player::AddPlayerStats(Equipment* newItem)
{
	//need player
	mPlayer.Speed = mPlayer.Speed + newItem->Speed;
	mPlayer.Health = mPlayer.Health + newItem->HP;
	mPlayer.Damage = mPlayer.Damage + newItem->Attack;
	mPlayer.Evade = mPlayer.Evade + newItem->Evasion;
	mPlayer.Defense = mPlayer.Defense + newItem->Defence;
}

void Player::DeletePlayerStats(Equipment* newItem)
{
	//need player
	mPlayer.Speed = mPlayer.Speed - newItem->Speed;
	mPlayer.Health = mPlayer.Health - newItem->HP;
	mPlayer.Damage = mPlayer.Damage - newItem->Attack;
	mPlayer.Evade = mPlayer.Evade - newItem->Evasion;
	mPlayer.Defense = mPlayer.Defense - newItem->Defence;
}
//when item is gained
//GetEpuipment();