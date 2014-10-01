#pragma once
//PlayerTile only needs to have a visual representation on the screen
#include "Tile.h"
class PlayerTile :
	public Tile
{

public:
	PlayerTile(FXMVECTOR pos, FXMVECTOR scale, unsigned short frameWidth, unsigned short frameHeight, float depth, const std::vector<Frame*>& frames, float frameRate, ID3D11Device* device)
		:Tile(pos, scale, frameWidth, frameHeight, depth, frames, frameRate, device)
	{

	}
	~PlayerTile();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	int GetCurrRow()
	{
		return curRow;
	}

	int GetCurrCol()
	{
		return curCol;
	}

private:
	int curCol;
	int curRow;

};

