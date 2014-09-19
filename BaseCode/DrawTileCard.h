#pragma once
#include "TilePlacementState.h"
class DrawTileCard :
	public State
{
public:
	DrawTileCard(StateMachine* stateMachine) : State(stateMachine)
	{
	}
	virtual ~DrawTileCard()
	{
		delete mNextState;
	}

	virtual void Update(float dt)
	{
		int test = 0;
		test++;

		if (/*condition to go to next state is true */ true)
		{
			mStateMachine->SetCurrState(mNextState);
		}
		//hahaha delete this
	}
	virtual void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}

private:
	
};

