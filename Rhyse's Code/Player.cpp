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

unsigned Player::GetPlayerDefense()
{
	return mDefense;
}

int Player::GetPlayerAttack()
{
	return mDamage;
}

unsigned Player::GetMaxArmourSlots()
{
	return mMaxArmourSlots;
}

unsigned Player::GetMaxWeaponSlots()
{
	return mMaxWeaponSlots;
}

unsigned Player::GetMaxAccessorySlots()
{
	return mMaxAccessorySlots;
}

std::stringstream Player::DisplayItems()
{
	std::stringstream ss;                        //21 + 22 = 43 for font rasterizer
	int i = 0;
	while (i < playerHand.size())
	{
		if (playerHand[i]->GetItemType() == Item::Type::_Potion)
		{
			ss << "Select " << i << " to use your Small Health Potion   ";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_MPotion)
		{
			ss << "Select " << i << " to use your Medium Health Potion  ";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_FireBall)
		{
			ss << "Select " << i << " to use your Fireball              ";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_LPotion)
		{
			ss << "Select " << i << " to use your Large Health Potion   ";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_Flaggon)
		{
			ss << "Select " << i << " to use your Flagon of Mead        ";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_Maiden)
		{
			ss << "Select " << i << " to use your Voluptuous Maiden     ";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_SPPotion)
		{
			ss << "Select " << i << " to use your Super Health Potion   ";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_BloodR)
		{
			ss << "Select " << i << " to use your Blood of the Righteous";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_UPPotion)
		{
			ss << "Select " << i << " to use your Ultra Health Potion   ";
		}
		else if (playerHand[i]->GetItemType() == Item::Type::_BloodD)
		{
			ss << "Select " << i << " to use your Blood of the Damned   ";
		}
		else
		{
			ss << "error";
		}
		++i;
	}
	return ss;
}

std::stringstream Player::DisplayArmourEquip()
{
	std::stringstream ss;                        //25 + 16 = 41 for font rasterizer
	int i = 0;
	while (i < armourInventory.size())
	{
		if (armourInventory[i]->GetItemType() == Equipment::Type::_Leather)
		{
			ss << "Select " << i << " to destroy your Leather         ";
			ss << "Attack: " << armourInventory[i]->Attack << "                               ";
			ss << "Defence: " << armourInventory[i]->Defence << "                               ";
			ss << "Evade: " << armourInventory[i]->Evasion << "                                 ";
			ss << "                                         ";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_Chainmail)
		{
			ss << "Select " << i << " to destroy your Chainmail        ";
			ss << "Attack: " << armourInventory[i]->Attack << "                               ";
			ss << "Defence: " << armourInventory[i]->Defence << "                               ";
			ss << "Evade: " << armourInventory[i]->Evasion << "                                 ";
			ss << "                                         ";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_PegasusBoots)
		{
			ss << "Select " << i << " to destroy your Pegasus Boots   ";
			ss << "Attack: " << armourInventory[i]->Attack << "                               ";
			ss << "Defence: " << armourInventory[i]->Defence << "                               ";
			ss << "Evade: " << armourInventory[i]->Evasion << "                                ";
			ss << "                                         ";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_BarbarianArmour)
		{
			ss << "Select " << i << " to destroy your Barbarian Armour";
			ss << "Attack: " << armourInventory[i]->Attack << "                               ";
			ss << "Defence: " << armourInventory[i]->Defence << "                               ";
			ss << "Evade: " << armourInventory[i]->Evasion << "                                 ";
			ss << "                                         ";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_HeavyPlate)
		{
			ss << "Select " << i << " to destroy your Heavy Plate     ";
			ss << "Attack: " << armourInventory[i]->Attack << "                               ";
			ss << "Defence: " << armourInventory[i]->Defence << "                               ";
			ss << "Evade: " << armourInventory[i]->Evasion << "                                 ";
			ss << "                                         ";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_PaladinGloves)
		{
			ss << "Select " << i << " to destroy your Paladin Gloves  ";
			ss << "Attack: " << armourInventory[i]->Attack << "                               ";
			ss << "Defence: " << armourInventory[i]->Defence << "                               ";
			ss << "Evade: " << armourInventory[i]->Evasion << "                                 ";
			ss << "                                         ";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_SpartanHelmet)
		{
			ss << "Select " << i << " to destroy your Spartan Helmet  ";
			ss << "Attack: " << armourInventory[i]->Attack << "                               ";
			ss << "Defence: " << armourInventory[i]->Defence << "                               ";
			ss << "Evade: " << armourInventory[i]->Evasion << "                                 ";
			ss << "                                         ";
		}
		else if (armourInventory[i]->GetItemType() == Equipment::Type::_WingedPlatemail)
		{
			ss << "Select " << i << " to destroy your Winged Platemail";
			ss << "Attack: " << armourInventory[i]->Attack << "                               ";
			ss << "Defence: " << armourInventory[i]->Defence << "                              ";
			ss << "Evade: " << armourInventory[i]->Evasion << "                                 ";
			ss << "                                         ";
		}
		else
		{
			ss << "error";
		}
		++i;
	}
	return ss;
}

