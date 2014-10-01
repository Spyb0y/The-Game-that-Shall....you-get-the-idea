#include "PlayerTurnState.h"
#include "StateMachine.h"

void PlayerTurnState::MoveRight()
{
	if (connectionRightToLeft)
	{
		curCol + 1;
	}
	else
	{
		//output error message saying direction is not available
	}

}

void PlayerTurnState::MoveLeft()
{
	if (connectionLeftToRight)
	{
		curCol - 1;
	}
	else
	{
		//output error message saying direction is not available
	}
}

void PlayerTurnState::MoveUp()
{
	if (connectionUpToDown)
	{
		curRow - 1;
	}
	else
	{
		//output error message saying direction is not available
	}
}

void PlayerTurnState::MoveDown()
{
	if (connectionDownToUp)
	{
		curRow + 1;
	}
	else
	{
		//output error message saying direction is not available
	}
}


void PlayerTurnState::CheckForBattle()
{
	
	//GetTileContents();
	

	bool curTileHasEnemy = tileContent->GetTileContents();

	if (curTileHasEnemy)
	{
		mStateMachine->SetCurrState(mNextState);
	}
	else
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
		
	}
}