#pragma once
#include <vector>
#include "State.h"
#include "FontRasterizer.h"
#include "TilePlacementState.h"
#include "Sprite.h"
#include "Tile.h"
#include "Enemy.h"
#include "Player.h"

class Inventory;

class BattleState : public State
{
public:
	BattleState(InClassProj* stateMachine) : State(stateMachine)
	{
		Next = false;
		isLClicked = false;
		drawMenu = false;
		selectItemState = false;
		BossLvl1 = false;
		BossLvl2 = false;
		BossLvl3 = false;
		BossLvl4 = false;
		BossLvl5 = false;
	}
	virtual ~BattleState()
	{
		delete mNextState;
	}
	void Init();
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);
	void SetPlayer(Player*);
	void SetInventory(Inventory*);
	void SetBossBools();
	bool GetBoss1Bool() const;
	bool GetBoss2Bool() const;
	bool GetBoss3Bool() const;
	bool GetBoss4Bool() const;
	bool GetBoss5Bool() const;

	bool GetBattleStatus();
	//test code
	void SetEnemy(Enemy*);

private:
	Player* mHero;
	Inventory* mInventory;
	Equipment* mEquip;
	Item* mItem;
	TilePlacementState* mTileP;
	FontRasterizer* mFont;

	bool Next;
	bool isLClicked;
	bool BossLvl1;
	bool BossLvl2;
	bool BossLvl3;
	bool BossLvl4;
	bool BossLvl5;

	bool InBattleState;

	//test code
	Enemy* mEnemy;

	ID3D11DeviceContext* md3dImmediateContext;
	ID3D11Device* md3dDevice;
	ID3D11BlendState* mTransparentBS;
	ID3D11DepthStencilState* mFontDS;

	Sprite::Frame* mBattleScreen;
	Tile* mScreenToDraw;

	std::vector<Tile::Frame*>mBattleScreenVector;
	std::vector<Enemy*> boss;

private:
	Enemy* SpawnEnemy();
	Enemy* SpawnBoss();
	Enemy* SpawnStalker();
	PlayerTurnState* mPlayerTurn;
	void DrawItemMenu(ID3D11DeviceContext* context);
	int PlayerSelectItem();

	bool drawMenu;
	bool selectItemState;
};

