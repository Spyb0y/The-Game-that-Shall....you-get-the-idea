#include "PlayerTurnState.h"
#include "InClassProj.h"
#include "PlayerTurnState.h"

void PlayerTurnState::Init()
{
	mPlace = new TilePlacementState(mStateMachine);
	
	col = mPlace->GetCurrCol();
	row = mPlace->GetCurrRow();

	Tile::Frame* playerTile = new Tile::Frame();
	ID3D11ShaderResourceView* image;
	D3DX11CreateShaderResourceViewFromFile(mStateMachine->GetDevice(), L"Textures/playerTile.png",
		0, 0, &image, 0);
	playerTile->imageWidth = 250;
	playerTile->imageHeight = 250;
	playerTile->x = 0;
	playerTile->y = 0;
	playerTile->image = image;
	playerTile->Terrain = 2;
	playerTile->Level = 5;
	playerTile->Direction = 24;
	//playerTile->isUp = true;
	//playerTile->isDown = true;
	//playerTile->isLeft = true;
	//playerTile->isRight = true;
	mPlayerTile.push_back(playerTile);

	PlayerPos.x = (col - 125) * 250;
	PlayerPos.y = (row - 125) * 250;
	PlayerTile = new Tile(XMVectorSet(PlayerPos.x, PlayerPos.y, 0.0f, 1.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 250, 250, 0.0f, mPlayerTile, 1.0f, mStateMachine->GetDevice());
}

void PlayerTurnState::Update(float dt)
{
	col;
	row;
	PlayerTile->SetPos(XMVectorSet(PlayerPos.x, PlayerPos.y, 0.0f, 1.0f));
	UpdateKeyboardInput(dt);
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
					showItemState = true;
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
					Next = true;
					isLClicked = true;
				}
			}
			else
			{
				isLClicked = false;
			}
		}

	}

	if (xPos >= 700 && xPos <= 900)
	{
		if (yPos >= 0 && yPos <= 200)
		{
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				if (!isLClicked)
				{
					showItemState = true;
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
	if (showItemState)
	{
		drawItemMenu = true;
		if (Next)
		{
		mNextState->Init();
		mStateMachine->SetCurrState(mNextState);
		}
	}
	if (showEquipState)
	{
		drawEquipMenu = true;
		if (Next)
		{
			mNextState->Init();
			mStateMachine->SetCurrState(mNextState);
		}
	}
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
	if (drawItemMenu)
	{
		DrawItemMenu(context);
	}
	if (drawEquipMenu)
	{
		DrawEquipMenu(context);
	}
}

void PlayerTurnState::DrawItemMenu(ID3D11DeviceContext* context)
{
	string sItemsDisplay = mHero->DisplayItems().str();
	mFont->DrawFont(context, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 25, 25, 15, sItemsDisplay);
}

void PlayerTurnState::DrawEquipMenu(ID3D11DeviceContext* context)
{
	string sItemsDisplay = mHero->DisplayItems().str();
	mFont->DrawFont(context, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 25, 25, 15, sItemsDisplay);
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
