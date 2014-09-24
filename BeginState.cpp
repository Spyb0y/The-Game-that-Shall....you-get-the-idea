#include "BeginState.h"
#include "InClassProj.h"
#include <array>

void BeginState::Update(float dt)
{
}

void BeginState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
	Tile*** board = ((InClassProj*)mStateMachine)->GetBoard();
	//std::vector<Sprite::Frame*> tile = ((InClassProj*)mStateMachine)->GetVec();
	for (int i = 0; i < 250; ++i)
	{
		for (int j = 0; j < 250; ++j)
		{
			if (board[i][j] != NULL)
			{
				board[i][j]->Draw(vp, context, litTexEffect);
			}
			
		}
	}
}
