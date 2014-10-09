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
std::stringstream Player::DisplayEquip()
{
	std::stringstream ss;
	int i = 0;
	while (i < weaponInventory.size())
	{
		ss << "items you have in your inventory: /n";
		if (weaponInventory[i]->GetItemType() == Equipment::Type::_Bow)
		{
			ss << "1 bow /n";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_ShortSword)
		{
			ss << "1 short sword /n";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_Axe)
		{
			ss << "1 axe /n";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_Spear)
		{
			ss << "1 spear /n";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_GreatSword)
		{
			ss << "1 great sword /n";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_Revolver)
		{
			ss << "1 Revolver /n";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_WhiteSword)
		{
			ss << "1 white sword /n";
		}
		else
		{
			ss << "error";
		}
		++i;
	}
	i = 0;
	while (i < armourInventory.size())
	{
		if (armourInventory[i]->GetItemType() == Equipment::Type::_Shield)
		{
			ss << "1 Shield /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_SteelShield)
		{
			ss << "1 steel shield /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_BulwarkOfAges)
		{
			ss << "1 bulwark of ages /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_Leather)
		{
			ss << "1 leather armour /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_Chainmail)
		{
			ss << "1 chainmail /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_PegasusBoots)
		{
			ss << "1 pegasus boots /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_BarbarianArmour)
		{
			ss << "1 barbarian armour /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_HeavyPlate)
		{
			ss << "1 heavy platemail /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_PaladinGloves)
		{
			ss << "1 paladin gloves /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_SpartanHelmet)
		{
			ss << "1 spartan helmet... because THIS IS SPARTA!@!!!! /n";
		}
		else
		{
			ss << "error";
		}
		++i;
	}
	i = 0;
	while (i < accessoryInventory.size())
	{
		if (armourInventory[i]->GetItemType() == Equipment::Type::_GhostRing)
		{
			ss << "1 ghost ring, you have an extra hand, sorta /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_InvisRing)
		{
			ss << "1 invis ring, now you can blend into the night /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_MonkeyGrip)
		{
			ss << "1 monkey grip, with this two handed weapons become one handed /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_SilverRing)
		{
			ss << "1 silver ring, ohhh shiny /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_GoldRing)
		{
			ss << "1 gold ring, this ones even shinier then the silver ring /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_JewelBracelet)
		{
			ss << "1 jewel ring, its covered in pretty sparkles /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_BlueBraclet)
		{
			ss << "1 blue bracelet, this give you the strenght of 1 and a half elves /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_RedBraclet)
		{
			ss << "1 red bracelet, with this you are as powerful as 10 biscits /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_SilverBracelet)
		{
			ss << "1 silver bracelet, like the silver ring, but a bracelet  /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_GoldBracelet)
		{
			ss << "1 gold bracelet, super shiny wrist accessory /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_JewelBracelet)
		{
			ss << "1 jeweled bracelet, you think some of the jewels are fake though /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_StalkersScythe)
		{
			ss << "The stalkers scythe, you can feel an ominous presnece when wielding it /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_GreatAxe)
		{
			ss << "The minutaur's great axe, smaller then you thought it would be/n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_MaceOfAges)
		{
			ss << "the mace of ages, torn from the stone guardians body /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_WingedPlatemail)
		{
			ss << "winged platemail, crafted from the severed wings of the gargoyle /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_DaggerOfDeception)
		{
			ss << "The Dagger of deception, forged from the stinger of the hornet queen /n";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_KeyOfVictory)
		{
			ss << "wait a minute... how are you even looking at this? /n";
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

