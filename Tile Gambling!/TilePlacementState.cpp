#include "TilePlacementState.h"
#include "InClassProj.h"
#include "State.h"


void TilePlacementState::Init()
{
	mCurrState = TILE_MOVE;
	DealCard(mStateMachine->GetDevice());
}

void TilePlacementState::Update(float dt)
{
	curCol;
	curRow;

	TileToBePlaced->SetPos(XMVectorSet(TilePos.x, TilePos.y, 0.0f, 1.0f));

	UpdateKeyboardInput(dt);
	if (Next)
	{
		Next = false;
		mStateMachine->SetCurrState(mNextState);
	}
	
}

void  TilePlacementState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
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
}

void TilePlacementState::DealCard(ID3D11Device* device)
{

	//srand(time(NULL));

	TilePos.x = (curCol - 125) * 250;
	TilePos.y = (curRow - 125) * 250;
	
	std::vector<Tile::Frame*> Lvl1 = ((InClassProj*)mStateMachine)->GetTileLvl1();
	//std::vector<Tile::Frame*> Lvl2 = ((InClassProj*)mStateMachine)->GetTileLvl2();
	//std::vector<Tile::Frame*> Lvl3 = ((InClassProj*)mStateMachine)->GetTileLvl3();
	//std::vector<Tile::Frame*> Lvl4 = ((InClassProj*)mStateMachine)->GetTileLvl4();
	//std::vector<Tile::Frame*> Lvl5 = ((InClassProj*)mStateMachine)->GetTileLvl5();
	int randCard = rand() % 30;
	tile.clear();
	for (int i = randCard; i < Lvl1.size(); ++i)
	{
		//if (Lvl1[i]->Terrain == 1)
		//{
			tile.push_back(Lvl1[i]);
		//}
	}

	TileToBePlaced = new Tile(XMVectorSet(TilePos.x, TilePos.y, 0.0f, 1.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 250, 250, 0.0f, tile, 1.0f, device);

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
		
	board[curCol][curRow] = TileToBePlaced;

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

