#include "BattleState.h"

void BattleState::Update(float dt)
{
	if (GetAsyncKeyState('A') & 0x8000)
	{
		mHero->Attack(mTestEnemy);
		if (mTestEnemy->GetEnemyHealth() <= 0)
		{
			int level = mTestEnemy->GetEnemyLevel();
			mEquip = mInventory->SelectEquip(level);
			mItem = mInventory->SelectItem(level);
			mHero->GetEquipment(mHero, mEquip);
			mHero->GetItem(mItem);
			delete mTestEnemy;
			Next = true;
		}
		else
		{
		mTestEnemy->Attack(mHero);
		}
		if (mHero->GetPlayerHealth() <= 0)
		{
			//set game over state
		}
	}
	if (Next)
	{
		mStateMachine->SetCurrState(mNextState);
	}
}

void BattleState::SetPlayer(Player* pPlayer)
{
	mHero = pPlayer;
}

void BattleState::SetInventory(Inventory* pInventory)
{
	mInventory = pInventory;
}

//test code
void BattleState::SetEnemy(Enemy* pEnemy)
{
	mTestEnemy = pEnemy;
}