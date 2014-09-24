#pragma once
#include "State.h"

class BattleState : public State
{
public:
	BattleState(StateMachine* stateMachine) : State(stateMachine)
	{
	}
	virtual ~BattleState()
	{
		delete mNextState;
	}
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
};

