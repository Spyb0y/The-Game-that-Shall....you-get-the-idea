#pragma once
#include "d3dUtil.h"
#include "Effect.h"
#include "StateMachine.h"

class State
{
public:
	State(StateMachine* stateMachine) : 
		mStateMachine(stateMachine)
	{}
	virtual ~State(){}

	virtual void Init() {}
	virtual void Update(float dt) = 0;
	virtual void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect) = 0;

	void SetNextState(State* nextState){ mNextState = nextState; }
	State* GetNextState()const{ return mNextState; }

protected:
	StateMachine* mStateMachine;
	State* mNextState;
};

