//
//***************************************************************************************
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include "d3dApp.h"
#include "StateMachine.h"
#include "d3dx11Effect.h"
#include "MathHelper.h"
#include "LightHelper.h"
#include "Terrain.h"
#include "ThirdPersonCam.h"
#include "Vertex.h"
#include "FontRasterizer.h"
#include "Player.h"
#include "Sprite.h"
#include "Tile.h"
#include "State.h"
#include "Enemy.h"
#include "Item.h"
#include "Equipment.h"
#include "Inventory.h"
#include "TilePlacementState.h"
#include "DrawTileCard.h"
#include "BeginState.h"
#include "BattleState.h"
#include "PlayerTurnState.h"
#include "StartTurnState.h"
#include "EnemyTurnState.h"
#include "GameOverState.h"
#include "GameWonState.h"
#include "xnacollision.h"
#include "InClassProj.h"
//#include "fmod.hpp"
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	InClassProj theApp(hInstance);



	if (!theApp.Init())
		return 0;



	return theApp.Run();
}


InClassProj::InClassProj(HINSTANCE hInstance)
	: D3DApp(hInstance), StateMachine(), mLitTexEffect(0), mMouseReleased(true), mCam(0), mTestTerrain(0)
{
	XMVECTOR pos = XMVectorSet(1.0f, 1.0f, 5.0f, 0.0f);
	XMVECTOR look = XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f);
	XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	mMainWndCaption = L"Box Demo";

	mLastMousePos.x = 0;
	mLastMousePos.y = 0;

	XMMATRIX I = XMMatrixIdentity();
	XMStoreFloat4x4(&mView, I);
	XMStoreFloat4x4(&mProj, I);
	XMStoreFloat4x4(&m2DProj, I);

	mBegin = new BeginState((InClassProj*)this);
	mTilePlacement = new TilePlacementState((InClassProj*)this);
	mBattlePhase = new BattleState((InClassProj*)this);
	mPlayerTurn = new PlayerTurnState((InClassProj*)this);
	mEnemyTurn = new EnemyTurnState((InClassProj*)this);
	mGameOver = new GameOverState((InClassProj*)this);
	mGameWon = new GameWonState((InClassProj*)this);

	mBegin->SetNextState(mTilePlacement);
	mTilePlacement->SetNextState(mBattlePhase);
	mBattlePhase->SetNextState(mTilePlacement);

	mCurrState = mBegin;

	srand((UINT)time(NULL));
}

InClassProj::~InClassProj()
{
	Vertex::CleanLayouts();


	if (mTestTerrain)
		delete mTestTerrain;

	if (mLitTexEffect)
		delete mLitTexEffect;

	if (mHero)
		delete mHero;
	
	if (mCam)
		delete mCam;

	if (m2DCam)
		delete m2DCam;

	if (mAdditiveBS)
		ReleaseCOM(mAdditiveBS);

	if (mTransparentBS)
		ReleaseCOM(mTransparentBS);

	if (mNoDepthDS)
		ReleaseCOM(mNoDepthDS);
}

void InClassProj::BuildSceneLights()
{
	/* test code, test a point light out */
/*	mPointLight.pos = XMFLOAT3(50.0f, 50.0f, 50.0f);
	mPointLight.lightColour = XMFLOAT4(0.75f, 0.75f, 0.75f, 1.0f);
	mPointLight.range = 1000.0f;
	mPointLight.att = XMFLOAT3(0.0f, 0.02f, 0.0f);
	mPointLight.pad = 0.0f;

	mSpotLight.pos = XMFLOAT3(mCam->GetPos().m128_f32[0], mCam->GetPos().m128_f32[1], mCam->GetPos().m128_f32[2]);
	mSpotLight.lightColour = XMFLOAT4(0.75f, 0.75f, 0.75f, 1.0f);
	mSpotLight.range = 100.0f;
	mSpotLight.att = XMFLOAT3(0.0f, 0.25f, 0.0f);
	XMVECTOR temp = XMVectorSet(-mSpotLight.pos.x, -mSpotLight.pos.y,
		-mSpotLight.pos.z, 0.0f);
	temp = XMVector3Normalize(temp);
	XMStoreFloat3(&mSpotLight.direction, temp);
	mSpotLight.spot = 128.0f;

	mAmbientColour = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);*/
}

