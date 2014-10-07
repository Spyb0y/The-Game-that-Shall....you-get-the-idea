#pragma once
#include "State.h"
#include "InClassProj.h"

/*class Menu :
	public State
{
public:
	Menu();
	~Menu();
};*/
class Menu : public State
{
public:
	Menu(StateMachine* stateMachine) : State(stateMachine)
	{
	}
	virtual ~Menu()
	{
		delete mNextState;
	}
	void Update(float dt){}
	void Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect){}
	void BattleMenu();
	void ItemMenu(Player* mHero);
};
