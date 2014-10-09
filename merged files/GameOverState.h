#pragma once
#include "State.h"
#include "InClassProj.h"
#include "FontRasterizer.h"

class GameOverState : public State
{
public:
	GameOverState(InClassProj* stateMachine) : State(stateMachine)
	{
	}
	virtual ~GameOverState()
	{
		delete mNextState;
	}
	void Init();
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}

	ID3D11DeviceContext* md3dImmediateContext;
	FontRasterizer* mFont;
	void CongratulateLoser();

	bool PlayerDefeated;
};

