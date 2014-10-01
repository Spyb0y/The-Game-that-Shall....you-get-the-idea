#pragma once
#include "State.h"
#include "TilePlacementState.h"

class PlayerTurnState : public State
{
private:
	int curCol;
	int curRow;

public:
	PlayerTurnState(StateMachine* stateMachine) : State(stateMachine),
		connectionDownToUp(false),
		connectionUpToDown(false),
		connectionRightToLeft(false),
		connectionLeftToRight(false)
	{
		tileContent = new TilePlacementState(mStateMachine);
	}
	virtual ~PlayerTurnState()
	{
		delete mNextState;
	}
	void Update(float dt){}
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}

	void CheckForBattle();

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

private:
	bool IsWPressed;
	bool IsAPressed;
	bool IsSPressed;
	bool IsDPressed;
	bool IsPPressed;
	bool Next;

	//Test Code//////////////////
	bool connectionRightToLeft;
	bool connectionLeftToRight;
	bool connectionUpToDown;
	bool connectionDownToUp;
	/////////////////////////////

	TilePlacementState* tileContent;
};

