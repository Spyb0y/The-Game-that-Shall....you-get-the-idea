#include "TilePlacementState.h"


void TilePlacementState::Update(float dt)
{
	switch (mCurrState)
	{
		case PlacementState::TILE_MOVE:
			break;
		case PlacementState::TILE_PLACE:
			break;
	}
}

void  TilePlacementState::Draw(CXMMATRIX vp, ID3D11DeviceContext* context, LitTexEffect* litTexEffect)
{

}