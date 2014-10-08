#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}


Equipment* Inventory::SelectEquip(int i, Enemy* enemy)
{
	bool isBoss = enemy->GetIsBoss();
	if (isBoss == true)
	{
		int l = enemy->GetEnemyLevel();
		return BossEquip[l];
	}
	srand(time(NULL));
	if (i == 1)
	{
		int equip;
		equip = rand() % EquipLv1.size();
		return EquipLv1[equip];
	}
	else if (i == 2)
	{
		int equip;
		equip = rand() % EquipLv2.size();
		return EquipLv2[equip];
	}
	else if (i == 3)
	{
		int equip;
		equip = rand() % EquipLv3.size();
		return EquipLv3[equip];
	}
	else if (i == 4)
	{
		int equip;
		equip = rand() % EquipLv4.size();
		return EquipLv4[equip];
	}
	else if (i == 5)
	{
		int equip;
		equip = rand() % EquipLv5.size();
		return EquipLv5[equip];
	}
}

Item* Inventory::SelectItem(int i)
{
	srand(time(NULL));
	if (i == 1)
	{
		int item;
		item = rand() % ItemsLv1.size();
		return ItemsLv1[item];
	}
	if (i == 2)
	{
		int item;
		item = rand() % ItemsLv2.size();
		return ItemsLv2[item];
	}
	if (i == 3)
	{
		int item;
		item = rand() % ItemsLv3.size();
		return ItemsLv3[item];
	}
	if (i == 4)
	{
		int item;
		item = rand() % ItemsLv4.size();
		return ItemsLv4[item];
	}
	if (i == 5)
	{
		int item;
		item = rand() % ItemsLv5.size();
		return ItemsLv5[item];
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
	Item* Potion = new Item(5, 0, 0, Item::Type::_Potion);
	ItemsLv1.push_back(Potion);

	//Level 2 consumable vector
	Item* MPotion = new Item(10, 0, 0, Item::Type::_MPotion);
	ItemsLv2.push_back(Potion);

	Item* FireBall = new Item(0, 5, 0, Item::Type::_FireBall);
	ItemsLv2.push_back(FireBall);

	//Level 3 consumable Vector
	Item* LPotion = new Item(15, 0, 0, Item::Type::_LPotion);
	ItemsLv3.push_back(LPotion);

	Item* Flaggon = new Item(0, 0, 5, Item::Type::_Flaggon);
	ItemsLv3.push_back(Flaggon);

	Item* Maiden = new Item(0, 0, 0, Item::Type::_Maiden);
	ItemsLv3.push_back(Maiden);
	 
	//Level 4 consumable Vector
	Item* SPPotion = new Item(30, 0, 0, Item::Type::_SPPotion);
	ItemsLv4.push_back(SPPotion);

	Item* BloodR = new Item(35, 0, 0, Item::Type::_BloodR);
	ItemsLv4.push_back(BloodR);

	//level 5 consumable Vector
	Item* UPPotion = new Item(50, 0, 0, Item::Type::_UPPotion);
	ItemsLv5.push_back(UPPotion);

	Item* BloodD = new Item(0, 10, 0, Item::Type::_BloodD);
	ItemsLv5.push_back(BloodD);
}

void Inventory::CreateEnemyVectors()
{
	//create the pointers to the enemies
	Enemy* mRat = new Rat();
	Enemy* mPheasent = new Pheasent();
	Enemy* mArmoredPhesant = new ArmoredPhesant();
	Enemy* mGiantRat = new GiantRat();
	Enemy* mWarHound = new WarHound();
	Enemy* mGiantBeetle = new GiantBeetle();
	Enemy* mGiantWasp = new GiantWasp();
	Enemy* mStoneGolem = new StoneGolem();
	Enemy* mGorgon = new Gorgon();
	Enemy* mGiantEagle = new GiantEagle();
	Enemy* mTroll = new Troll();
	Enemy* mCrocodile = new Crocodile();
	Enemy* mDeviousPenguin = new DeviousPenguin();
	Enemy* mBasilisk = new Basilisk();
	Enemy* mOgre = new Ogre();
	Enemy* mDragon = new Dragon();
	Enemy* mTheKing’sRoyalGuard = new TheKing’sRoyalGuard();

	//boss monster pointers
	
	Enemy* mMinotaur = new Minotaur(); // boss 1
	Enemy* mStoneGuardian = new StoneGuardian();//boss 2
	Enemy* mGargoyle = new Gargoyle();//boss 3
	Enemy* mHornetQueen = new HornetQueen();//boss 4
	Enemy* mRadDragon = new RadDragon();//boss 5
	Enemy* mStalker = new TheStalker();//boss 0
	

	//push the pointers into the correct arrays
	//castle vector
	CastleEnemies.push_back(mRat);
	CastleEnemies.push_back(mPheasent);
	CastleEnemies.push_back(mArmoredPhesant);
	CastleEnemies.push_back(mGiantRat);
	CastleEnemies.push_back(mWarHound);
	CastleEnemies.push_back(mGiantEagle);
	CastleEnemies.push_back(mTheKing’sRoyalGuard);
	CastleEnemies.push_back(mDeviousPenguin);

	//forest vector
	ForestEnemies.push_back(mRat);
	ForestEnemies.push_back(mGiantRat);
	ForestEnemies.push_back(mWarHound);
	ForestEnemies.push_back(mGiantBeetle);
	ForestEnemies.push_back(mGiantWasp);
	ForestEnemies.push_back(mTroll);
	ForestEnemies.push_back(mGiantEagle);
	ForestEnemies.push_back(mOgre);

	//mountain vector
	MountainEnemies.push_back(mStoneGolem);
	MountainEnemies.push_back(mGiantEagle);
	MountainEnemies.push_back(mTroll);
	MountainEnemies.push_back(mBasilisk);
	MountainEnemies.push_back(mOgre);
	MountainEnemies.push_back(mDragon);
	MountainEnemies.push_back(mDeviousPenguin);

	//swamp vector
	SwampEnemies.push_back(mGiantRat);
	SwampEnemies.push_back(mGorgon);
	SwampEnemies.push_back(mTroll);
	SwampEnemies.push_back(mCrocodile);
	SwampEnemies.push_back(mBasilisk);
	SwampEnemies.push_back(mDeviousPenguin);

	//boss vector
	//first element is stalker
	BossEnemies.push_back(mStalker);
	//second element is minotaur
	BossEnemies.push_back(mMinotaur);
	//third element is stone guardian
	BossEnemies.push_back(mStoneGuardian);
	//fourth element is gargoyle
	BossEnemies.push_back(mGargoyle);
	//fifth element is queen hornet
	BossEnemies.push_back(mHornetQueen);
	//sixth elemnt is rad dragon
	BossEnemies.push_back(mRadDragon);

}

int Inventory::GetForestSize()
{
	return ForestEnemies.size();
}

int Inventory::GetCastleSize()
{
	return CastleEnemies.size();
}

int Inventory::GetSwampSize()
{
	return SwampEnemies.size();
}

int Inventory::GetMountainSize()
{
	return MountainEnemies.size();
}

