/* FMOD_RESULT result;
FMOD::System     *sys;
FMOD::Sound      *sound1, *sound2, *sound3;
FMOD::Channel    *channel = 0;
unsigned int      version;
void             *extradriverdata = 0;
*/


bool InClassProj::Init()
{
	if (!D3DApp::Init())
		return false;

	/*
	Create a System object and initialize
	*/
	/*result = FMOD::System_Create(&sys);

	result = sys->getVersion(&version);


	if (version < FMOD_VERSION)
	{
	OutputDebugString(L"FMOD lib version doesn't match header version");
	}

	result = sys->init(32, FMOD_INIT_NORMAL, extradriverdata);


	result = sys->createSound("Sounds/drumloop.wav", FMOD_DEFAULT, 0, &sound1);
	*/
	//result = sound1->setMode(FMOD_LOOP_OFF);
	DrawNewTile = false;

	mLitTexEffect = new LitTexEffect();
	mLitTexEffect->LoadEffect(L"FX/lighting.fx", md3dDevice);

	Vertex::InitLitTexLayout(md3dDevice, mLitTexEffect->GetTech());

	XMVECTOR pos = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR look = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR scale = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	//mCam = new ThirdPersonCam(mTestSprite, 8.0f, 3.0f, 3.0f);
	//mCam->Update();

	m2DCam = new BaseCamera(XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f), XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),
		XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));

	m2DCam->Update();

