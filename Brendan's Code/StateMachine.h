#pragma once
#include "Sprite.h"
class State;
class TilePlacementState;
class BattleState;

class StateMachine
{
public:
	StateMachine();
	~StateMachine()
	{
		delete mBegin;
		delete mTilePlacement;
		delete mPlayerTurn;
		delete mBattlePhase;
		delete mEnemyTurn;
		delete mHandMenu;
		delete mGameOver;
		delete mGameWon;
	}

	Sprite::Frame* GetCurrTile();
	Sprite::Frame* mCurrentTile;
	bool GetBool1();
	bool GetBool2();
	bool GetBool3();
	bool GetBool4();
	bool GetBool5();
	bool boss1;
	bool boss2;
	bool boss3;
	bool boss4;
	bool boss5;


	void SetCurrState(State* newState)
	{
		mCurrState = newState;
	}

protected:
	State* mCurrState;
	State* mBegin;
	State* mTilePlacement; //move and place the tile
	State* mPlayerTurn; //counts the player's remaining moves and lets the player travel through tiles
	State* mBattlePhase; //have Loot, Run and Loss states/variables
	State* mEnemyTurn; //check for conditions to spawn Stalker. Move Stalker if he is spawned
	State* mHandMenu;
	State* mGameOver;
	State* mGameWon;

	
	

};

