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
		isLClicked(0),
		PlayerTileIsMade(false),
		walk(0)
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
	Tile* GetPlayerTile();
	void UpdateKeyboardInput(float dt);
	void PlacePlayerTile();

	bool GetPlayerExistence();

	XMFLOAT2 GetPlayerPos() const
	{
		return PlayerPos;
	}
	void SetPlayer(Player*);
	void SetInventory(Inventory* pInventory);

	int GetWalk();
	int walk;

private:
	Tile* PlayerTile;
	XMFLOAT2 PlayerPos;
	bool Next;
	bool IsWPressed;
	bool IsAPressed;
	bool IsSPressed;
	bool IsDPressed;
	bool IsMPressed;

	bool PlayerTileIsMade;

	TilePlacementState* mPlace;
	int col;
	int row;
	std::vector<Sprite::Frame*> mPlayerTile;

	void PlayerTurnState::DrawItemMenu(ID3D11DeviceContext* context);
	void PlayerTurnState::DrawEquipMenu(ID3D11DeviceContext* context);
	void CreatePlayerTile();
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


	//Test Code//////////////////
	bool connectionRightToLeft;
	bool connectionLeftToRight;
	bool connectionUpToDown;
	bool connectionDownToUp;
	/////////////////////////////

	TilePlacementState* tileContent;
};










