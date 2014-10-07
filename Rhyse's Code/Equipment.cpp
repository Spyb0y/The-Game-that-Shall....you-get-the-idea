#include "Equipment.h"
#include <vector>
Equipment::Equipment(int Hp, int Eva, int Atk, int Def, int Spe, int size, bool IsWeapon, bool IsArmor, bool IsAccessory)
	{
		HP = Hp;
		Evasion = Eva;
		Attack = Atk;
		Defence = Def;
		Speed = Spe;
		Size = size;
		isWeapon = IsWeapon;
		isArmor = IsArmor;
		isAccessory = IsAccessory;
	}

	Equipment::Equipment()
	{
		HP = 0;
		Attack = 0;
		Evasion = 0;
		Speed = 0;
		Defence = 0;
		Size = 0;
		isArmor = false;
		isWeapon = false;
		isAccessory = false;
	}

	Equipment::~Equipment()
	{

	}
	
