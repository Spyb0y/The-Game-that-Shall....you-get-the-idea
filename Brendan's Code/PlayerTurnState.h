#pragma once
#include "State.h"
#include "TilePlacementState.h"
#include "FontRasterizer.h"
#include "Player.h"

class PlayerTurnState : public State
{
public:
	PlayerTurnState(InClassProj* stateMachine) : State(stateMachine),
		Next(false),
		IsWPressed(false),
		IsAPressed(false),
		IsSPressed(false),
		IsDPressed(false),
		IsMPressed(false),
		col(0),
		row(0),
		PlayerTile(0),
		showItemState(0),
		showEquipState(0),
		drawItemMenu(0),
		drawEquipMenu(0),
		isLClicked(0)
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
	void SetPlayer(Player* pPlayer);
	void SetInventory(Inventory* pInventory);
	void PlacePlayerTile();
	void DrawItemMenu(ID3D11DeviceContext* context);
	void DrawEquipMenu(ID3D11DeviceContext* context);
	
	XMFLOAT2 GetPlayerPos() const
	{
		return PlayerPos;
	}
private:
	Tile* PlayerTile;
	XMFLOAT2 PlayerPos;
	bool Next;
	bool IsWPressed;
	bool IsAPressed;
	bool IsSPressed;
	bool IsDPressed;
	bool IsMPressed;
	TilePlacementState* mPlace;
	int col;
	int row;
	std::vector<Sprite::Frame*> mPlayerTile;
	ID3D11DeviceContext* md3dImmediateContext;
	ID3D11Device* md3dDevice;
	bool showItemState;
	bool showEquipState;
	bool drawItemMenu;
	bool drawEquipMenu;
	bool isLClicked;
	Player* mHero;
	Inventory* mInventory;
	Equipment* mEquip;
	Item* mItem;
	FontRasterizer* mFont;
	ID3D11BlendState* mTransparentBS;
	ID3D11DepthStencilState* mFontDS;
	
};

