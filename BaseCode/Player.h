#pragma once
#include "sprite.h"
class Player :
	public Sprite
{
private:
	
public:

	Player(FXMVECTOR pos, FXMVECTOR scale, uint16_t frameWidth, uint16_t frameHeight, float depth, const std::vector<Frame*>& frames, float frameRate, ID3D11Device* device)
		:Sprite(pos, scale, frameWidth, frameHeight, depth, frames, frameRate, device)
	{
	}

	//~Player(void);

//	void Jump();

};

