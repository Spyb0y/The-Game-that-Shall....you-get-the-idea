#pragma once
class State;

class StateMachine
{
public:
	StateMachine();
	~StateMachine()
	{
		delete mStartTurn;
		delete mTilePlacement;
	}

	void SetCurrState(State* newState)
	{
		mCurrState = newState;
	}

protected:
	State* mCurrState;
	State* mStartTurn;
	State* mTilePlacement;

};

