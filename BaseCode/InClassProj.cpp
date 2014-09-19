//
//***************************************************************************************

#include "d3dApp.h"
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
#include "Effect.h"
#include "FontRasterizer.h"
#include "Terrain.h"
#include "Player.h"
//#include "SkyBox.h"
#include "Sprite.h"
#include "Tile.h"

#include "xnacollision.h"
//#include "fmod.hpp"

struct TestParticle
{
	XMFLOAT3 pos;
	XMFLOAT3 vel;
	XMFLOAT2 size;
};

const int MAX_PARTICLES = 100000;

class InClassProj : public D3DApp
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
//	Player* mHero;
	//SkyBox* mSkyBox;
	BasicModel* mBarnProjectile;
	BasicModel* mFarmModel;
	Sprite* mTestSprite;

//	std::vector<Character*> mTestChars;

	std::vector<Tile*> mTiles;

	std::vector<Projectile*> mProjectiles;
	std::vector<TestParticle> mParticles;

//	ID3D11Buffer* mParticleVB;
//	ID3D11ShaderResourceView* mParticleTexture;

	ID3D11BlendState* mAdditiveBS;
	ID3D11BlendState* mTransparentBS;
	ID3D11DepthStencilState* mNoDepthDS;
	ID3D11DepthStencilState* mFontDS;

	enum GameStates 
	{
		gs_START,
		gs_DRAWPHASE,
		gs_PLAYERTURN


	};
	GameStates mCurrentGameState; 

	bool mMouseReleased;
	POINT mLastMousePos;
};

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
: D3DApp(hInstance), mLitTexEffect(0), mMouseReleased(true), mCam(0), mHero(0), mTestTerrain(0), mCurrentGameState(gs_START)
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

	srand((UINT)time(NULL));
}

InClassProj::~InClassProj()
{
	Vertex::CleanLayouts();


	if (mTestTerrain)
		delete mTestTerrain;

//	if (mTiles)
//		delete mTiles;

	if (mLitTexEffect)
		delete mLitTexEffect;

	if (mHero)
		delete mHero;

	if (mCam)
		delete mCam;

	if (m2DCam)
		delete m2DCam;

	if (mParticleEffect)
		delete mParticleEffect;

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
	mPointLight.pos = XMFLOAT3(50.0f, 50.0f, 50.0f);
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

	mAmbientColour = XMFLOAT4(0.3f, 0.3f, 0.3f, 1.0f);
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

	mParticleEffect = new ParticleEffect();
	mParticleEffect->LoadEffect(L"FX/Particles.fx", md3dDevice);

	Vertex::InitLitTexLayout(md3dDevice, mLitTexEffect->GetTech());

	XMVECTOR pos = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR look = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR scale = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	mCam = new ThirdPersonCam(mHero, 8.0f, 3.0f, 3.0f);
	mCam->Update();

	m2DCam = new BaseCamera(XMVectorSet(0.0f, 0.0f, -0.5f, 0.0f), XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f),
		XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));

	m2DCam->Update();

	BuildSceneLights();

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
	terrainInfo.heightScale = 175.0f;
	terrainInfo.texTilesWide = 10.0f;
	terrainInfo.texTilesHigh = 10.0f;

	mTestTerrain = new Terrain();
	mTestTerrain->Init(md3dDevice, terrainInfo);

	
	Vertex::InitTerrainVertLayout(md3dDevice, mTestTerrain->GetEffect()->GetTech());
	Vertex::InitParticleVertLayout(md3dDevice, mParticleEffect->GetTech());

	//mSkyBox = new SkyBox(md3dDevice, 500.0f, L"Textures/sunsetcube1024.dds");

	mBarnProjectile = new BasicModel(md3dDevice, mLitTexEffect, "Models/Wolf.obj",
		false, true);
//	BuildParticleVB();

//	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/DarkParticle.png",
//		0, 0, &mParticleTexture, 0);

	BuildBlendStates();
	BuildDSStates();

	// Test Barns
/*	Character* newBarn = new Character(XMVectorSet(5.0f, 0.0f, 5.0f, 0.0f),
		XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),
		*mFarmModel);

	mTestChars.push_back(newBarn);*/

	ID3D11ShaderResourceView* font;
	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/font.png",
		0, 0, &font, 0);

	mFont = new FontRasterizer(m2DCam, XMLoadFloat4x4(&m2DProj),
		mLitTexEffect, 10, 10, font, md3dDevice);

	Sprite::Frame* newFrame = new Sprite::Frame();
	ID3D11ShaderResourceView* image;
	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/WalkAnim.png",
		0, 0, &image, 0);

	
	newFrame->imageWidth = 2048;
	newFrame->imageHeight = 512;
	newFrame->x = 0;
	newFrame->y = 0;
	newFrame->image = image;

	std::vector<Sprite::Frame*> frames;
	frames.push_back(newFrame);

	newFrame = new Sprite::Frame();
	newFrame->imageWidth = 2048;
	newFrame->imageHeight = 512;
	newFrame->x = 512;
	newFrame->y = 0;
	newFrame->image = image;

	frames.push_back(newFrame);

	newFrame = new Sprite::Frame();
	newFrame->imageWidth = 2048;
	newFrame->imageHeight = 512;
	newFrame->x = 1024;
	newFrame->y = 0;
	newFrame->image = image;

	frames.push_back(newFrame);


	mTestSprite = new Sprite(XMVectorSet(mClientWidth / 2.0f, mClientHeight / 2.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f), 512, 512, 0.1f, frames, 0.25f, md3dDevice);
	mHero = new Player(XMVectorSet(mClientWidth / 2.0f, mClientHeight / 2.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f), 512, 512, 0.1f, frames, 0.25f, md3dDevice);
	//pos, scale, frameWidth, frameHeight, depth, frames, frameRate, device

	for (int i = 0; i < mTiles.size(); ++i)
	{
		mTiles[i] = new Tile(XMVectorSet(mClientWidth / 2.0f, mClientHeight / 2.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f), 512, 512, 0.1f, frames, 0.25f, md3dDevice);//DrawTile();
	}

	mTestSprite->Play(true);

	//result = sys->playSound(sound1, 0, false, &channel);

	return true;
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
	UpdateKeyboardInput(dt);
	RECT screenRect;
	screenRect.left = 0;
	screenRect.right = mClientWidth;
	screenRect.top = 0;
	screenRect.bottom = mClientHeight;
	//ClipCursor(&screenRect);

	XMVECTOR camPos = mCam->GetPos();

	camPos = XMVectorSet(camPos.m128_f32[0], mTestTerrain->GetHeight(camPos.m128_f32[0],
	camPos.m128_f32[2]) + 4.0f,
	camPos.m128_f32[2], 1.0f);

	mCam->SetPos(camPos);
