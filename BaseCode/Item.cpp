#include "Item.h"

class Item
{
public:
	int heal = 0;
	int dam = 0;
	int eva = 0;

	Item(int Heal, int Dam, int Eva)
	{
		heal = Heal;
		dam = Dam;
		eva = Eva;
	}

	Item()
	{
		heal = 0;
		dam = 0;
		eva = 0;
	}

	~Item()
	{

	}

	public function useHealItem()
	{
		player.hp += heal;
		//remove potion
	}

	public function useDamItem()
	{
		enemy.hp -= dam;
		//remove damage item
	}

	public function maiden()
	{
		player.maxHP += 5;
		//remove maiden
	}

	public function useDodgeItem()
	{
		player.eva += eva;
		//remove flaggon of mead
	}
	//functions to create all the items
		//potions of healing
		public function makePotionSE()
		{
			new Item = potionSe;
			evaPot.dam = 0;
			evaPot.heal = 5;
			evaPot.eva = 0;
		}
	
		public function makePotionME()
		{
			new Item = potionMe;
			evaPot.dam = 0;
			evaPot.heal = 10;
			evaPot.eva = 0;
		}

		public function makePotionL()
		{
			new Item = potionL;
			evaPot.dam = 0;
			evaPot.heal = 15;
			evaPot.eva = 0;
		}

		public function makePotionSP()
		{
			new Item = potionSP;
			evaPot.dam = 0;
			evaPot.heal = 10;
			evaPot.eva = 0;
		}

		public function makeBloodR()
		{
			new Item = bloodOfTheRighteous;
			evaPot.dam = 0;
			evaPot.heal = 35;
			evaPot.eva = 0;
		}

		public function makePotionUL()
		{
			new Item = potionUL;
			evaPot.dam = 0;
			evaPot.heal = 50;
			evaPot.eva = 0;
		}
		// damage items
		public function makeFireball()
		{
			new Item = fireball;
			evaPot.dam = 5;
			evaPot.heal = 0;
			evaPot.eva = 0;
		}

		public function makeBloodD()
		{
			new Item = BloodOTD;
			evaPot.dam = 10;
			evaPot.heal = 0;
			evaPot.eva = 0;
		}

		//other items
		public function makeFlaggon
		{
			new Item = Mead;
			evaPot.dam = 0;
			evaPot.heal = 0;
			evaPot.eva = 5;
		}

		public function makeMaiden()
		{
			new Item = maiden;	
		}
}