#include "BattleState.h"
#include "InClassProj.h"

void BattleState::Init()
{
	mHero = new Player();

	mInventory = new Inventory();
	
	mTestEnemy = new Rat();
	
	mInventory->createItemVectors();
}

void BattleState::Update(float dt)
{
	if (GetAsyncKeyState('A') & 0x8000)
	{
		if (!isAPressed)
		{
			mHero->Attack(mTestEnemy);
			if (mTestEnemy->GetEnemyHealth() <= 0)
			{
				int level = mTestEnemy->GetEnemyLevel();
				mEquip = mInventory->SelectEquip(level, mTestEnemy);
				mItem = mInventory->SelectItem(level);
				mHero->GetEquipment(mHero, mEquip);
				mHero->GetItem(mItem);
				//delete mTestEnemy;
				//mTestEnemy = false;
				Next = true;
			}
			else if (mTestEnemy)
			{
				mTestEnemy->Attack(mHero);
			}
			if (mHero->GetPlayerHealth() <= 0)
			{
				//set game over state
				exit(-1);
			}
			if (Next)
			{
				mStateMachine->SetCurrState(mNextState);
			}
			isAPressed = true;
		}
	}
	else// if (!GetAsyncKeyState('A') & 0x8000)
	{
		isAPressed = false;
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

void BattleState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
	Tile*** board = ((InClassProj*)mStateMachine)->GetBoard();

	for (int i = 0; i < 250; ++i)
	{
		for (int j = 0; j < 250; ++j)
		{
			if (board[i][j] != NULL)
			{
				board[i][j]->Draw(vp, context, litTexEffect);

			}

		}
	}
}