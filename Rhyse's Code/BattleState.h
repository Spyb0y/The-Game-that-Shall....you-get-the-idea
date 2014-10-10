#pragma once
#include <vector>
#include "State.h"
#include "InClassProj.h"
#include "FontRasterizer.h"
#include "TilePlacementState.h"
#include "Sprite.h"
#include "Tile.h"

class Inventory;

class BattleState : public State
{
public:
	BattleState(InClassProj* stateMachine) : State(stateMachine)
	{
		Next = false;
		isLClicked = false;
		drawMenu = false;
		drawArmour = false;
		selectItemState = false;
	}
	virtual ~BattleState()
	{
		delete mNextState;
		delete mLastState;
	}
	void Init();
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);
	void SetPlayer(Player*);
	void SetInventory(Inventory*);

private:
	Player* mHero;
	Inventory* mInventory;
	Equipment* mEquip;
	Item* mItem;

	FontRasterizer* mFont;

	bool Next;
	bool isLClicked;

	Enemy* mEnemy;

	ID3D11DeviceContext* md3dImmediateContext;
	ID3D11Device* md3dDevice;
	ID3D11BlendState* mTransparentBS;
	ID3D11DepthStencilState* mFontDS;

	Sprite::Frame* mBattleScreen;
	Tile* mScreenToDraw;

	std::vector<Tile::Frame*>mBattleScreenVector;

private:
	Enemy* SpawnEnemy();
	void SpawnBoss();
	void DrawItemMenu(ID3D11DeviceContext* context);
	void DrawArmourInventory(ID3D11DeviceContext* context);
	int PlayerSelectItem();

	bool drawMenu;
	bool drawArmour;
	bool selectItemState;
};

