#pragma once
#include "State.h"

class GameOverState : public State
{
public:
	GameOverState(StateMachine* stateMachine) : State(stateMachine)
	{
	}
	virtual ~GameOverState()
	{
		delete mNextState;
	}
	void Update(float dt){}
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
};

