#pragma once
#include "State.h" 
#include "Tile.h"

class TilePlacementState : public State
{
	enum PlacementState
	{
		TILE_MOVE,
		TILE_PLACE
	};

public:
	TilePlacementState(StateMachine* stateMachine) : State(stateMachine),
		curCol(125),
		curRow(125),
		IsAPressed(false),
		IsWPressed(false),
		IsSPressed(false),
		IsDPressed(false),
		IsPPressed(false),
		Next(false)
	{
		
	}
	
	virtual ~TilePlacementState(){}

	virtual void Init()
	{
		mCurrState = TILE_MOVE;
	}

	virtual void Update(float dt);
	virtual void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void PlaceTile();

	void UpdateKeyboardInput(float dt);
	
	int GetCurrRow()
	{
		return curRow;
	}

	int GetCurrCol()
	{
		return curCol;
	}

private:
	PlacementState mCurrState;
	StateMachine* nextState;

	bool IsWPressed;
	bool IsAPressed;
	bool IsSPressed;
	bool IsDPressed;
	bool IsPPressed;
	bool Next;

	int curCol;
	int curRow;
	int currTile;
};

