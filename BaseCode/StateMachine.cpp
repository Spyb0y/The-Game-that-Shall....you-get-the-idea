#include "StateMachine.h"

#include "DrawTileCard.h"


StateMachine::StateMachine()
{
	//mCurrState = new StartState(this);
	mStartTurn = new DrawTileCard(this);
	mTilePlacement = new TilePlacementState(this);

	mStartTurn->SetNextState(mTilePlacement);
	mTilePlacement->SetNextState(mStartTurn);

	mCurrState = mStartTurn;
}
