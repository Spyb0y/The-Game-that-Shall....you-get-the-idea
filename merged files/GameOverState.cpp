#include "GameOverState.h"
#include "InClassProj.h"

void GameOverState::Init()

{
	PlayerDefeated = false;
}

void GameOverState::Update(float dt)
{
	PlayerDefeated = true;
	//check to see if PlayerIsDefeated
	if (PlayerDefeated)
	{
		CongratulateLoser();
	}
}


void GameOverState::CongratulateLoser()
{
	string mMessage = "You Lose.";
	mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 25, 25, 15, mMessage);
}
