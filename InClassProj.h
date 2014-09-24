#include "d3dApp.h"
#include "StateMachine.h"
#include "d3dx11Effect.h"
#include "MathHelper.h"
#include "LightHelper.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "Vertex.h"
#include "Quad.h"
#include "ThirdPersonCam.h"
#include "Cube.h"
#include "GraphicalObject.h"
#include "Projectile.h"
//#include "Effect.h"
#include "FontRasterizer.h"
#include "Terrain.h"
#include "Player.h"
//#include "SkyBox.h"
#include "Sprite.h"
#include "Tile.h"
#include "State.h"
#include "PlayerInterface.h"
#include <string>
#include <sstream>
#include <iostream>
#include <array>

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


private:
	void BuildTestPyramid();
	void BuildVertexLayout();
	void BuildSceneLights();
	void BuildParticleVB();
	void BuildBlendStates();
	void BuildDSStates();

	void UpdateParticleVB();
	void UpdateKeyboardInput(float dt);

	XMVECTOR CylToCyl(FXMVECTOR c1Pos, float c1Rad, float c1Height, FXMVECTOR c2Pos, float c2Rad, float c2Height);

	//	void DrawParticles();


private:

	LitTexEffect* mLitTexEffect;
	ParticleEffect* mParticleEffect;

	ThirdPersonCam* mCam;
	BaseCamera* m2DCam;

	FontRasterizer* mFont;

	XMFLOAT4 mAmbientColour;
	XMFLOAT4X4 mView;
	XMFLOAT4X4 mProj;
	XMFLOAT4X4 m2DProj;

	PointLightOptimized mPointLight;
	SpotLightOptimized mSpotLight;

	Player* mHero;
	//Tile* mTile;

	Terrain* mTestTerrain;
	//SkyBox* mSkyBox;
	BasicModel* mBarnProjectile;
	BasicModel* mFarmModel;
	Sprite* mTestSprite;

	//	std::vector<Character*> mTestChars;


	std::vector<Projectile*> mProjectiles;
	std::vector<TestParticle> mParticles;
	std::vector<Sprite::Frame*> mTileFrames;

	//	ID3D11Buffer* mParticleVB;
	//	ID3D11ShaderResourceView* mParticleTexture;

	ID3D11BlendState* mAdditiveBS;
	ID3D11BlendState* mTransparentBS;
	ID3D11DepthStencilState* mNoDepthDS;
	ID3D11DepthStencilState* mFontDS;

	Player* player;
	float test;

	Sprite::Frame* tile;
	Sprite::Frame* tile2;

	std::vector<Tile::Frame*> mTiles;
	Tile*** board;



	/*enum GameStates
	{
	gs_START,
	gs_DRAWPHASE,
	gs_TILEPLACEMENT,
	gs_PLAYERMOVE,
	gs_BATTLEPHASE,
	gs_LOOTPHASE,
	gs_ENEMYPHASE,
	gs_GAMEOVER,
	gs_HANDMENU,
	gs_MAINMENU
	};
	GameStates mCurrentGameState; */

	enum TileFrames
	{
		FOREST1,
		GRASS1,
		FOREST2
	};

	bool mMouseReleased;
	POINT mLastMousePos;
};