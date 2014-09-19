#include Equipment.h

class Equipment
{
	Equipment(int Hp, int Eva, int Atk, int Def, int Spe, int size)
	{
		HP = Hp;
		Attack = Atk;
		Evasion = Eva;
		Speed = Spe;
		Defence = Def;
		Size = size;
		isArmor = false;
		isWeapon = false;
		isAccessory = false;
	}

	~Equipment()
	{

	}

	//array to hold level 1 equipment
	Equipment[] EquipLv1 = new array();
	//array to hold level 2 equipment
	Equipment[] EquipLv2 = new array();
	//array to hol level 3 equipment
	Equipment[] EquipLv3 = new array();
	//array to hol level 4 equipment
	Equipment[] EquipLv4 = new array();
	//array to hol level 5 equipment
	Equipment[] EquipLv5 = new array();

	//array to hold boss iterm
	//first item is stalkers item
	//second item is minotaurs item
	//third item is Stone guardians item
	//fourth item is Gargoyles item
	//fifth item is Hornet Queen's item
	//sixth item is Rad Dragon's item
	Equipment[] BossItems = new Array();
	
	//weapons
	Bow = new Equipment(0, 2, 0, 0, 0, 2);
	Bow.isWeapon = true;
	EquipLv1[].push(bow);

	ShortSword = new Equipment(0, 2, 0, 0, 0, 1);
	ShortSword.isWeapon = true;
	equipmentLv1[].push(ShortSword);

	Axe = new Equipment(0, 5, 0, 0, 0, 1);
	Axe.isWeapon = true;
	EquipLv2[].push(Axe);

	Spear = new Equipment(0, 10, 0, 0, 0, 2);
	Spear.isWeapon = true;
	EquipLv3[].push(Spear);

	GreatSword = new Equipment(0, 15, 0, 0, 0, 2);
	GreatSword.isWeapon = true;
	EquipLv4[].push(GreatSword);

	Revolver = new Equipment(0, 20, 0, 0, 0, 1);
	Revolver.isWeapon = true;
	EquipLv5[].push(Revolver);

	WhiteSword = new Equipment(0, 10, 5, 0, 0, 1);
	WhiteSword.isWeapon = true;
	EquipLv3[].push(WhiteSword);

	Shield = new Equipment(0, 0, 0, 0, 1, 1);
	Sheild.isWeapon = true;
	EquipLv1[].push(Shield);

	SteelShield = new Equipment(0, 0, 0, 0, 1, 1);
	SteelSheild.isWeapon = true;
	EquipLv1[].push(SteelShield);

	BulwarkOfAges = new Equipment(0, 0, 0, 0, 5, 1);
	BulwarkOfAges.isWeapon = true;
	EquipLv5[].push(BulwarkOfAges);

	//armour
	Leather = new Equipment(0, 0, 0, 1, 0, 1);
	Leather.isArmor = true;
	EquipLv1[].push(Leather);

	Chainmail = new Equipment(0, 0, 0, 2, 0, 1);
	Chainmail.isArmor = true;
	EquipLv2[].push(Chainmail);

	SteelArmour = new Equipment(0, 0, 0, 3, 0, 1);
	SteelArmour.isArmor = true;
	EquipLv3[].push(SteelArmour);

	PegasusBoots = new Equipment(0, 10, 0, 0, 0, 1);
	PegsusBoots.isArmor = true;
	EquipLv3[].push(PegasusBoots);

	BarbarianArmour = new Equipment(0, 0, 1, 3, 0, 1);
	BarbarianArmous.isArmor = true;
	EquipLv4[].push(BarbarianArmour);

	HeavyPlate = new Equipment(0, 0, 0, 8, 0, 2);
	HeavyPlate.isArmor = true;
	EquipLv5[].push(HeavyPlate);

	PaladinGloves = new Equipment(5, 0, 0, 0, 0, 1);
	PaladinGloves.isArmor = true;
	EquipLv5[].push(PaladinGloves);

	SpartanHelmet = new Equipment(0, 0, 3, 2, 0, 1);
	SpartanHelmet.isArmor = true;
	EquipLv5[].push(SpartanHelmet);

	//Accesories
	GhostRing = new Equipment(0, 0, 0, 0, 0, 1);
	GhostRing.isAccessory = true;
	EquipLv5[].push(GhostRing);

	InvisRing = new Equipment(0, 0, 0, 0, 0, 1);
	InvisRing.isAccessory = true;
	EquipLv3[].push(InvisRing);

	MonkeyGrip = new Equipment(0, 0, 0, 0, 0, 1);
	MonkeyGrip.isAccessory = true;
	EquipLv3.push(MonkeyGrip);

	SilverRing = new Equipment(0, 0, 0, 0, 0, 1);
	SilverRing.isAccessory = true;
	EquipLv1[].push(SilverRing);

	GoldRing = new Equipment(0, 0, 0, 0, 0, 1);
	GoldRing.isAccessory = true;
	EquipLv1[].push(GoldRing);

	JewelRing = new Equipment(0, 0, 0, 0, 0, 1);
	JewelRing.isAccessory = true;
	EquipLv3[].push(JewelRing);

	BlueBraclet = new Equipment(0, 9, 0, 0, 0, 1);
	BlueBraclet.isAccessory = true;
	EquipLv4[].push(BlueBraclet);

	RBraclet = new Equipment(0, 2, 0, 0, 0, 1);
	RBraclet.isAccessory = true;
	EquipLv1[].push(RBraclet);

	SilverBracelet = new Equipment(0, 0, 0, 0, 0, 1);
	SilverBracelet.isAccessory = true;
	EquipLv1[].push(SilverBracelet);

	GoldBracelet = new Equipment(0, 0, 0, 0, 0, 1);
	GoldBracelet.isAccessory = true;
	EquipLv1[].push(GoldBracelet);

	JewelBracelet = new Equipment(0, 0, 0, 0, 0, 1);
	JewelBracelet.isAccessory = true;
	EquipLv3[].push(JewelBracelet);

	//boss items
	StalkersScythe = new Equipment(0, 0, 66, 1, 0, 2);
	StalkersScythe.isWeapon = true;
	BossItems[].push(StalkersScythe);

	GreatAxe = new Equipment(0, 0, 15, 0, 0, 2);
	GreatAxe.isWeapon = true;
	BossItems[].push(GreatAxe);
	
	MaceOfAges = new Equipment(0, 0, 15, 0, 5, 2);
	MaceOfAges.isWeapon = true;
	BossItems[].push(MaceOfAges);

	WingedPlateMail = new Equipment(0, 0, 0, 1, 10, 1);
	WingedPlaceMail.isArmor = true;
	BossItems[].push(WingedPlateMail);

	DaggerOfDeception = new Equipment(0, 0, 15, 1, 5, 1);
	DaggerOfDeception.isWeapon = true;
	BossItems[].push(DaggerOfDeception);

	KeyOfVictory = new Equipment(0, 0, 0, 0, 0, 0);
	KeyOfVictory.isAccessory = true;
	BossItems[].push(KeyOfVictory);
};