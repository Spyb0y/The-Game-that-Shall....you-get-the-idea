#pragma once
#include "State.h"

class GameWonState : public State
{
public:
	GameWonState(InClassProj* stateMachine) : State(stateMachine)
	{
	}
	virtual ~GameWonState()
	{
		delete mNextState;
	}
	void Init(){}
	void Update(float dt){}
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
};

