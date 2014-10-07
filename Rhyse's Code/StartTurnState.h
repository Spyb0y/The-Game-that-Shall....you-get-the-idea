#pragma once
#include "State.h"
#include "Sprite.h"
#include <ctime>
#include <vector>


class StartTurnState : public State
{
public:
	StartTurnState(InClassProj* stateMachine) : State(stateMachine)
	{
	}
	virtual ~StartTurnState()
	{
		delete mNextState;
	}
	void Update(ID3D11Device* device, float dt);
	void Update(float dt){}
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
	void DealCard(ID3D11Device* device);
};

