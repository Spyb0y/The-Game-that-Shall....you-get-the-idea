#include "TilePlacementState.h"
#include "InClassProj.h"
#include "State.h"



void TilePlacementState::Update(float dt)
{
	UpdateKeyboardInput(dt);
	if (Next)
	{
		Next = false;
		mStateMachine->SetCurrState(mNextState);
	}

}

void  TilePlacementState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
//	Tile* tile = ((InClassProj*)mStateMachine)->GetTileLvl1();
	//std::vector<Sprite::Frame*> tile = ((InClassProj*)mStateMachine)->GetVec();

//	tile->Draw(vp, context, litTexEffect);


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

	srand(time(NULL));

	std::vector<Tile::Frame*> Lvl1 = ((InClassProj*)mStateMachine)->GetTileLvl1();
	std::vector<Tile::Frame*> Lvl2 = ((InClassProj*)mStateMachine)->GetTileLvl2();
	std::vector<Tile::Frame*> Lvl3 = ((InClassProj*)mStateMachine)->GetTileLvl3();
	std::vector<Tile::Frame*> Lvl4 = ((InClassProj*)mStateMachine)->GetTileLvl4();
	std::vector<Tile::Frame*> Lvl5 = ((InClassProj*)mStateMachine)->GetTileLvl5();

	if (!boss1Defeated)
	{
		int randCard = rand() % 15;
		for (int i = randCard; i < Lvl1.size(); ++i)
		{
			if (Lvl1[i]->Terrain = 1)
			{
				tile.push_back(Lvl1[i]);
			}
			else if (Lvl1[i]->Terrain = 2)
			{
				tile.push_back(Lvl1[i]);
			}
		}
	}
	else if (!boss2Defeated)
	{
		int randCard = rand() % 15;
		for (int i = randCard; i < Lvl2.size(); ++i)
		{
			if (Lvl2[i]->Terrain = 1)
			{
				tile.push_back(Lvl2[i]);
			}
			else if
			(Lvl2[i]->Terrain = 2)
			{
				tile.push_back(Lvl1[i]);
			}
		}
	}
	else if (!boss3Defeated)
	{
		int randCard = rand() % 15;
		for (int i = randCard; i < Lvl3.size(); ++i)
		{
			if (Lvl3[i]->Terrain = 1)
			{
				tile.push_back(Lvl3[i]);
			}
			else if (Lvl3[i]->Terrain = 2)
			{
				tile.push_back(Lvl3[i]);
			}
			else if (Lvl3[i]->Terrain = 3)
			{
				tile.push_back(Lvl3[i]);
			}
		}
	}
	else if (!boss4Defeated)
	{
		int randCard = rand() % 15;
		for (int i = randCard; i < Lvl4.size(); ++i)
		{
			if (Lvl4[i]->Terrain = 1)
			{
				tile.push_back(Lvl4[i]);
			}
			else if (Lvl4[i]->Terrain = 2)
			{
				tile.push_back(Lvl4[i]);
			}
			else if (Lvl4[i]->Terrain = 3)
			{
				tile.push_back(Lvl4[i]);
			}
			else if (Lvl4[i]->Terrain = 4)
			{
				tile.push_back(Lvl4[i]);
			}
		}
	}
	else if (!boss5Defeated)
	{
		int randCard = rand() % 15;
		for (int i = randCard; i < Lvl5.size(); ++i)
		{
			if (Lvl5[i]->Terrain = 1)
			{
				tile.push_back(Lvl5[i]);
			}
			else if (Lvl5[i]->Terrain = 2)
			{
				tile.push_back(Lvl5[i]);
			}
			else if (Lvl5[i]->Terrain = 3)
			{
				tile.push_back(Lvl5[i]);
			}
			else if (Lvl5[i]->Terrain = 4)
			{
				tile.push_back(Lvl5[i]);
			}
			else if (Lvl5[i]->Terrain = 5)
			{
				tile.push_back(Lvl5[i]);
			}

		}
	}
	else
	{
		//Game over, Victory
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
	Tile* tile = ((InClassProj*)mStateMachine)->GetTile();

	board[curCol][curRow] = tile;

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

