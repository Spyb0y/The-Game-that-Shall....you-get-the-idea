#pragma once
#include "State.h"
#include "InClassProj.h"
#include "FontRasterizer.h"

class BattleState : public State
{
public:
	BattleState(StateMachine* stateMachine) : State(stateMachine)
	{
		Next = false;
		isAPressed = false;
	}
	virtual ~BattleState()
	{
		delete mNextState;
	}
	void Update(float dt);
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect);
	void SetPlayer(Player*);
	void SetInventory(Inventory*);

	//test code
	void SetEnemy(Enemy*);

private:
	Player* mHero;
	Inventory* mInventory;
	Equipment* mEquip;
	Item* mItem;

	FontRasterizer* mFont;

	bool Next;
	bool isAPressed;
	bool isLClicked;

	//test code
	Enemy* mTestEnemy;

	ID3D11DeviceContext* md3dImmediateContext;

private:
	void DrawItemMenu();
};

