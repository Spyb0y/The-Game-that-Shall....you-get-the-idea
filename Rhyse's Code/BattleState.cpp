#include "BattleState.h"
#include "FontRasterizer.h"
#include "Inventory.h"

void BattleState::Init()
{
	mInventory = new Inventory();
	mInventory->createItemVectors();
	mInventory->CreateEnemyVectors();

	mTestEnemy = SpawnEnemy();

	mFont = ((InClassProj*)mStateMachine)->GetFont();

	Next = false;

	md3dDevice = ((InClassProj*)mStateMachine)->GetDevice();

	mBattleScreen = new Sprite::Frame();
	ID3D11ShaderResourceView* image;
	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/BattleScreen.png",
		0, 0, &image, 0);
	mBattleScreen->imageWidth = 1900;
	mBattleScreen->imageHeight = 1000;
	mBattleScreen->x = 0;
	mBattleScreen->y = 0;
	mBattleScreen->image = image;
	mBattleScreen->Terrain = 1;
	mBattleScreen->Level = 1;
	mBattleScreen->Direction = 1;

	mBattleScreenVector.push_back(mBattleScreen);
	mScreenToDraw = new Tile(XMVectorSet(950.0f, 500.0f, 0.0f, 1.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 1900, 1000, 0.0f, mBattleScreenVector, 1.0f, md3dDevice);

}

void BattleState::Update(float dt)
{
	//load the menu
	int xPos = ((InClassProj*)mStateMachine)->GetXPos();
	int yPos = ((InClassProj*)mStateMachine)->GetYPos();
	if (xPos >= 0 && xPos <= 300)
	{
		if (yPos >= 0 && yPos <= 200)
		{
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (!isLClicked)
				{
					mHero->Attack(mTestEnemy);

					if (mTestEnemy->GetEnemyHealth() <= 0)
					{
						int level = mTestEnemy->GetEnemyLevel();
						mEquip = mInventory->SelectEquip(level, mTestEnemy);
						mItem = mInventory->SelectItem(level);
						mHero->GetEquipment(mHero, mEquip);
						mHero->GetItem(mItem);
						delete mTestEnemy;
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
						Next = false;
						mNextState->Init();
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


	if (xPos >= 300 && xPos <= 600)
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

	if (xPos >= 600 && xPos <= 900)
	{
		if (yPos >= 0 && yPos <= 200)
		{
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (!isLClicked)
				{
					selectItemState = true;
					isLClicked = true;
				}
			}
			else
			{
				isLClicked = false;
			}
		}
	}
	if (selectItemState)
	{
		drawMenu = true;
		int i = PlayerSelectItem();
		if (i != -1)
		{
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
				delete mTestEnemy;
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
				mNextState->Init();
				mStateMachine->SetCurrState(mNextState);
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

Enemy* BattleState::SpawnEnemy()
{
	Sprite::Frame* mTile = ((StateMachine*)mStateMachine)->GetCurrTile();
	int random;
	if (mTile->Terrain == 1)//forest
	{
		srand(time(NULL));
		random = rand() % mInventory->GetForestSize();
		while (mInventory->ForestEnemies[random]->GetEnemyLevel() > mTile->Level - 4)
		{
			random = rand() % mInventory->GetForestSize();
		}
		return mInventory->ForestEnemies[random];
	}
	else if (mTile->Terrain == 2)//castle
	{
		srand(time(NULL));
		random = rand() % mInventory->GetCastleSize();
		while (mInventory->CastleEnemies[random]->GetEnemyLevel() > mTile->Level - 4)
		{
			random = rand() % mInventory->GetCastleSize();
		}
		return mInventory->CastleEnemies[random];
	}
	else if (mTile->Terrain == 3)//swamp
	{
		srand(time(NULL));
		random = rand() % mInventory->GetSwampSize();
		while (mInventory->SwampEnemies[random]->GetEnemyLevel() > mTile->Level - 4)
		{
			random = rand() % mInventory->GetSwampSize();
		}
		return mInventory->SwampEnemies[random];
	}
	else if (mTile->Terrain == 4)//mountain
	{
		srand(time(NULL));
		random = rand() % mInventory->GetMountainSize();
		while (mInventory->CastleEnemies[random]->GetEnemyLevel() > mTile->Level - 4)
		{
			random = rand() % mInventory->GetMountainSize();
		}
		return mInventory->CastleEnemies[random];
	}
}

void BattleState::SpawnBoss()
{
	Sprite::Frame* mTile = ((StateMachine*)mStateMachine)->GetCurrTile();
	if (mTile->Level = 1 + 4)
	{
		mTestEnemy = mInventory->BossEnemies[0];
	}
	if (mTile->Level = 2 + 4)
	{
		mTestEnemy = mInventory->BossEnemies[1];
	}
	if (mTile->Level = 3 + 4)
	{
		mTestEnemy = mInventory->BossEnemies[2];
	}
	if (mTile->Level = 4 + 4)
	{
		mTestEnemy = mInventory->BossEnemies[3];
	}
	if (mTile->Level = 5 + 4)
	{
		mTestEnemy = mInventory->BossEnemies[4];
	}
	//if (Stalker)
	//{
	// mTestEnemy = Inventory::BossEnemies[5];
	//}
}

int BattleState::PlayerSelectItem()
{
	if (GetAsyncKeyState('0') & 0x8000)
	{
		drawMenu = false;
		selectItemState = false;
		return 0;
	}
	else if (GetAsyncKeyState('1') & 0x8000)
	{
		drawMenu = false;
		selectItemState = false;
		return 1;
	}
	else if (GetAsyncKeyState('2') & 0x8000)
	{
		drawMenu = false;
		selectItemState = false;
		return 2;
	}
	else if (GetAsyncKeyState('3') & 0x8000)
	{
		drawMenu = false;
		selectItemState = false;
		return 3;
	}
	else if (GetAsyncKeyState('4') & 0x8000)
	{
		drawMenu = false;
		selectItemState = false;
		return 4;
	}
	else if (GetAsyncKeyState('5') & 0x8000)
	{
		drawMenu = false;
		selectItemState = false;
		return 5;
	}
	else
	{
		return -1;
	}
}

void BattleState::DrawItemMenu(ID3D11DeviceContext* context)
{
		string sItemsDisplay = mHero->DisplayItems().str();
		mFont->DrawFont(context, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 25, 25, 15, sItemsDisplay);
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

	mScreenToDraw->Draw(vp, context, litTexEffect);

	if (drawMenu)
	{
		DrawItemMenu(context);
	}
}