//	BuildSceneLights();

	Terrain::InitInfo terrainInfo;
	terrainInfo.cellHeight = 10.0f;
	terrainInfo.cellWidth = 10.0f;
	terrainInfo.height = 256;
	terrainInfo.width = 256;
	terrainInfo.heightMapFilename = L"Textures/HeightMapHills2.raw";
	terrainInfo.layerMapFilename0 = L"Textures/pavedTexture.png";
	terrainInfo.layerMapFilename1 = L"Textures/darkdirt.dds";
	terrainInfo.layerMapFilename2 = L"Textures/lightdirt.dds";
	terrainInfo.layerMapFilename3 = L"Textures/grass.dds";
	terrainInfo.blendMapFilename = L"Textures/texMapHills.png";
	terrainInfo.heightScale = 1.0f;
	terrainInfo.texTilesWide = 10.0f;
	terrainInfo.texTilesHigh = 10.0f;

	mTestTerrain = new Terrain();
	mTestTerrain->Init(md3dDevice, terrainInfo);

	
	Vertex::InitTerrainVertLayout(md3dDevice, mTestTerrain->GetEffect()->GetTech());

	BuildBlendStates();
	BuildDSStates();

	ID3D11ShaderResourceView* font;
	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/font.png",
		0, 0, &font, 0);

	mFont = new FontRasterizer(m2DCam, XMLoadFloat4x4(&m2DProj),
		mLitTexEffect, 10, 10, font, md3dDevice);

	///////////////////////////////////////////////////////////////////////////////////////////////////////
	///CASTLE TILES

	Tile::Frame* newTile = new Tile::Frame();
	ID3D11ShaderResourceView* image;
	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/TileSheet.png",
		0, 0, &image, 0);

	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 0;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 10;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 250;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 11;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 500;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 12;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 750;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 13;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 1000;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 14;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 1250;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 15;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 1500;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 15;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 1750;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 15;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 2000;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 16;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 2250;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 17;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 2500;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 18;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 2750;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 19;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 3000;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 20;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 3250;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 21;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 3500;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 22;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 3750;
	newTile->y = 0;
	newTile->image = image;
	newTile->Terrain = 2;
	newTile->Level = 5;
	newTile->Direction = 23;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///FOREST TILES

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 0;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 10;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 250;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 11;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 500;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 12;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 750;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 13;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 1000;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 14;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 1250;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 15;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 1500;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 16;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 1750;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 17;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 2000;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 18;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 2250;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 19;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 2500;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 20;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 2750;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 21;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 3000;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 22;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 3250;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 23;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->x = 3500;
	newTile->y = 250;
	newTile->image = image;
	newTile->Terrain = 1;
	newTile->Level = 5;
	newTile->Direction = 24;

	TileLvl1.push_back(newTile);
	TileLvl2.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Swamp///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	newTile = new Tile::Frame();//North
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 0;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 10;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//East
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 250;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 11;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//South
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 500;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 12;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//West
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 750;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 13;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//North - East
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 1000;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 14;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//South - East
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 1250;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 15;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//South - West
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 1500;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 16;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//North - West
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 1750;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 17;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//North - South
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 2000;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 18;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//East -West
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 2250;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 19;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//North - East - South
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 2500;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 20;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//East - South - West
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 2750;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 21;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//North - South - West
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 3000;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 22;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//North - East - West
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 3250;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 23;

	TileLvl5.push_back(newTile);
	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);

	newTile = new Tile::Frame();//4 Way Tile
	newTile->imageWidth = 3500;
	newTile->imageHeight = 1000;
	newTile->y = 500;
	newTile->x = 3500;
	newTile->image = image;
	newTile->Terrain = 3;
	newTile->Level = 9;
	newTile->Direction = 24;

	TileLvl3.push_back(newTile);
	TileLvl4.push_back(newTile);
	TileLvl5.push_back(newTile);

	//Mountain Tiles ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	newTile = new Tile::Frame();//North
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 0;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 10;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//East
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 250;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 11;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//South
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 500;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 12;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//West
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 750;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 13;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//North - East
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 1000;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 14;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//South - East
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 1250;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 15;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//South - West
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 1500;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 16;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//North - West
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 1750;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 17;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//North - South
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 2000;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 18;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//East -West
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 2250;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 19;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//North - East - South
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 2500;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 20;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//East - South - West
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 2750;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 21;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//North - South - West
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 3000;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 22;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//North - East - West
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 3250;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 23;

	TileLvl5.push_back(newTile);

	newTile = new Tile::Frame();//4 Way Tile
	newTile->imageWidth = 3750;
	newTile->imageHeight = 1000;
	newTile->y = 750;
	newTile->x = 3500;
	newTile->image = image;
	newTile->Terrain = 4;
	newTile->Level = 9;
	newTile->Direction = 24;

	TileLvl5.push_back(newTile);

	/////////////////////////////////////////////////////////////////////////////////////

	//result = sys->playSound(sound1, 0, false, &channel);
	test = 0;
	enemyHealth = 0;

	Tile::Frame* homeTile = new Tile::Frame();
	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/TileSheet.png",
		0, 0, &image, 0);
	homeTile->imageWidth = 3750;
	homeTile->imageHeight = 1000;
	homeTile->x = 3500;
	homeTile->y = 0;
	homeTile->image = image;
	homeTile->Terrain = 2;
	homeTile->Level = 5;
	homeTile->Direction = 24;
	mTiles.push_back(homeTile);

	board = new Tile**[250];
	for (int i = 0; i < 250; ++i)
	{
		board[i] = new Tile*[250];
		for (int j = 0; j < 250; ++j)
		{
			board[i][j] = NULL;
		}

	}
	int homeCol = ((TilePlacementState*)mTilePlacement)->GetCurrCol();
	int homeRow = ((TilePlacementState*)mTilePlacement)->GetCurrRow();
	//int curCol = ((TilePlacementState*)mTilePlacement)->GetCurrCol();
	//int curRow = ((TilePlacementState*)mTilePlacement)->GetCurrRow();

	std::vector<Sprite::Frame*> homeTile2;
	homeTile2.push_back(mTiles[0]);
	//board[125][125] = new Tile(XMVectorSet((homeCol - 125) * 250, (homeRow - 125) * 250, 0.0f, 0.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 250, 250, 0.0f, homeTile, 1.0f, md3dDevice);
	board[125][125] = new Tile(XMVectorSet(250.0f, 500.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 250, 250, 0.0f, homeTile2, 1.0f, md3dDevice);

	//TilePos.x = (curCol - 125) * 250;
	//TilePos.y = (curRow - 125) * 250;

	//std::vector<Sprite::Frame*> tile = ((StartTurnState*)mStartTurn)->GetTileVec();
	//tile.push_back(mTiles[1]);
	//TileToBePlaced = new Tile(XMVectorSet(TilePos.x, TilePos.y, 0.0f, 1.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f), 250, 250, 0.0f, tile, 1.0f, md3dDevice);

	//int currTile = board[curCol][curRow];

	isPressed = false;

	mHero = new Player();
	((BattleState*)mBattlePhase)->SetPlayer(mHero);

	mInventory = new Inventory();
	((BattleState*)mBattlePhase)->SetInventory(mInventory);

	mInventory->createItemVectors();
	mInventory->CreateEnemyVectors();

	return true;

	
}

