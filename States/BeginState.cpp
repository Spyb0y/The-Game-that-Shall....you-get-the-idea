#include "BeginState.h"
#include "InClassProj.cpp"

void BeginState::Update(float dt)
{
//std::vector<Sprite::Frame*> tile = ((InClassProj*)mStateMachine)->GetVec();
	int i = 0;
	while (board[i] != NULL)
	{
		board[125][125]->Draw();
	}
	
}

void BeginState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
	
}
