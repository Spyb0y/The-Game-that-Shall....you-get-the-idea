#pragma once
#include "d3dApp.h"
#include "d3dx11Effect.h"
#include "MathHelper.h"
#include "LightHelper.h"
#include "Vertex.h"
#include "FontRasterizer.h"
#include "xnacollision.h"

#include "StateMachine.h"
#include "StartTurnState.h"
#include "TilePlacementState.h"
#include "DrawTileCard.h"
#include "BeginState.h"
#include "BattleState.h"
#include "PlayerTurnState.h"
#include "StartTurnState.h"
#include "EnemyTurnState.h"
#include "GameOverState.h"
#include "GameWonState.h"

#include "Player.h"
//#include "PlayerTile.h"
#include "Sprite.h"
#include "Tile.h"
#include "State.h"
#include "PlayerInterface.h"
#include "Enemy.h"
#include "Item.h"
#include "Equipment.h"
#include "Inventory.h"

#include "Terrain.h"
#include "ThirdPersonCam.h"

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <array>



//#include "fmod.hpp"
using namespace std;

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
	void UpdateKeyboardInput(float dt);

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
	std::vector<Sprite::Frame*> GetHomeVec() const;
	std::vector<Tile::Frame*> GetPlayerTile() const;
	FontRasterizer* GetFont();
	Sprite::Frame* GetTile();
	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetContext();
	ID3D11BlendState* GetTransparentBS();
	ID3D11DepthStencilState* GetFontDS();
	Player* GetPlayer() const;

	int GetXPos();
	int GetYPos();

	int CamUp();
	int CamDown();
	int CamRight();
	int CamLeft();


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
	Player* mHero;
	Enemy* mEnemy;
	Inventory* mInventory;
	//PlayerTile* mPlayerTile;

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
	std::vector<Sprite::Frame*> homeTile2;

//	std::vector<Tile::Frame*>mPlayerTile() const;

//	std::vector<Tile::Frame*> PlayerTile();

	Tile*** board;

	bool isPressed;

	XMFLOAT2 TilePos;

	bool mMouseReleased;
	POINT mLastMousePos;

	int camY;
	int camX;
};