std::stringstream Player::DisplayWeaponEquip()
{
	std::stringstream ss;                        //25 + 19 = 44 for font rasterizer
	int i = 0;
	while (i < weaponInventory.size())
	{
		if (weaponInventory[i]->GetItemType() == Equipment::Type::_Bow)
		{
			ss << "Select " << i << " to destroy your Bow                ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                   ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_ShortSword)
		{
			ss << "Select " << i << " to destroy your Short Sword        ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                   ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_Axe)
		{
			ss << "Select " << i << " to destroy your Axe                ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                   ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_Spear)
		{
			ss << "Select " << i << " to destroy your Spear              ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                  ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_GreatSword)
		{
			ss << "Select " << i << " to destroy your Great Sword        ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                  ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_Revolver)
		{
			ss << "Select " << i << " to destroy your Revolver           ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                  ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_WhiteSword)
		{
			ss << "Select " << i << " to destroy your White Sword        ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                  ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_Shield)
		{
			ss << "Select " << i << " to destroy your Shield             ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                   ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_SteelShield)
		{
			ss << "Select " << i << " to destroy your Steel Shield       ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                   ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_BulwarkOfAges)
		{
			ss << "Select " << i << " to destroy your Bulwark of Ages ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                   ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_StalkersScythe)
		{
			ss << "Select " << i << " to destroy your Stalker's Scythe   ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                  ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_GreatAxe)
		{
			ss << "Select " << i << " to destroy your Great Axe          ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                  ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_MaceOfAges)
		{
			ss << "Select " << i << " to destroy your Mace of Ages       ";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                  ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_DaggerOfDeception)
		{
			ss << "Select " << i << " to destroy your Dagger of Deception";
			ss << "Attack: " << weaponInventory[i]->Attack << "                                  ";
			ss << "Defence: " << weaponInventory[i]->Defence << "                                  ";
			ss << "Evade: " << weaponInventory[i]->Evasion << "                                    ";
			ss << "                                            ";
		}
		else
		{
			ss << "error";
		}
		++i;
	}
	return ss;
}

std::stringstream Player::DisplayAccessoryEquip()
{
	std::stringstream ss;                        //25 + 15 = 40 for font rasterizer
	int i = 0;
	while (i < accessoryInventory.size())
	{
		if (accessoryInventory[i]->GetItemType() == Equipment::Type::_GhostRing)
		{
			ss << "Select " << i << " to destroy your Ghost Ring     ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_InvisRing)
		{
			ss << "Select " << i << " to destroy your Ivisiblity Ring";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_MonkeyGrip)
		{
			ss << "Select " << i << " to destroy your Monkey Grip    ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_SilverRing)
		{
			ss << "Select " << i << " to destroy your Silver Ring    ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_GoldRing)
		{
			ss << "Select " << i << " to destroy your Gold Ring      ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_JewelBracelet)
		{
			ss << "Select " << i << " to destroy your Jewel Bracelet ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_BlueBraclet)
		{
			ss << "Select " << i << " to destroy your Blue Bracelet  ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_RedBraclet)
		{
			ss << "Select " << i << " to destroy your Red Bracelet   ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_SilverBracelet)
		{
			ss << "Select " << i << " to destroy your Silver Bracelet";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_GoldBracelet)
		{
			ss << "Select " << i << " to destroy your Gold Bracelet  ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_JewelBracelet)
		{
			ss << "Select " << i << " to destroy your Jewel Bracelet ";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_KeyOfVictory)
		{
			ss << "Select " << i << " to destroy your Keys of Victory";
			ss << "Attack: " << accessoryInventory[i]->Attack << "                               ";
			ss << "Defence: " << accessoryInventory[i]->Defence << "                              ";
			ss << "Evade: " << accessoryInventory[i]->Evasion << "                                ";
			ss << "                                        ";
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
		else if (weaponInventory[i]->GetItemType() == Equipment::Type::_Shield)
		{
			ss << "1 Shield /n";
		}
		else
		{
			ss << "error";
		}
		++i;
	}
	while (i < armourInventory.size())
	{
		if (armourInventory[i]->GetItemType() == Equipment::Type::_SteelShield)
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
	while (i < accessoryInventory.size())
	{
		if (accessoryInventory[i]->GetItemType() == Equipment::Type::_GhostRing)
		{
			ss << "1 ghost ring, you have an extra hand, sorta /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_InvisRing)
		{
			ss << "1 invis ring, now you can blend into the night /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_MonkeyGrip)
		{
			ss << "1 monkey grip, with this two handed weapons become one handed /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_SilverRing)
		{
			ss << "1 silver ring, ohhh shiny /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_GoldRing)
		{
			ss << "1 gold ring, this ones even shinier then the silver ring /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_JewelBracelet)
		{
			ss << "1 jewel ring, its covered in pretty sparkles /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_BlueBraclet)
		{
			ss << "1 blue bracelet, this give you the strenght of 1 and a half elves /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_RedBraclet)
		{
			ss << "1 red bracelet, with this you are as powerful as 10 biscits /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_SilverBracelet)
		{
			ss << "1 silver bracelet, like the silver ring, but a bracelet  /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_GoldBracelet)
		{
			ss << "1 gold bracelet, super shiny wrist accessory /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_JewelBracelet)
		{
			ss << "1 jeweled bracelet, you think some of the jewels are fake though /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_StalkersScythe)
		{
			ss << "The stalkers scythe, you can feel an ominous presnece when wielding it /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_GreatAxe)
		{
			ss << "The minutaur's great axe, smaller then you thought it would be/n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_MaceOfAges)
		{
			ss << "the mace of ages, torn from the stone guardians body /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_WingedPlatemail)
		{
			ss << "winged platemail, crafted from the severed wings of the gargoyle /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_DaggerOfDeception)
		{
			ss << "The Dagger of deception, forged from the stinger of the hornet queen /n";
		}
		else if (accessoryInventory[i]->GetItemType() == Equipment::Type::_KeyOfVictory)
		{
			ss << "wait a minute... how are you even looking at this? /n";
		}
		else
		{
			ss << "error";
		}
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
	if (mHero->mHealth >= 10)
	{
		mHero->mHealth = 10;
	}
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
		int j = 0;
		for (int i = 0; i < armourInventory.size(); ++i)
		{ 
			j += armourInventory[i]->Size;
		}
		if (j > mMaxArmourSlots)
		{
			//ask player to remove an item
			//DeletePlayerStats(mHero, armourInventory[armourInventory.size() - 1]);
			//delete armourInventory[armourInventory.size() - 1];
			//armourInventory.erase(armourInventory.begin() + armourInventory.size() - 1);
		}
	}
	if (newItem->isWeapon == true)
	{
		weaponInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		int j = 0;
		for (int i = 0; i < weaponInventory.size(); ++i)
		{
			j += weaponInventory[i]->Size;
		}
		if (j > mMaxWeaponSlots)
		{
			//ask player to remove an item
			//DeletePlayerStats(mHero, weaponInventory[weaponInventory.size() - 1]);
			//delete weaponInventory[weaponInventory.size() - 1];
			//weaponInventory.erase(weaponInventory.begin() + weaponInventory.size() - 1);
		}
	}
	if (newItem->isAccessory == true)
	{
		accessoryInventory.push_back(newItem);
		AddPlayerStats(mHero, newItem);
		int j = 0;
		for (int i = 0; i < accessoryInventory.size(); ++i)
		{
			j += accessoryInventory[i]->Size;
		}
		if (j > mMaxAccessorySlots)
		{
			//ask player to remove an item
			//DeletePlayerStats(mHero, accessoryInventory[accessoryInventory.size() - 1]);
			//delete accessoryInventory[accessoryInventory.size() - 1];
			//accessoryInventory.erase(accessoryInventory.begin() + accessoryInventory.size() - 1);
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