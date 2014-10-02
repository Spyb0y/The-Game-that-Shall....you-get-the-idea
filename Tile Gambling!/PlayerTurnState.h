#pragma once
#include "State.h"

class PlayerTurnState : public State
{
public:
	PlayerTurnState(InClassProj* stateMachine) : State(stateMachine)
	{
	}
	virtual ~PlayerTurnState()
	{
		delete mNextState;
	}
	void Init(){}
	void Update(float dt){}
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
};

