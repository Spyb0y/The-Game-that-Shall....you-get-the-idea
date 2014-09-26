#pragma once
#include "Sprite.h"
#include "TilePlacementState.h"
class Tile : public Sprite
{

public:
	
	
	Tile(FXMVECTOR pos, FXMVECTOR scale, unsigned short frameWidth, unsigned short frameHeight, float depth, const std::vector<Frame*>& frames, float frameRate, ID3D11Device* device)
		:Sprite(pos, scale, frameWidth, frameHeight, depth, frames, frameRate, device),
		curCol(125),
		curRow(125)
	{
		
	}

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

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

	//	XMFLOAT2 DrawTile(FXMVECTOR pos);


};

