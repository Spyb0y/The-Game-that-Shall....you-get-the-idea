#pragma once
#include "State.h"

class PlayerTurnState : public State
{
public:
	PlayerTurnState(StateMachine* stateMachine) : State(stateMachine)
	{
	}
	virtual ~PlayerTurnState()
	{
		delete mNextState;
	}
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
};

