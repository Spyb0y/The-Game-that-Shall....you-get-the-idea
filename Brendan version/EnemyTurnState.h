#pragma once
#include "State.h"

class EnemyTurnState : public State
{
public:
	EnemyTurnState(StateMachine* stateMachine) : State(stateMachine)
	{
	}
	virtual ~EnemyTurnState()
	{
		delete mNextState;
	}
	void Update(float dt){}
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
};

