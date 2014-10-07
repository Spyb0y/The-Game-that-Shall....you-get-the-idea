#pragma once
#include "State.h"
#include "TilePlacementState.h"

class PlayerTurnState : public State
{
public:
	PlayerTurnState(InClassProj* stateMachine) : State(stateMachine),
		Next(false),
		IsWPressed(false),
		IsAPressed(false),
		IsSPressed(false),
		IsDPressed(false),
		IsPPressed(false),
		col(0),
		row(0)

	{
	}
	virtual ~PlayerTurnState()
	{
		delete mNextState;
	}
	void Init();
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void UpdateKeyboardInput(float dt);
private:
	Tile* PlayerTile;
	XMFLOAT2 PlayerPos;
	bool Next;
	bool IsWPressed;
	bool IsAPressed;
	bool IsSPressed;
	bool IsDPressed;
	bool IsPPressed;
	TilePlacementState* mPlace;
	int col;
	int row;
};

