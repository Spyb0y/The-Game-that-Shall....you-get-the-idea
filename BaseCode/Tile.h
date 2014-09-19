#pragma once
#include "Sprite.h"
class Tile :
	public Sprite
{

public:
	
public:
	
	
	Tile(FXMVECTOR pos, FXMVECTOR scale, uint16_t frameWidth, uint16_t frameHeight, float depth, const std::vector<Frame*>& frames, float frameRate, ID3D11Device* device)
		:Sprite(pos, scale, frameWidth, frameHeight, depth, frames, frameRate, device)
	{

	}

	virtual void MoveRight(float amt);


//	XMFLOAT2 DrawTile(FXMVECTOR pos);


};

