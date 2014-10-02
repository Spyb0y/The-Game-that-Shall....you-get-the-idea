#include "d3dApp.h"
#include "StateMachine.h"
#include "d3dx11Effect.h"
#include "MathHelper.h"
#include "LightHelper.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Terrain.h"
#include "ThirdPersonCam.h"
#include "Vertex.h"
#include "FontRasterizer.h"
#include "Player.h"
#include "Sprite.h"
#include "Tile.h"
#include "State.h"
#include "PlayerInterface.h"
#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include "Enemy.h"
#include "Item.h"
#include "Equipment.h"
#include "Inventory.h"
#include "StartTurnState.h"

#include "xnacollision.h"
//#include "fmod.hpp"
using namespace std;

struct TestParticle
{
	XMFLOAT3 pos;
	XMFLOAT3 vel;
	XMFLOAT2 size;
};

const int MAX_PARTICLES = 100000;

class InClassProj : public D3DApp, public StateMachine
{
public:
	InClassProj(HINSTANCE hInstance);
	~InClassProj();

	bool Init();
	bool DrawNewTile;
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

	void OnMouseDown(WPARAM btnState, int x, int y);
	void OnMouseUp(WPARAM btnState, int x, int y);
	void OnMouseMove(WPARAM btnState, int x, int y);

	void GetImage() const;
	Tile*** GetBoard() const;
	std::vector<Tile::Frame*> GetTileLvl1() const;
	std::vector<Tile::Frame*> GetTileLvl2() const;
	std::vector<Tile::Frame*> GetTileLvl3() const;
	std::vector<Tile::Frame*> GetTileLvl4() const;
	std::vector<Tile::Frame*> GetTileLvl5() const;



private:
	void BuildTestPyramid();
	void BuildVertexLayout();
	void BuildSceneLights();
	void BuildBlendStates();
	void BuildDSStates();

	
private:

	LitTexEffect* mLitTexEffect;
	
	ThirdPersonCam* mCam;
	BaseCamera* m2DCam;
	Terrain* mTestTerrain;
	Player* mPlayer;
	Enemy* mEnemy;

	FontRasterizer* mFont;

	XMFLOAT4 mAmbientColour;
	XMFLOAT4X4 mView;
	XMFLOAT4X4 mProj;
	XMFLOAT4X4 m2DProj;

	PointLightOptimized mPointLight;
	SpotLightOptimized mSpotLight;

	ID3D11BlendState* mAdditiveBS;
	ID3D11BlendState* mTransparentBS;
	ID3D11DepthStencilState* mNoDepthDS;
	ID3D11DepthStencilState* mFontDS;

	float test;
	float enemyHealth;

	Sprite::Frame* tile;
	Sprite::Frame* tile2;

	std::vector<Tile::Frame*> TileLvl1;
	std::vector<Tile::Frame*> TileLvl2;
	std::vector<Tile::Frame*> TileLvl3;
	std::vector<Tile::Frame*> TileLvl4;
	std::vector<Tile::Frame*> TileLvl5;
	std::vector<Tile::Frame*> mTiles;
	Tile*** board;
	
	bool isPressed;

	XMFLOAT2 TilePos;

	bool mMouseReleased;
	POINT mLastMousePos;
};