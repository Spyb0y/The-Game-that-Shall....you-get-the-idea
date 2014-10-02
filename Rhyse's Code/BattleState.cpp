#include "BattleState.h"
#include "FontRasterizer.h"

void BattleState::Update(float dt)
{
	//load the menu
	int xPos = ((InClassProj*)mStateMachine)->GetXPos();
	int yPos = ((InClassProj*)mStateMachine)->GetYPos();
	if (xPos >= 0 && xPos <= 200)
	{
		if (yPos >= 0 && yPos <= 200)
		{
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (!isLClicked)
				{
					mHero->Attack(mTestEnemy);

					//test code
					int level = mTestEnemy->GetEnemyLevel();
					//mEquip = mInventory->SelectEquip(level, mTestEnemy);
					mItem = mInventory->SelectItem(level);
					//mHero->GetEquipment(mHero, mEquip);
					mHero->GetItem(mItem);

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
					isLClicked = true;
				}
			}
			else
			{
				isLClicked = false;
			}
		}
	}


	if (xPos >= 200 && xPos <= 400)
	{
		if (yPos >= 0 && yPos <= 200)
		{
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (!isLClicked)
				{
					//test code
					mHero->SetPlayerHealth(10);

					isLClicked = true;
				}
			}
			else
			{
				isLClicked = false;
			}
		}
	}

	if (xPos >= 400 && xPos <= 600)
	{
		if (yPos >= 0 && yPos <= 200)
		{
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (!isLClicked)
				{
					//mFont = ((InClassProj*)mStateMachine)->GetFont();
					//mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 50, 50, 15, sItemsDisplay);

					//int i = m??->DrawItemFont(mHero);

					//string sItemsDisplay = mHero->DisplayItems().str();
					//display items
					//select item

					DrawItemMenu();

					//test code
					int i = 0;

					mHero->UseItem(i, mHero);
					mHero->Attack(mTestEnemy);
					mHero->ResetStats(i, mHero);
					mHero->DeleteItem(i);
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

					isLClicked = true;
				}
			}
			else
			{
				isLClicked = false;
			}
		}
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

void BattleState::DrawItemMenu()
{
		string sItemsDisplay = mHero->DisplayItems().str();
		mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 25, 25, 15, sItemsDisplay);
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