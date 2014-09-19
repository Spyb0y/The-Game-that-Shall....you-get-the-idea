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
	 //array of level 1 equipment
	 std::vector<Equipment*> EquipLv1;
	 //array of level 2 equipment
	 std::vector<Equipment*> EquipLv2;
	 //array of level 3 equipment
	 std::vector<Equipment*> EquipLv3;
	 //array of level 4 equipment
	 std::vector<Equipment*> EquipLv4;
	 //array of level 5 equipment
	 std::vector<Equipment*> EquipLv5;
	 //array to hold boss iterm
	 //first item is stalkers item
	 //second item is minotaurs item
	 //third item is Stone guardians item
	 //fourth item is Gargoyles item
	 //fifth item is Hornet Queen's item
	 //sixth item is Rad Dragon's item
	 std::vector<Equipment*> BossItems;
	 void createItemArrays();
};
#endif // EQUIPMENT_H