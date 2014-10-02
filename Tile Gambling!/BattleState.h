#pragma once
#include "State.h"
#include "Enemy.h"
#include "Inventory.h"

class BattleState : public State
{
public:
	BattleState(InClassProj* stateMachine) : State(stateMachine)
	{
		Next = false;
		isAPressed = false;
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

	//test code
	void SetEnemy(Enemy*);

private:
	Player* mHero;
	Enemy* mTestEnemy;
	Inventory* mInventory;
	Equipment* mEquip;
	Item* mItem;

	bool Next;
	bool isAPressed;

};

