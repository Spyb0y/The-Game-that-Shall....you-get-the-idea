#pragma once
#include "State.h" 
#include "Tile.h"

class TilePlacementState : public State
{
public:
	enum PlacementState
	{
		TILE_MOVE,
		TILE_PLACE
	};

public:
	TilePlacementState(StateMachine* stateMachine) : State(stateMachine)
	{}
	virtual ~TilePlacementState(){}

	virtual void Init()
	{
		mCurrState = TILE_MOVE;
	}

	virtual void Update(float dt);
	virtual void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);

private:
	Tile* mTileToPlace;
	PlacementState mCurrState;
};

