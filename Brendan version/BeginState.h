#pragma once
#include "State.h"
class BeginState :
	public State
{
public:
	BeginState(StateMachine* stateMachine) : State(stateMachine),
		Next(false)
	{
	}
	virtual ~BeginState()
	{
		delete mNextState;
	}
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);
private:
	BeginState* begin;
	bool Next;


};

