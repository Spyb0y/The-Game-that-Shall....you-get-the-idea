#include "PlayerTurnState.h"
#include "InClassProj.h"
#include "PlayerTurnState.h"

void PlayerTurnState::Init()
{
	mPlace = new TilePlacementState(mStateMachine);
	std::vector<Tile::Frame*> pTile = ((InClassProj*)mStateMachine)->GetPlayerTile();
	col = mPlace->GetCurrCol();
	row = mPlace->GetCurrRow();
	PlayerPos.x = (col - 125) * 250;
	PlayerPos.y = (row - 125) * 250;
	PlayerTile = new Tile(XMVectorSet(PlayerPos.x, PlayerPos.y, 0.0f, 1.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 250, 250, 0.0f, pTile, 1.0f, mStateMachine->GetDevice());
}

void PlayerTurnState::Update(float dt)
{
	col;
	row;
	PlayerTile->SetPos(XMVectorSet(PlayerPos.x, PlayerPos.y, 0.0f, 1.0f));
	UpdateKeyboardInput(dt);
	
	if (Next)
	{
		Next = false;
		mStateMachine->SetCurrState(mNextState);
	}
}

void PlayerTurnState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{
	PlayerTile->Draw(vp, context, litTexEffect);
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

void PlayerTurnState::MoveRight()
{
	col += 1;
}

void PlayerTurnState::MoveLeft()
{
	col -= 1;
}

void PlayerTurnState::MoveUp()
{
	row += 1;
}

void PlayerTurnState::MoveDown()
{
	row -= 1;
}

void PlayerTurnState::UpdateKeyboardInput(float dt)
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
	/*if (GetAsyncKeyState('P') & 0x8000)
	{
		if (!IsPPressed)
		{
			
		}
		IsPPressed = true;
	}
	else if (!GetAsyncKeyState('P'))
	{
		IsPPressed = false;
	}*/


}
