#include "StateMachine.h"

#include "DrawTileCard.h"
#include "BeginState.h"
#include "BattleState.h"
#include "PlayerTurnState.h"
#include "StartTurnState.h"
#include "EnemyTurnState.h"
#include "GameOverState.h"
#include "GameWonState.h"

#include "TilePlacementState.h"


StateMachine::StateMachine()
{
	/*
	mBegin = new BeginState(this);
	mStartTurn = new DrawTileCard(this);
	mTilePlacement = new TilePlacementState(this);
	mBattlePhase = new BattleState(this);
	mPlayerTurn = new PlayerTurnState(this);
	mStartTurn = new StartTurnState(this);
	mEnemyTurn = new EnemyTurnState(this);
	mGameOver = new GameOverState(this);
	mGameWon = new GameWonState(this);

	mBegin->SetNextState(mTilePlacement);
	mTilePlacement->SetNextState(mBattlePhase);
	mBattlePhase->SetNextState(mTilePlacement);

	mCurrState = mBegin;*/
}

Sprite::Frame* StateMachine::GetCurrTile()
{
	mCurrentTile = ((TilePlacementState*)mTilePlacement)->GetCurrentTile();
	return mCurrentTile;
}