std::vector<Tile::Frame*> InClassProj::GetTileLvl1() const
{
	return TileLvl1;
}
std::vector<Tile::Frame*> InClassProj::GetTileLvl2() const
{
	return TileLvl2;
}
std::vector<Tile::Frame*> InClassProj::GetTileLvl3() const
{
	return TileLvl3;
}
std::vector<Tile::Frame*> InClassProj::GetTileLvl4() const
{
	return TileLvl4;
}
std::vector<Tile::Frame*> InClassProj::GetTileLvl5() const
{
	return TileLvl5;
}

Tile*** InClassProj::GetBoard() const
{
	return (Tile***)board;
}

void InClassProj::BuildBlendStates()
{
	D3D11_BLEND_DESC bsDesc = { 0 };
	bsDesc.AlphaToCoverageEnable = false;
	bsDesc.IndependentBlendEnable = false;

	bsDesc.RenderTarget[0].BlendEnable = true;
	bsDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
	bsDesc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
	bsDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	bsDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	bsDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	bsDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	bsDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	HR(md3dDevice->CreateBlendState(&bsDesc, &mAdditiveBS));

	bsDesc.RenderTarget[0].BlendEnable = true;
	bsDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	bsDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;

	HR(md3dDevice->CreateBlendState(&bsDesc, &mTransparentBS));
}

void InClassProj::BuildDSStates()
{
	D3D11_DEPTH_STENCIL_DESC dsDesc;
	dsDesc.DepthEnable = true;
	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;
	dsDesc.StencilEnable = false;
	dsDesc.StencilReadMask = 0xff;
	dsDesc.StencilWriteMask = 0xff;

	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// We are not rendering backfacing polygons, so these settings do not matter.
	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	HR(md3dDevice->CreateDepthStencilState(&dsDesc, &mNoDepthDS));

	dsDesc.DepthEnable = false;
	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;
	dsDesc.StencilEnable = false;
	dsDesc.StencilReadMask = 0xff;
	dsDesc.StencilWriteMask = 0xff;

	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// We are not rendering backfacing polygons, so these settings do not matter.
	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	HR(md3dDevice->CreateDepthStencilState(&dsDesc, &mFontDS));
}

void InClassProj::OnResize()
{
	D3DApp::OnResize();

	// The window resized, so update the aspect ratio and recompute the projection matrix.
	XMMATRIX P = XMMatrixPerspectiveFovLH(0.25f*MathHelper::Pi, AspectRatio(), 1.0f, 1000.0f);
	XMStoreFloat4x4(&mProj, P);

	P = XMMatrixOrthographicOffCenterLH(0.0f, mClientWidth, 0.0f, mClientHeight, 0.0001f, 1000.0f);
	XMStoreFloat4x4(&m2DProj, P);
}

float timer = 0.0f;
void InClassProj::UpdateScene(float dt)
{
	((TilePlacementState*)mTilePlacement)->Init();
	//mCurrState->Init();
	mCurrState->Update(dt);

	RECT screenRect;
	screenRect.left = 0;
	screenRect.right = mClientWidth;
	screenRect.top = 0;
	screenRect.bottom = mClientHeight;
	//ClipCursor(&screenRect);

	std::vector<Sprite::Frame*> frames;

	m2DCam->Update();
}

