#pragma once
#include "State.h"
#include <vector>
#include "State.h"
#include "InClassProj.h"
#include "FontRasterizer.h"
#include "TilePlacementState.h"
#include "Sprite.h"
#include "Tile.h"

class EnemyTurnState : public State
{
public:
	EnemyTurnState(InClassProj* stateMachine) : State(stateMachine)
	{
		Next = false;
		isLClicked = false;
		drawArmour = false;
		drawWeapon = false;
		drawAccessory = false;
		selectArmourState = false;
		selectWeaponState = false;
		selectAccessoryState = false;
	}
	virtual ~EnemyTurnState()
	{
		delete mNextState;
	}
	void Init();
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);
	void SetPlayer(Player*);
	void SetInventory(Inventory*);

private:
	Player* mHero;
	Inventory* mInventory;
	Equipment* tempEquip;

	FontRasterizer* mFont;

	bool Next;
	bool isLClicked;

	ID3D11DeviceContext* md3dImmediateContext;
	ID3D11Device* md3dDevice;
	ID3D11BlendState* mTransparentBS;
	ID3D11DepthStencilState* mFontDS;

	Sprite::Frame* mBattleScreen;
	Tile* mScreenToDraw;

	std::vector<Tile::Frame*>mBattleScreenVector;

private:
	void DrawArmourInventory(ID3D11DeviceContext* context);
	void DrawWeaponInventory(ID3D11DeviceContext* context);
	void DrawAccessoryInventory(ID3D11DeviceContext* context);
	int PlayerSelectItem();

	bool drawArmour;
	bool drawWeapon;
	bool drawAccessory;
	bool selectArmourState;
	bool selectWeaponState;
	bool selectAccessoryState;
};

