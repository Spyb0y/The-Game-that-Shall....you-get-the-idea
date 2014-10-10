#pragma once
#include "State.h" 
#include "Tile.h"
#include <ctime>
#include "BeginState.h"
#include "Sprite.h"
#include "Inventory.h"

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
		pBossLvl1(false),
		pBossLvl2(false),
		pBossLvl3(false),
		pBossLvl4(false),
		pBossLvl5(false)
	{
	}
		
	virtual ~TilePlacementState()
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
	void PlaceTile();

	void UpdateKeyboardInput(float dt);
	void DealCard(ID3D11Device* device);
	void SetCurrentTile(Sprite::Frame* temp);
	void SetBossBools();
	Sprite::Frame* GetCurrentTile();
	int GetCurrRow() const
	{
		return curRow;
	}

	int GetCurrCol() const
	{
		return curCol;
	}

	bool pBossLvl1;
	bool pBossLvl2;
	bool pBossLvl3;
	bool pBossLvl4;
	bool pBossLvl5;

private:
	PlacementState mCurrState;
	InClassProj* nextState;
	Tile* TileToBePlaced;
	
	bool IsWPressed;
	bool IsAPressed;
	bool IsSPressed;
	bool IsDPressed;
	bool IsPPressed;
	bool Next;
	
	int curCol;
	int curRow;
	Tile* prevTile;
	std::vector<Sprite::Frame*> prev;
	Sprite* sprite;
	Sprite::Frame* curFrame;
	std::vector<Sprite::Frame*> tile;
	XMFLOAT2 TilePos;
	Sprite::Frame* currentTile;
	Inventory* inv;
	std::vector<Enemy*> Bosses;
	ID3D11BlendState* mTransparentBS;
	ID3D11DepthStencilState* mFontDS;
	ID3D11DeviceContext* md3dImmediateContext;
	ID3D11Device* md3dDevice;
	
};

