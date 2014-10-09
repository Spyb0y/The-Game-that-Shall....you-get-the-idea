#pragma once
#include "State.h" 
#include "Tile.h"
#include <ctime>
#include "BeginState.h"
#include "Sprite.h"

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
		Next(false),
		BossLvl1(false),
		BossLvl2(false),
		BossLvl3(false),
		BossLvl4(false),
		BossLvl5(false)
	{
		//work = new BeginState(mStateMachine);
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
	void SetCurrentTile(Sprite::Frame* temp);
	Sprite::Frame* GetCurrentTile();

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
//	BeginState* work;

	bool IsWPressed;
	bool IsAPressed;
	bool IsSPressed;
	bool IsDPressed;
	bool IsPPressed;
	bool Next;

	bool BossLvl1;
	bool BossLvl2;
	bool BossLvl3;
	bool BossLvl4;
	bool BossLvl5;

/*	bool boss1Defeated;
	bool boss2Defeated;
	bool boss3Defeated;
	bool boss4Defeated;
	bool boss5Defeated;*/

	int curCol;
	int curRow;

	Tile* prevTile;
	std::vector<Sprite::Frame*> prev;
	Sprite* sprite;
	Sprite::Frame* curFrame;
	std::vector<Sprite::Frame*> tile;
	XMFLOAT2 TilePos;
	Sprite::Frame* currentTile;

};

