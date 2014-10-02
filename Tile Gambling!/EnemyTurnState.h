#pragma once
#include "State.h"

class EnemyTurnState : public State
{
public:
	EnemyTurnState(InClassProj* stateMachine) : State(stateMachine)
	{
	}
	virtual ~EnemyTurnState()
	{
		delete mNextState;
	}
	void Init(){}
	void Update(float dt){}
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
};

