#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}


Equipment* Inventory::SelectEquip(int i)
{
	if (i == 1)
	{
		int equip;
		equip = rand() % EquipLv1.size();
		return EquipLv1[equip];
	}
	if (i == 2)
	{
		int equip;
		equip = rand() % EquipLv2.size();
		return EquipLv2[equip];
	}
	if (i == 3)
	{
		int equip;
		equip = rand() % EquipLv3.size();
		return EquipLv3[equip];
	}
	if (i == 4)
	{
		int equip;
		equip = rand() % EquipLv4.size();
		return EquipLv4[equip];
	}
	if (i == 5)
	{
		int equip;
		equip = rand() % EquipLv5.size();
		return EquipLv5[equip];
	}
}

Item* Inventory::SelectItem(int i)
{
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

	Equipment* StalkersScythe = new Equipment(0, 0, 66, 0, 1, 2, true, false, false);
	BossEquip.push_back(StalkersScythe);

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
	Item* LPotion = new Item(15, 0, 0);
	ItemsLv3.push_back(LPotion);

	Item* Flaggon = new Item(0, 0, 5);
	ItemsLv3.push_back(Flaggon);

	Item* Maiden = new Item(0, 0, 0);
	ItemsLv3.push_back(Maiden);
	 
	//Level 4 consumable Vector
	Item* SPPotion = new Item(30, 0, 0);
	ItemsLv4.push_back(SPPotion);

	Item* BloodR = new Item(35, 0, 0);
	ItemsLv4.push_back(BloodR);

	//level 5 consumable Vector
	Item* UPPotion = new Item(50, 0, 0);
	ItemsLv5.push_back(UPPotion);

	Item* BloodD = new Item(0, 10, 0);
	ItemsLv5.push_back(BloodD);
}

void Inventory::CreateEnemyVectors()
{
	//create the pointers to the enemies
	Enemy* Rat = new Rat() : MAX_HIT(20), MIN_HIT(0);
	Enemy* Peasant = new Peasant) : MAX_HIT(20), MIN_HIT(0);
	Enemy* ArmouredPhesant = new ArmouredPhesant() : MAX_HIT(25), MIN_HIT(5);
	Enemy* GiantRat = new GiantRat() : MAX_HIT(5), MIN_HIT(5);
	Enemy* WarHound = new WarHound() ::MAX_HIT(20), MIN_HIT(8);
	Enemy* GiantBeetle = new GiantBeetle() : MAX_HIT(20), MIN_HIT(0);
	Enemy* GiantWasp = new GiantWasp() : MAX_HIT(25), MIN_HIT(8);
	Enemy* StoneGolem = new StoneGolem() : MAX_HIT(15), MIN_HIT(5);
	Enemy* Gorgon = new Gorgon() : MAX_HIT(40), MIN_HIT(4);
	Enemy* GiantEagle = new GiantEagle() : MAX_HIT(20), MIN_HIT(6);
	Enemy* Troll = new Troll : MAX_HIT(30), MIN_HIT(5); 
	Enemy* Crocodile = new Crocodile() : MAX_HIT(25), MIN_HIT(6);
	Enemy* DeviousPenguin = new DeviousPenguin(): MAX_HIT(10), MIN_HIT(1);
	Enemy* Basilisk = new Basilisk() : MAX_HIT(15), MIN_HIT(5); 
	Enemy* Ogre = new Ogre() : MAX_HIT(30), MIN_HIT(6);
	Enemy* Dragon = new Dragon() : MAX_HIT(30), MIN_HIT(6);
	Enemy* TheKing’sRoyalGuard = new TheKing’sRoyalGuard() : MAX_HIT(30), MIN_HIT(3);

	//boss monster pointers

	Enemy* Minotaur = new Minotaur() : MAX_HIT(25), MIN_HIT(1); // boss 1
	Enemy* StoneGuardian = new StoneGuardian() : MAX_HIT(30), MIN_HIT(1);//boss 2
	Enemy* Gargoyle = new Gargoyle() : MAX_HIT(50), MIN_HIT(1);//boss 3
	Enemy* HornetQueen = new HornetQueen() : MAX_HIT(50), MIN_HIT(5);//boss 4
	Enemy* RadDragon = new RadDragon() : MAX_HIT(80), MIN_HIT(10);//boss 5
	Enemy* Stalker = new Stalker() : MAX_HIT(110), MIN_HIT(30);//boss 6
	//push the pointers into the correct arrays
	//castle vector
	CastleEnemies.push_back(Rat);
	CastleEnemies.push_back(Peasant);
	CastleEnemies.push_back(ArmouredPhesant);
	CastleEnemies.push_back(GiantRat);
	CastleEnemies.push_back(WarHound);
	CastleEnemies.push_back(GiantEagle);
	CastleEnemies.push_back(TheKing’sRoyalGuard);
	CastleEnemies.push_back(DeviousPenguin);
	//forest vector
	ForestEnemies.push_back(Rat);
	ForestEnemies.push_back(GiantRat);
	ForestEnemies.push_back(WarHound);
	ForestEnemies.push_back(GiantBeetle);
	ForestEnemies.push_back(GiantWasp);
	ForestEnemies.push_back(Troll);
	ForestEnemies.push_back(GiantEagle);
	ForestEnemies.push_back(Ogre);
	
	//mountain vector
	MountainEnemies.push_back(StoneGolem);
	MountainEnemies.push_back(GiantEagle);
	MountainEnemies.push_back(Troll);
	MountainEnemies.push_back(Basilisk);
	MountainEnemies.push_back(Ogre);
	MountainEnemies.push_back(Dragon);
	MountainEnemies.push_back(DeviousPenguin);

	//swamp vector
	SwampEnemies.push_back(GiantRat);
	SwampEnemies.push_back(Gorgon);
	SwampEnemies.push_back(Troll);
	SwampEnemies.push_back(Crocodile);
	SwampEnemies.push_back(Basilisk);
	SwampEnemies.push_back(DeviousPenguin);

	//boss vector
	//first element is minotaur
	BossEnemies.push_back(Minotaur);
	//second element is stone guardian
	BossEnemies.push_back(StoneGuardian);
	//third element is gargoyle
	BossEnemies.push_back(Gargoyle);
	//fourth element is queen hornet
	BossEnemies.push_back(QueenHornet);
	//fifth elemnt is rad dragon
	BossEnemies.push_back(RadDragon);
	//sixth element is stalker
	BossEnemies.push_back(Stalker);
}

















