#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
	enum Type
	{
		_Potion = 1,
		_MPotion,
		_FireBall,
		_LPotion,
		_Flaggon,
		_Maiden,
		_SPPotion,
		_BloodR,
		_UPPotion,
		_BloodD
	};

public:
	Item(int Heal, int Dam, int Eva, Type type);
	Item();
	~Item();

	Item::Type GetItemType();
	int GetItemHeal();
	int GetItemDamage();
	int GetItemEvade();

	void useHealItem();
	void useDamItem();
	void useDodgeItem();
	void maiden();
	void makePotionSE();
	void makePotionME();
	void makePotionL();
	void makePotionSP();
	void makeBloodR();
	void makePotionUL();
	void makeFireball();
	void makeBloodD();
	void makeFlaggon();
	void makeMaiden();

private:

	int heal = 0;
	int dam = 0;
	int eva = 0;
	Type iType;

};
#endif // ITEM_H