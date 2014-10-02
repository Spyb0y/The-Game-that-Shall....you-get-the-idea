#pragma once
#include "TilePlacementState.h"
class DrawTileCard :
	public State
{
public:
	DrawTileCard(InClassProj* stateMachine) : State(stateMachine)
	{
	}
	virtual ~DrawTileCard()
	{
		delete mNextState;
	}
	void Init(ID3D11Device* device){}
	virtual void Update(float dt)
	{

	}
	virtual void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}

private:
	
};

