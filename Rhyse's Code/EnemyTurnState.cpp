#include "EnemyTurnState.h"
#include "InClassProj.h"
#include "FontRasterizer.h"
#include "Inventory.h"

void EnemyTurnState::Init()
{
	mInventory = new Inventory();
	mInventory->createItemVectors();
	mInventory->CreateEnemyVectors();

	mFont = ((InClassProj*)mStateMachine)->GetFont();

	Next = false;

	md3dDevice = ((InClassProj*)mStateMachine)->GetDevice();
	md3dImmediateContext = ((InClassProj*)mStateMachine)->GetContext();
	mTransparentBS = ((InClassProj*)mStateMachine)->GetTransparentBS();
	mFontDS = ((InClassProj*)mStateMachine)->GetFontDS();

	mBattleScreen = new Sprite::Frame();
	ID3D11ShaderResourceView* image;
	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/PostBattleScreen.png",
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
	Sprite::Frame* test = mBattleScreenVector[0];
	mScreenToDraw = new Tile(XMVectorSet(950.0f, 500.0f, 0.0f, 1.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 1900, 1000, 0.0f, mBattleScreenVector, 1.0f, md3dDevice);

}

void EnemyTurnState::Update(float dt)
{
	if (mHero->armourInventory.size() <= mHero->GetMaxArmourSlots())
	{
		drawArmour = false;
		drawWeapon = false;
		drawAccessory = false;
		selectArmourState = false;
		selectWeaponState = false;
		selectAccessoryState = false;
		Next = true;
	}
	if (mHero->weaponInventory.size() <= mHero->GetMaxWeaponSlots())
	{
		drawArmour = false;
		drawWeapon = false;
		drawAccessory = false;
		selectArmourState = false;
		selectWeaponState = false;
		selectAccessoryState = false;
		Next = true;
	}
	if (mHero->accessoryInventory.size() <= mHero->GetMaxAccessorySlots())
	{
		drawArmour = false;
		drawWeapon = false;
		drawAccessory = false;
		selectArmourState = false;
		selectWeaponState = false;
		selectAccessoryState = false;
		Next = true;
	}

	if (mHero->armourInventory.size() > mHero->GetMaxArmourSlots())
	{
		drawArmour = true;
		drawWeapon = false;
		drawAccessory = false;
		selectArmourState = true;
		selectWeaponState = false;
		selectAccessoryState = false;
		Next = false;
	}
	if (mHero->weaponInventory.size() > mHero->GetMaxWeaponSlots())
	{
		drawArmour = false;
		drawWeapon = true;
		drawAccessory = false;
		selectArmourState = false;
		selectWeaponState = true;
		selectAccessoryState = false;
		Next = false;
	}
	if (mHero->accessoryInventory.size() > mHero->GetMaxAccessorySlots())
	{
		drawArmour = false;
		drawWeapon = false;
		drawAccessory = true;
		selectArmourState = false;
		selectWeaponState = false;
		selectAccessoryState = true;
		Next = false;
	}

	if (selectArmourState)
	{
		int j = 0;
		j = PlayerSelectItem();
		if (j != -1)
		{
			tempEquip = mHero->armourInventory[j];
			mHero->DeletePlayerStats(mHero, tempEquip);
			mHero->armourInventory.erase(mHero->armourInventory.begin() + j);
		}
	}
	if (selectWeaponState)
	{
		int j = 0;
		j = PlayerSelectItem();
		if (j != -1)
		{
			tempEquip = mHero->weaponInventory[j];
			mHero->DeletePlayerStats(mHero, tempEquip);
			mHero->weaponInventory.erase(mHero->weaponInventory.begin() + j);
		}
	}
	if (selectAccessoryState)
	{
		int j = 0;
		j = PlayerSelectItem();
		if (j != -1)
		{
			tempEquip = mHero->accessoryInventory[j];
			mHero->DeletePlayerStats(mHero, tempEquip);
			mHero->accessoryInventory.erase(mHero->accessoryInventory.begin() + j);
		}
	}

	if (Next)
	{
		Next = false;
		mNextState->Init();
		mStateMachine->SetCurrState(mNextState);
	}
}

void EnemyTurnState::SetPlayer(Player* pPlayer)
{
	mHero = pPlayer;
}

void EnemyTurnState::SetInventory(Inventory* pInventory)
{
	mInventory = pInventory;
}

int EnemyTurnState::PlayerSelectItem()
{
	if (GetAsyncKeyState('0') & 0x8000)
	{
		drawArmour = false;
		drawWeapon = false;
		drawAccessory = false;
		selectArmourState = false;
		selectWeaponState = false;
		selectAccessoryState = false;
		return 0;
	}
	else if (GetAsyncKeyState('1') & 0x8000)
	{
		drawArmour = false;
		drawWeapon = false;
		drawAccessory = false;
		selectArmourState = false;
		selectWeaponState = false;
		selectAccessoryState = false;
		return 1;
	}
	else if (GetAsyncKeyState('2') & 0x8000)
	{
		drawArmour = false;
		drawWeapon = false;
		drawAccessory = false;
		selectArmourState = false;
		selectWeaponState = false;
		selectAccessoryState = false;
		return 2;
	}
	else
	{
		return -1;
	}
}

void EnemyTurnState::DrawArmourInventory(ID3D11DeviceContext* context)
{
	string sArmourDisplay = mHero->DisplayArmourEquip().str();
	mFont->DrawFont(context, XMVectorSet(10.0f, 900.0f, 0.0f, 0.0f), 35, 35, 41, sArmourDisplay);
}

void EnemyTurnState::DrawWeaponInventory(ID3D11DeviceContext* context)
{
	string sWeaponDisplay = mHero->DisplayWeaponEquip().str();
	mFont->DrawFont(context, XMVectorSet(10.0f, 900.0f, 0.0f, 0.0f), 35, 35, 44, sWeaponDisplay);
}

void EnemyTurnState::DrawAccessoryInventory(ID3D11DeviceContext* context)
{
	string sAccessoryDisplay = mHero->DisplayAccessoryEquip().str();
	mFont->DrawFont(context, XMVectorSet(10.0f, 900.0f, 0.0f, 0.0f), 35, 35, 40, sAccessoryDisplay);
}

void EnemyTurnState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	context->OMSetBlendState(mTransparentBS, blendFactor, 0xffffffff);
	context->OMSetDepthStencilState(mFontDS, 0);

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

	if (drawArmour)
	{
		DrawArmourInventory(context);
	}
	if (drawWeapon)
	{
		DrawWeaponInventory(context);
	}
	if (drawAccessory)
	{
		DrawAccessoryInventory(context);
	}
}


