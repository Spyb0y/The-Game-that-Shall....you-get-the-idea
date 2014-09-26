#include "Tile.h"
#include "InClassProj.h"
#include "State.h"



void Tile::MoveRight()
{
	curCol + 1;
}

void Tile::MoveLeft()
{
	curCol - 1;
}

void Tile::MoveUp()
{
	curRow - 1;
}

void Tile::MoveDown()
{
	curRow + 1;
}
