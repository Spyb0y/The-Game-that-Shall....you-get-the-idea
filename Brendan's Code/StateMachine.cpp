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
	
}

Sprite::Frame* StateMachine::GetCurrTile()
{
	mCurrentTile = ((TilePlacementState*)mTilePlacement)->GetCurrentTile();
	return mCurrentTile;
}

bool StateMachine::GetBool1()
{
	boss1 = ((BattleState*)mBattlePhase)->GetBoss1Bool();
	return boss1;
}
bool StateMachine::GetBool2()
{
	boss2 = ((BattleState*)mBattlePhase)->GetBoss2Bool();
	return boss2;
}
bool StateMachine::GetBool3()
{
	boss3 = ((BattleState*)mBattlePhase)->GetBoss3Bool();
	return boss3;
}
bool StateMachine::GetBool4()
{
	boss4 = ((BattleState*)mBattlePhase)->GetBoss4Bool();
	return boss4;
}
bool StateMachine::GetBool5()
{
	boss5 = ((BattleState*)mBattlePhase)->GetBoss5Bool();
	return boss5;
}
