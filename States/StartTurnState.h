#pragma once
#include "State.h"
class StartTurnState : public State
{
public:
	StartTurnState(StateMachine* stateMachine) : State(stateMachine)
	{
	}
	virtual ~StartTurnState()
	{
		delete mNextState;
	}
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
};

