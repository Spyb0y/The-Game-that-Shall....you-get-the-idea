#include "TilePlacementState.h"
#include "InClassProj.h"
#include "State.h"


void TilePlacementState::Init()
{
	DealCard(mStateMachine->GetDevice());
	md3dDevice = ((InClassProj*)mStateMachine)->GetDevice();
	md3dImmediateContext = ((InClassProj*)mStateMachine)->GetContext();
	mTransparentBS = ((InClassProj*)mStateMachine)->GetTransparentBS();
	mFontDS = ((InClassProj*)mStateMachine)->GetFontDS();
	inv = new Inventory();

	pBossLvl1 = ((StateMachine*)mStateMachine)->GetBool1();
	pBossLvl2 = ((StateMachine*)mStateMachine)->GetBool2();
	pBossLvl3 = ((StateMachine*)mStateMachine)->GetBool3();
	pBossLvl4 = ((StateMachine*)mStateMachine)->GetBool4();
	pBossLvl5 = ((StateMachine*)mStateMachine)->GetBool5();
}

void TilePlacementState::Update(float dt)
{
	DealCard(mStateMachine->GetDevice());
	curCol;
	curRow;

	TileToBePlaced->SetPos(XMVectorSet(TilePos.x, TilePos.y, 0.0f, 1.0f));
	
	UpdateKeyboardInput(dt);
	if (Next)
	{
		Next = false;
		mStateMachine->SetCurrState(mNextState);
		mNextState->Init();
	}
	
}

void  TilePlacementState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	md3dImmediateContext->OMSetBlendState(mTransparentBS, blendFactor, 0xffffffff);
	md3dImmediateContext->OMSetDepthStencilState(mFontDS, 0);
	
	TileToBePlaced->Draw(vp, context, litTexEffect);
	
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

	Tile*** pBoard = ((InClassProj*)mStateMachine)->GetPlayerBoard();
	for (int i = 0; i < 250; ++i)
	{
		for (int j = 0; j < 250; ++j)
		{
			if (pBoard[i][j] != NULL)
			{
				pBoard[i][j]->Draw(vp, context, litTexEffect);
			}
		}
	}
}

void TilePlacementState::DealCard(ID3D11Device* device)
{
	std::vector<Sprite::Frame*> home = ((InClassProj*)mStateMachine)->GetHomeVec();
	srand(time(NULL));

	TilePos.x = (curCol - 125) * 250;
	TilePos.y = (curRow - 125) * 250;
	
	std::vector<Tile::Frame*> Lvl1 = ((InClassProj*)mStateMachine)->GetTileLvl1();
	std::vector<Tile::Frame*> Lvl2 = ((InClassProj*)mStateMachine)->GetTileLvl2();
	std::vector<Tile::Frame*> Lvl3 = ((InClassProj*)mStateMachine)->GetTileLvl3();
	std::vector<Tile::Frame*> Lvl4 = ((InClassProj*)mStateMachine)->GetTileLvl4();
	std::vector<Tile::Frame*> Lvl5 = ((InClassProj*)mStateMachine)->GetTileLvl5();
	int i = rand() % 30;
	int j = rand() % 45;
	int k = rand() % 60;
	tile.clear();
		
	if (pBossLvl4)
	{
		tile.push_back(Lvl5[k]);
		SetCurrentTile(Lvl5[k]);
	}
	else if (pBossLvl3)
	{
		tile.push_back(Lvl4[j]);
		SetCurrentTile(Lvl4[j]);
	}
	else if (pBossLvl2)
	{
		tile.push_back(Lvl3[j]);
		SetCurrentTile(Lvl3[j]);
	}
	else if (pBossLvl1)
	{
		tile.push_back(Lvl2[i]);
		SetCurrentTile(Lvl2[i]);
	}
	else
	{
		SetCurrentTile(Lvl1[i]);
		tile.push_back(Lvl1[i]);
	}
			
	TileToBePlaced = new Tile(XMVectorSet(TilePos.x, TilePos.y, 0.0f, 1.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 250, 250, 0.0f, tile, 1.0f, device);

}

void TilePlacementState::SetCurrentTile(Sprite::Frame* temp)
{
	currentTile = temp;
}

Sprite::Frame* TilePlacementState::GetCurrentTile()
{
	return currentTile;
}

void TilePlacementState::MoveRight()
{
	curCol += 1;
}

void TilePlacementState::MoveLeft()
{
	curCol -= 1;
}

void TilePlacementState::MoveUp()
{
	curRow += 1;
}

void TilePlacementState::MoveDown()
{
	curRow -= 1;
}

void TilePlacementState::PlaceTile()
{
	Tile*** board = ((InClassProj*)mStateMachine)->GetBoard();
	if (board[curCol][curRow] == NULL)
	{
		board[curCol][curRow] = TileToBePlaced;
	}
	Next = true;
}

void TilePlacementState::UpdateKeyboardInput(float dt)
{
	if (GetAsyncKeyState('W') & 0x8000)
	{
		if (!IsWPressed)
		{
			MoveUp();
		}
		IsWPressed = true;
	}
	else if (!GetAsyncKeyState('W'))
	{
		IsWPressed = false;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{

		if (!IsAPressed)
		{
			MoveLeft();
		}
		IsAPressed = true;
	}
	else if (!GetAsyncKeyState('A'))
	{
		IsAPressed = false;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		if (!IsSPressed)
		{
			MoveDown();
		}
		IsSPressed = true;
	}
	else if (!GetAsyncKeyState('S'))
	{
		IsSPressed = false;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		if (!IsDPressed)
		{
			MoveRight();
		}
		IsDPressed = true;
	}
	else if (!GetAsyncKeyState('D'))
	{
		IsDPressed = false;
	}
	if (GetAsyncKeyState('P') & 0x8000)
	{
		if (!IsPPressed)
		{
			PlaceTile();
		}
		IsPPressed = true;
	}
	else if (!GetAsyncKeyState('P'))
	{
		IsPPressed = false;
	}


}

