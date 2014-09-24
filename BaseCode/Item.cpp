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
	
