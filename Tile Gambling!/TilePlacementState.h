#pragma once
#include "State.h" 
#include "Tile.h"
#include <ctime>
#include "BeginState.h"

class TilePlacementState : public State
{
	enum PlacementState
	{
		TILE_MOVE,
		TILE_PLACE
	};

public:
	TilePlacementState(InClassProj* stateMachine) : State(stateMachine),
		curCol(125),
		curRow(125),
		IsAPressed(false),
		IsWPressed(false),
		IsSPressed(false),
		IsDPressed(false),
		IsPPressed(false),
		Next(false)
	{
		work = new BeginState(mStateMachine);
	}
		
	virtual ~TilePlacementState(){}

	void Init();
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void PlaceTile();

	void UpdateKeyboardInput(float dt);
	void DealCard(ID3D11Device* device);
	
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
	InClassProj* nextState;
	Tile* TileToBePlaced;
	BeginState* work;

	bool IsWPressed;
	bool IsAPressed;
	bool IsSPressed;
	bool IsDPressed;
	bool IsPPressed;
	bool Next;

	int curCol;
	int curRow;
	int currTile;

	std::vector<Sprite::Frame*> tile;
	XMFLOAT2 TilePos;
	
};