void InClassProj::DrawScene()
{
	md3dImmediateContext->ClearRenderTargetView(mRenderTargetView,
		reinterpret_cast<const float*>(&Colors::Blue));
	md3dImmediateContext->ClearDepthStencilView(mDepthStencilView,
		D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	md3dImmediateContext->IASetInputLayout(Vertex::GetNormalTexVertLayout());
	md3dImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	XMVECTOR ambient = XMLoadFloat4(&mAmbientColour);
	/*XMVECTOR eyePos = XMVectorSet(mCam->GetPos().m128_f32[0], mCam->GetPos().m128_f32[1],
		mCam->GetPos().m128_f32[2], 0.0f);

	/*XMMATRIX proj = XMLoadFloat4x4(&m2DProj);
	XMMATRIX view = mCam->GetView();

	mLitTexEffect->SetPerFrameParams(ambient, eyePos, mPointLight, mSpotLight);
	mTestTerrain->GetEffect()->SetPerFrameParams(ambient, eyePos, mPointLight, mSpotLight);

	XMMATRIX vp = view * proj;

	mTestTerrain->Draw(md3dImmediateContext, vp);

	
	XMMATRIX view = mCam->GetView();

	mLitTexEffect->SetPerFrameParams(ambient, eyePos, mPointLight, mSpotLight);
	mTestTerrain->GetEffect()->SetPerFrameParams(ambient, eyePos, mPointLight, mSpotLight);*/

	//XMMATRIX proj = XMLoadFloat4x4(&mProj);
	//XMMATRIX view = m2DCam->GetView();
	//XMMATRIX vp = view * proj;



	//mSkyBox->Draw(md3dImmediateContext, vp, mCam->GetPos());

	//mTestTerrain->Draw(md3dImmediateContext, vp);

	XMMATRIX vp = XMMatrixIdentity();
	XMMATRIX proj = XMLoadFloat4x4(&m2DProj);
	XMMATRIX view = m2DCam->GetView();

	vp = vp * view * proj;

	//mTestTerrain->Draw(md3dImmediateContext, vp);
	mCurrState->Draw(vp, md3dImmediateContext, mLitTexEffect);

	//string sItemsDisplay = mHero->DisplayItems().str();
		
	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	md3dImmediateContext->OMSetBlendState(mTransparentBS, blendFactor, 0xffffffff);
	md3dImmediateContext->OMSetDepthStencilState(mFontDS, 0);

	//mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 50, 50, 15, sItemsDisplay);
	md3dImmediateContext->OMSetDepthStencilState(0, 0);
	md3dImmediateContext->OMSetBlendState(0, blendFactor, 0xffffffff);

	HR(mSwapChain->Present(1, 0));

}

void InClassProj::ItemMenu()
{
	//string sItemsDisplay = mHero->DisplayItems().str();
	//mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 300.0f, 0.0f, 0.0f), 25, 25, 15, sItemsDisplay);
}

int InClassProj::GetXPos()
{
	return mLastMousePos.x;
}

int InClassProj::GetYPos()
{
	return mLastMousePos.y;
}

FontRasterizer* InClassProj::GetFont()
{
	return mFont;
}

Sprite::Frame* InClassProj::GetTile()
{
	return mTiles[0];
}

ID3D11Device* InClassProj::GetDevice()
{
	return md3dDevice;
}

ID3D11DeviceContext* InClassProj::GetContext()
{
	return md3dImmediateContext;
}

ID3D11BlendState* InClassProj::GetTransparentBS()
{
	return mTransparentBS;
}

ID3D11DepthStencilState* InClassProj::GetFontDS()
{
	return mFontDS;
}

void InClassProj::OnMouseDown(WPARAM btnState, int x, int y)
{
	mLastMousePos.x = x;
	mLastMousePos.y = y;

	if ((btnState & MK_RBUTTON) != 0)
	{
		
	}

	if ((btnState & MK_LBUTTON) != 0)
	{
		
	}

	SetCapture(mhMainWnd);
}

void InClassProj::OnMouseUp(WPARAM btnState, int x, int y)
{
	mMouseReleased = false;


	ReleaseCapture();


}

void InClassProj::OnMouseMove(WPARAM btnState, int x, int y)
{

	// Make each pixel correspond to a quarter of a degree.
	float dx = XMConvertToRadians(0.25f*static_cast<float>(x - mLastMousePos.x));
	float dy = XMConvertToRadians(0.25f*static_cast<float>(y - mLastMousePos.y));

	//mHero->Pitch(dy);
	//mHero->YawGlobal(dx);


	mLastMousePos.x = x;
	mLastMousePos.y = y;
}

void InClassProj::UpdateKeyboardInput(float dt)
{
	if (GetAsyncKeyState('W') & 0x8000)
	{
		
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		
		
	}
	if (GetAsyncKeyState('P') & 0x8000)
	{
		
	}


}