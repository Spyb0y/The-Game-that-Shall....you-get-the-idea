#pragma once
#include "d3dUtil.h"
#include "Effect.h"

class InClassProj;

class State
{
public:
	State(InClassProj* stateMachine) :
		mStateMachine(stateMachine)
	{}
	virtual ~State(){}

	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect) = 0;
	
	void SetNextState(State* nextState){ mNextState = nextState; }
	State* GetNextState()const{ return mNextState; }

protected:
	InClassProj* mStateMachine;
	State* mNextState;
};

