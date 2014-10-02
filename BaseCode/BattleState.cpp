#include "BattleState.h"
void BattleState::SpawnEnemy()
{
	Tile mTile = InClassProj.GetTile();
	int rand;
	if (mTile.Terrain == 1)//forest
	{
		rand = rand() % Inventory::GetForestSize() + 1;
		if (Inventory::ForestEnemies[rand].level > level)
		{
			BattleState::SpawnEnemy();
		}
		mTestEnemy = Inventory::ForestEnemies[rand];
	}
	else if (mTile.Terrain == 2)//castle
	{
		rand = rand() % Inventory::GetCastleSize() + 1;
		if (Inventory::CastleEnemies[rand].level > level)
		{
			BattleState::SpawnEnemy();
		}
		mTestEnemy = Inventory::CastleEnemies[rand];
	}
	else if (mTile.Terrain == 3)//swamp
	{
		rand = rand() % Inventory::GetSwampSize() + 1;
		if (Inventory::SwampEnemies[rand].level > level)
		{
			BattleState::SpawnEnemy();
		}
		mTestEnemy = Inventory::SwampEnemies[rand];
	}
	else if (mTile.Terrain == 4)//mountain
	{
		rand = rand() % Inventory::GetMountainSize() + 1;
		if (Inventory::MountainEnemies[rand].level > level)
		{
			BattleState::SpawnEnemy();
		}
		mTestEnemy = Inventory::MountainEnemies[rand];
	}
}

void BattleState::SpawnBoss()
{
	if (level = 1)
	{
		mTestEnemy = Inventory::BossEnemies[1];
	}
	if (level = 2)
	{
		mTestEnemy = Inventory::BossEnemies[2];
	}
	if (level = 3)
	{
		mTestEnemy = Inventory::BossEnemies[3];
	}
	if (level = 4)
	{
		mTestEnemy = Inventory::BossEnemies[4];
	}
	if (level = 5)
	{
		mTestEnemy = Inventory::BossEnemies[5];
	}
	//if (Stalker)
	//{
	//	mTestEnemy = Inventory::BossEnemies[6];
	//}
}

void BattleState::Update(float dt)
{	
	BattleState::SpawnEnemy();
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