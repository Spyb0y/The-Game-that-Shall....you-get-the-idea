#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <vector>
class Equipment
{
public:
	enum Type
	{
		_Bow = 1,
		_ShortSword,
		_Axe,
		_Spear,
		_GreatSword,
		_Revolver,
		_WhiteSword,
		_Shield,
		_SteelShield,
		_BulwarkOfAges,
		_Leather,
		_Chainmail,
		_SteelArmour,
		_PegasusBoots,
		_BarbarianArmour,
		_HeavyPlate,
		_PaladinGloves,
		_SpartanHelmet,
		_GhostRing,
		_InvisRing,
		_MonkeyGrip,
		_SilverRing,
		_GoldRing,
		_JewelRing,
		_BlueBraclet,
		_RedBraclet,
		_SilverBracelet,
		_GoldBracelet,
		_JewelBracelet,
		_StalkersScythe,
		_GreatAxe,
		_MaceOfAges,
		_WingedPlatemail,
		_DaggerOfDeception,
		_KeyOfVictory
	};
public:
	Equipment(int Hp, int Eva, int Atk, int Def, int Spe, int size, bool IsWeapon, bool IsArmor, bool IsAccessory, Type type);
	Equipment();
	~Equipment();

	Equipment::Type GetItemType();

	 int HP;
	 int Evasion;
	 int Attack;
	 int Speed;
	 int Defence;
	 int Size;
	 bool isArmor;
	 bool isWeapon;
	 bool isAccessory;

private:
	Type iType;
};
#endif // EQUIPMENT_H