#ifndef ITEM_H
#define ITEM_H
class Item
{
public:
	Item(int Heal, int Dam, int Eva);
	Item();
	~Item();

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
};
#endif // ITEM_H