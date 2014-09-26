#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <vector>
class Equipment
{
public:
	Equipment(int Hp, int Eva, int Atk, int Def, int Spe, int size, bool IsWeapon, bool IsArmor, bool IsAccessory);
	Equipment();
	~Equipment();
	 int HP;
	 int Evasion;
	 int Attack;
	 int Speed;
	 int Defence;
	 int Size;
	 bool isArmor;
	 bool isWeapon;
	 bool isAccessory;

};
#endif // EQUIPMENT_H