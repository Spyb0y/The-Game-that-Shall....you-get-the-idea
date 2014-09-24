#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}


Equipment* Inventory::SelectItem(int i)
{
	if (i == 1)
	{
		int item;
		item = rand() % EquipLv1.size();
		return EquipLv1[item];
	}
	if (i == 2)
	{
		int item;
		item = rand() % EquipLv2.size();
		return EquipLv2[item];
	}
	if (i == 3)
	{
		int item;
		item = rand() % EquipLv3.size();
		return EquipLv3[item];
	}
	if (i == 4)
	{
		int item;
		item = rand() % EquipLv4.size();
		return EquipLv4[item];
	}
	if (i == 5)
	{
		int item;
		item = rand() % EquipLv5.size();
		return EquipLv5[item];
	}
}

void Inventory::createItemVectors()
{
	///////////////////////////////////////int Hp, int Eva, int Atk, int Def, int Spe, int size, bool IsWeapon, bool IsArmor, bool IsAccessory
	//weapons
	Equipment* Bow = new Equipment(0, 0, 2, 0, 0, 2, true, false, false);
	EquipLv1.push_back(Bow);

	Equipment* ShortSword = new Equipment(0, 0, 2, 0, 0, 1, true, false, false);
	EquipLv1.push_back(ShortSword);

	Equipment* Axe = new Equipment(0, 0, 5, 0, 0, 1, true, false, false);
	EquipLv2.push_back(Axe);

	Equipment* Spear = new Equipment(0, 0, 10, 0, 0, 2, true, false, false);
	EquipLv3.push_back(Spear);

	Equipment* GreatSword = new Equipment(0, 0, 15, 0, 0, 2, true, false, false);
	EquipLv4.push_back(GreatSword);

	Equipment* Revolver = new Equipment(0, 0, 20, 0, 0, 1, true, false, false);
	EquipLv5.push_back(Revolver);

	Equipment* WhiteSword = new Equipment(0, 5, 10, 0, 0, 1, true, false, false);
	EquipLv3.push_back(WhiteSword);

	Equipment* Shield = new Equipment(0, 0, 0, 1, 0, 1, true, false, false);
	EquipLv1.push_back(Shield);

	Equipment* SteelShield = new Equipment(0, 0, 0, 1, 0, 1, true, false, false);
	EquipLv1.push_back(SteelShield);

	Equipment* BulwarkOfAges = new Equipment(0, 0, 0, 5, 0, 1, true, false, false);
	EquipLv5.push_back(BulwarkOfAges);

	//armour
	Equipment* Leather = new Equipment(0, 0, 0, 1, 0, 1, false, true, false);
	EquipLv1.push_back(Leather);

	Equipment* Chainmail = new Equipment(0, 0, 0, 2, 0, 1, false, true, false);
	EquipLv2.push_back(Chainmail);

	Equipment* SteelArmour = new Equipment(0, 0, 0, 3, 0, 1, false, true, false);
	EquipLv3.push_back(SteelArmour);

	Equipment* PegasusBoots = new Equipment(0, 10, 0, 0, 0, 1, false, true, false);
	EquipLv3.push_back(PegasusBoots);

	Equipment* BarbarianArmour = new Equipment(0, 0, 1, 3, 0, 1, false, true, false);
	EquipLv4.push_back(BarbarianArmour);

	Equipment* HeavyPlate = new Equipment(0, 0, 0, 8, 0, 2, false, true, false);
	EquipLv5.push_back(HeavyPlate);

	Equipment* PaladinGloves = new Equipment(5, 0, 0, 0, 0, 1, false, true, false);
	EquipLv5.push_back(PaladinGloves);

	Equipment* SpartanHelmet = new Equipment(0, 0, 3, 2, 0, 1, false, true, false);
	EquipLv5.push_back(SpartanHelmet);

	//Accesories
	Equipment* GhostRing = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv5.push_back(GhostRing);

	Equipment* InvisRing = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv3.push_back(InvisRing);

	Equipment* MonkeyGrip = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv3.push_back(MonkeyGrip);

	Equipment* SilverRing = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv1.push_back(SilverRing);

	Equipment* GoldRing = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv1.push_back(GoldRing);

	Equipment* JewelRing = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv3.push_back(JewelRing);

	Equipment* BlueBraclet = new Equipment(0, 0, 9, 0, 0, 1, false, false, true);
	EquipLv4.push_back(BlueBraclet);

	Equipment* RBraclet = new Equipment(0, 0, 2, 0, 0, 1, false, false, true);
	EquipLv1.push_back(RBraclet);

	Equipment* SilverBracelet = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv1.push_back(SilverBracelet);

	Equipment* GoldBracelet = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv1.push_back(GoldBracelet);

	Equipment* JewelBracelet = new Equipment(0, 0, 0, 0, 0, 1, false, false, true);
	EquipLv3.push_back(JewelBracelet);

	//boss items
	Equipment* StalkersScythe = new Equipment(0, 0, 66, 0, 1, 2, true, false, false);
	BossEquip.push_back(StalkersScythe);

	Equipment* GreatAxe = new Equipment(0, 0, 15, 0, 0, 2, true, false, false);
	BossEquip.push_back(GreatAxe);

	Equipment* MaceOfAges = new Equipment(0, 0, 15, 5, 0, 2, true, false, false);
	BossEquip.push_back(MaceOfAges);

	Equipment* WingedPlateMail = new Equipment(0, 0, 0, 10, 1, 1, false, true, false);
	BossEquip.push_back(WingedPlateMail);

	Equipment* DaggerOfDeception = new Equipment(0, 0, 15, 5, 1, 1, true, false, false);
	BossEquip.push_back(DaggerOfDeception);

	Equipment* KeyOfVictory = new Equipment(0, 0, 0, 0, 0, 0, false, false, true);
	BossEquip.push_back(KeyOfVictory);

	//consumable vectors
	//level one consumable items
	Item* Potion = new Item(5, 0, 0);
	ItemsLv1.push_back(Potion);

	//Level 2 consumable vector
	Item* MPotion = new Item(10, 0, 0);
	ItemsLv2.push_back(Potion);

	Item* FireBall = new Item(0, 5, 0);
	ItemsLv2.push_back(FireBall);

	//Level 3 consumable Vector
	Item* LPotion = new item(15, 0, 0);
	ItemsLv3.push_back(LPotion);

	Item* Flaggon = new item(0, 0, 5);
	ItemsLv3.push_back(Flaggon);

	Item* Maiden = new item(0, 0, 0);
	ItemLv3.push_back(Maiden);
	 
	//Level 4 consumable Vector
	Item* SPPotion = new item(30, 0, 0);
	ItemLv4.push_back(SPPotion);

	Item* BloodR = new Item(35, 0, 0);
	ItemLv4.push_back(BloodR);

	//level 5 consumable Vector
	Item* UPPotion = new Item(50, 0, 0);
	ItemLv5.push_back(UPPotion);

	Item* BloodD = new Item(0, 10, 0);
	ItemLv5.push_back(BloodD);
}

















