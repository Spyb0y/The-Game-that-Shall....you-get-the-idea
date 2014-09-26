#include "Item.h"

int heal = 0;
int dam = 0;
int eva = 0;

	Item::Item(int Heal, int Dam, int Eva)
	{
		heal = Heal;
		dam = Dam;
		eva = Eva;
	}

	Item::Item()
	{
		heal = 0;
		dam = 0;
		eva = 0;
	}

	Item::~Item()
	{

	}

	/*void Item::useHealItem()
	{
		player.hp += heal;
		//remove potion
	}

	void Item::useDamItem()
	{
		enemy.hp -= dam;
		//remove damage item
	}

	void Item::maiden()
	{
		player.maxHP += 5;
		//remove maiden
	}

	void Item::useDodgeItem()
	{
		player.eva += eva;
		//remove flaggon of mead
	}
	//functions to create all the items
		//potions of healing
		void Item::makePotionSE()
		{
			new Item = potionSe;
			evaPot.dam = 0;
			evaPot.heal = 5;
			evaPot.eva = 0;
		}
	
		void Item::makePotionME()
		{
			new Item = potionMe;
			evaPot.dam = 0;
			evaPot.heal = 10;
			evaPot.eva = 0;
		}

		void Item::makePotionL()
		{
			new Item = potionL;
			evaPot.dam = 0;
			evaPot.heal = 15;
			evaPot.eva = 0;
		}

		void Item::makePotionSP()
		{
			new Item = potionSP;
			evaPot.dam = 0;
			evaPot.heal = 10;
			evaPot.eva = 0;
		}

		void Item::makeBloodR()
		{
			new Item = bloodOfTheRighteous;
			evaPot.dam = 0;
			evaPot.heal = 35;
			evaPot.eva = 0;
		}

		void Item::makePotionUL()
		{
			new Item = potionUL;
			evaPot.dam = 0;
			evaPot.heal = 50;
			evaPot.eva = 0;
		}
		// damage items
		void Item::makeFireball()
		{
			new Item = fireball;
			evaPot.dam = 5;
			evaPot.heal = 0;
			evaPot.eva = 0;
		}

		void Item::makeBloodD()
		{
			new Item = BloodOTD;
			evaPot.dam = 10;
			evaPot.heal = 0;
			evaPot.eva = 0;
		}

		//other items
		void Item::makeFlaggon()
		{
			Mead = new Item();
			evaPot.dam = 0;
			evaPot.heal = 0;
			evaPot.eva = 5;
		}

		void Item::makeMaiden()
		{
			new Item = maiden;	
		}
}*/