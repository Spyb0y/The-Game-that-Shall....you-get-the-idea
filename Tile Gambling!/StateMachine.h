#pragma once
class State;

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
	State* mGameWon;;
	

};

