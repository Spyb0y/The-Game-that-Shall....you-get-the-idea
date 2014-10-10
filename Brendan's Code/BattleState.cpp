#include "BattleState.h"
#include "FontRasterizer.h"
#include "Inventory.h"
#include "InClassProj.h"

void BattleState::Init()
{
	mInventory = new Inventory();
	mInventory->createItemVectors();
	mInventory->CreateEnemyVectors();
	boss = mInventory->GetBossVec();

	mEnemy = SpawnEnemy();

	mFont = ((InClassProj*)mStateMachine)->GetFont();

	Next = false;

	md3dDevice = ((InClassProj*)mStateMachine)->GetDevice();
	md3dImmediateContext = ((InClassProj*)mStateMachine)->GetContext();
	mTransparentBS = ((InClassProj*)mStateMachine)->GetTransparentBS();
	mFontDS = ((InClassProj*)mStateMachine)->GetFontDS();

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
					mHero->Attack(mEnemy);

					if (mEnemy->GetEnemyHealth() <= 0)
					{
						int level = mEnemy->GetEnemyLevel();
						mEquip = mInventory->SelectEquip(level, mEnemy);
						mItem = mInventory->SelectItem(level);
						mHero->GetEquipment(mHero, mEquip);
						mHero->GetItem(mItem);
						delete mEnemy;
						Next = true;
					}
					else if (mEnemy)
					{
						mEnemy->Attack(mHero);
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
					selectItemState = false;
					drawMenu = false;
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
					exit(-1);

					selectItemState = false;
					drawMenu = false;
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
			mHero->Attack(mEnemy);
			mHero->ResetStats(i, mHero);
			mHero->DeleteItem(i);
			if (mEnemy->GetEnemyHealth() <= 0)
			{
				int level = mEnemy->GetEnemyLevel();
				mEquip = mInventory->SelectEquip(level, mEnemy);
				mItem = mInventory->SelectItem(level);
				mHero->GetEquipment(mHero, mEquip);
				mHero->GetItem(mItem);
				delete mEnemy;
				Next = true;
			}
			else if (mEnemy)
			{
				mEnemy->Attack(mHero);
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
	if (mEnemy->GetEnemyHealth() <= 0)
	{
		SetBossBools();
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
	mEnemy = pEnemy;
}

void BattleState::SetBossBools()
{
	if (boss[0]->GetEnemyHealth() <= 0)
	{
		BossLvl1 = true;
	}
	if (boss[1]->GetEnemyHealth() <= 0)
	{
		BossLvl2 = true;
	}
	if (boss[2]->GetEnemyHealth() <= 0)
	{
		BossLvl3 = true;
	}
	if (boss[3]->GetEnemyHealth() <= 0)
	{
		BossLvl4 = true;
	}
	if (boss[4]->GetEnemyHealth() <= 0)
	{
		BossLvl5 = true;
	}
}

bool BattleState::GetBoss1Bool() const
{
	return BossLvl1;
}
bool BattleState::GetBoss2Bool() const
{
	return BossLvl2;
}
bool BattleState::GetBoss3Bool() const
{
	return BossLvl3;
}
bool BattleState::GetBoss4Bool() const
{
	return BossLvl4;
}
bool BattleState::GetBoss5Bool() const
{
	return BossLvl5;
}

Enemy* BattleState::SpawnEnemy()
{
	Sprite::Frame* mTile = ((StateMachine*)mStateMachine)->GetCurrTile();
	int random;

	if (mTile->Direction == 24)
	{
		SpawnBoss();
	}
	else if (mTile->Terrain == 1)//forest
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

Enemy* BattleState::SpawnBoss()
{
	Sprite::Frame* mTile = ((StateMachine*)mStateMachine)->GetCurrTile();
	if (mTile->Level = 5)
	{
		return mInventory->BossEnemies[0];
	}
	if (mTile->Level = 6)
	{
		return mInventory->BossEnemies[1];
	}
	if (mTile->Level = 7)
	{
		return mInventory->BossEnemies[2];
	}
	if (mTile->Level = 8)
	{
		return mInventory->BossEnemies[3];
	}
	if (mTile->Level = 9)
	{
		return mInventory->BossEnemies[4];
	}
	//if (Stalker)
	//{
	// mEnemy = Inventory::BossEnemies[5];
	//}*/
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
		mFont->DrawFont(context, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 25, 25, 43, sItemsDisplay);
}

void BattleState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	md3dImmediateContext->OMSetBlendState(mTransparentBS, blendFactor, 0xffffffff);
	md3dImmediateContext->OMSetDepthStencilState(mFontDS, 0);

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

	std::stringstream ssPlayerHealth;
	ssPlayerHealth << mHero->GetPlayerHealth();
	string sPlayerHealth = ssPlayerHealth.str();

	string sEnemyDisplay = mEnemy->DisplayEnemy(mEnemy).str();

	std::stringstream ssEnemyHealth;
	ssEnemyHealth << mEnemy->GetEnemyHealth();
	string sEnemyHealth = ssEnemyHealth.str();

	std::stringstream ssPlayerAttack;
	ssPlayerAttack << mHero->GetPlayerAttack();
	string sPlayerAttack = ssPlayerAttack.str();

	std::stringstream ssPlayerDefense;
	ssPlayerDefense << mHero->GetPlayerDefense();
	string sPlayerDefense = ssPlayerDefense.str();

	std::stringstream ssPlayerEvade;
	ssPlayerEvade << mHero->GetPlayerEvade();
	string sPlayerEvade = ssPlayerEvade.str();

	std::stringstream ssPlayerHand;
	ssPlayerHand << mHero->playerHand.size();
	string sPlayerHand = ssPlayerHand.str();

	mFont->DrawFont(md3dImmediateContext, XMVectorSet(300.0f, 675.0f, 0.0f, 0.0f), 50, 50, 15, sPlayerHealth);
	mFont->DrawFont(md3dImmediateContext, XMVectorSet(150.0f, 565.0f, 0.0f, 0.0f), 25, 25, 50, sEnemyDisplay);
	mFont->DrawFont(md3dImmediateContext, XMVectorSet(300.0f, 475.0f, 0.0f, 0.0f), 50, 50, 15, sEnemyHealth);
	mFont->DrawFont(md3dImmediateContext, XMVectorSet(750.0f, 675.0f, 0.0f, 0.0f), 50, 50, 15, sPlayerAttack);
	mFont->DrawFont(md3dImmediateContext, XMVectorSet(750.0f, 575.0f, 0.0f, 0.0f), 50, 50, 15, sPlayerDefense);
	mFont->DrawFont(md3dImmediateContext, XMVectorSet(750.0f, 475.0f, 0.0f, 0.0f), 50, 50, 15, sPlayerEvade);
	mFont->DrawFont(md3dImmediateContext, XMVectorSet(1100.0f, 975.0f, 0.0f, 0.0f), 50, 50, 15, sPlayerHand);
}