//	mHero->AddForce(XMVectorSet(0.0f, -20.0f * dt, 0.0f, 0.0f));

	mHero->Update(dt);
//	mTiles->Update(dt);

	switch (mCurrentGameState)
	{
		case gs_START:

			break;

		case gs_DRAWPHASE:
			
			break;

		case gs_PLAYERTURN:
			
			break;
	}

	if (gs_DRAWPHASE)
	{
		Tile::Frame* newTileFrame = new Tile::Frame();
		ID3D11ShaderResourceView* tileImage;
		D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/WalkAnim.png",
			0, 0, &tileImage, 0);
		newTileFrame->imageWidth = 2048;
		newTileFrame->imageHeight = 512;
		newTileFrame->x = 0;
		newTileFrame->y = 0;
		newTileFrame->image = tileImage;

		std::vector<Sprite::Frame*> frames;
		frames.push_back(newTileFrame);

		mCurrentGameState = gs_PLAYERTURN;
	}

	XMVECTOR playerPos = mHero->GetPos();
	XMVECTOR toPlayer = playerPos - mCam->GetPos();
	toPlayer = XMVector3Normalize(toPlayer);
	mCam->SetFacing(toPlayer, XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
	mCam->SetPos(XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
	mCam->SetFacing(XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f));
	mCam->Update();

	m2DCam->Update();

	XMStoreFloat3(&mSpotLight.pos, mCam->GetPos());
	XMStoreFloat3(&mSpotLight.direction, mCam->GetLook());

//	UpdateParticleVB();

	mTestSprite->Update(dt);

	//sys->update();
}

void InClassProj::DrawScene()
{
//	md3dImmediateContext->ClearRenderTargetView(mRenderTargetView,
//		reinterpret_cast<const float*>(&Colors::White));
	md3dImmediateContext->ClearDepthStencilView(mDepthStencilView,
		D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	md3dImmediateContext->IASetInputLayout(Vertex::GetNormalTexVertLayout());
	md3dImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	XMVECTOR ambient = XMLoadFloat4(&mAmbientColour);
	XMVECTOR eyePos = XMVectorSet(mCam->GetPos().m128_f32[0], mCam->GetPos().m128_f32[1],
		mCam->GetPos().m128_f32[2], 0.0f);

	XMMATRIX proj = XMLoadFloat4x4(&m2DProj);
	XMMATRIX view = mCam->GetView();

	mLitTexEffect->SetPerFrameParams(ambient, eyePos, mPointLight, mSpotLight);
	mTestTerrain->GetEffect()->SetPerFrameParams(ambient, eyePos, mPointLight, mSpotLight);

	XMMATRIX vp = view * proj;

	mTestTerrain->Draw(md3dImmediateContext, vp);

//	XMMATRIX proj = XMLoadFloat4x4(&mProj);
//	XMMATRIX view = mCam->GetView();

	mLitTexEffect->SetPerFrameParams(ambient, eyePos, mPointLight, mSpotLight);
	mTestTerrain->GetEffect()->SetPerFrameParams(ambient, eyePos, mPointLight, mSpotLight);

//	XMMATRIX vp = view * proj;

	mTestTerrain->Draw(md3dImmediateContext, vp);

	

	vp = XMMatrixIdentity();
	proj = XMLoadFloat4x4(&m2DProj);
	view = m2DCam->GetView();

	vp = vp * view * proj;

	//mTestTerrain->Draw(md3dImmediateContext, vp);

	md3dImmediateContext->IASetInputLayout(Vertex::GetNormalTexVertLayout());
	md3dImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	md3dImmediateContext->OMSetBlendState(mTransparentBS, blendFactor, 0xffffffff);
	md3dImmediateContext->OMSetDepthStencilState(mFontDS, 0);

	vp = XMMatrixIdentity();
	proj = XMLoadFloat4x4(&m2DProj);
	view = m2DCam->GetView();

	vp = vp * view * proj;



	mTestSprite->Draw(vp, md3dImmediateContext, mLitTexEffect);
	mHero->Draw(vp, md3dImmediateContext, mLitTexEffect);

	mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f),
		50, 75, 10, "This is font");
	md3dImmediateContext->OMSetDepthStencilState(0, 0);
	//md3dImmediateContext->OMSetBlendState(0, blendFactor, 0xffffffff);

	HR(mSwapChain->Present(1, 0));
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
		/*bool isPlaying = false;
		channel->isPlaying(&isPlaying);
		if(!isPlaying)
		{
		result = sys->playSound(sound1, 0, false, &channel);
		}*/
		if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
		{
			
		}
		else
		{
			
		}
	}


}
