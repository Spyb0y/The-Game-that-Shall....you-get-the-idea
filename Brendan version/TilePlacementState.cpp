#include "TilePlacementState.h"
#include "InClassProj.h"
#include "State.h"



void TilePlacementState::Update(float dt)
{
	UpdateKeyboardInput(dt);
	if (Next)
	{
		mStateMachine->SetCurrState(mNextState);
	}
}

void  TilePlacementState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
	Tile* tile = ((InClassProj*)mStateMachine)->GetTile();
	//std::vector<Sprite::Frame*> tile = ((InClassProj*)mStateMachine)->GetVec();
	
	tile->Draw(vp, context, litTexEffect);


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

