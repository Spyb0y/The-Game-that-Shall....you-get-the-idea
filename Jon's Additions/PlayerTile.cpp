#include "PlayerTile.h"



void PlayerTile::MoveUp()
{
	curRow -= 1;
}

void PlayerTile::MoveDown()
{
	curRow += 1;
}

void PlayerTile::MoveLeft()
{
	curCol -= 1;
}

void PlayerTile::MoveRight()
{
	curCol += 1;
}