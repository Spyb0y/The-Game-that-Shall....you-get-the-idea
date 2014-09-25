#include "InClassProj.h"
#include "BattleState.h"

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
: D3DApp(hInstance), mLitTexEffect(0), mMouseReleased(true), mCam(0), mHero(0), mTestTerrain(0), StateMachine()
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

	//if (mParticleEffect)
		//delete mParticleEffect;

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

	//mParticleEffect = new ParticleEffect();
	//mParticleEffect->LoadEffect(L"FX/Particles.fx", md3dDevice);

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
	//Vertex::InitParticleVertLayout(md3dDevice, mParticleEffect->GetTech());

	//mSkyBox = new SkyBox(md3dDevice, 500.0f, L"Textures/sunsetcube1024.dds");
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


	Tile::Frame* newTileFrame = new Tile::Frame();
	ID3D11ShaderResourceView* tileImage;
	D3DX11CreateShaderResourceViewFromFile(md3dDevice, L"Textures/TestTexture.png", 0, 0, &tileImage, 0);
	newTileFrame->imageWidth = 1024;
	newTileFrame->imageHeight = 1024;
	newTileFrame->x = 0;
	newTileFrame->y = 0;
	newTileFrame->image = tileImage;
//	frames.push_back(newFrame);
	mTileFrames.push_back(newTileFrame);

	//mTestSprite = new Sprite(XMVectorSet(mClientWidth / 2.0f, mClientHeight / 2.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f), 512, 512, 0.1f, frames, 0.25f, md3dDevice);
//the following line uses Player as though it inherits from the Sprite class and will not work with Rhyse's new code
	mHero = new Player();//XMVectorSet(mClientWidth / 2.0f, mClientHeight / 2.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f), 512, 512, 0.1f, frames, 0.25f, md3dDevice
	//pos, scale, frameWidth, frameHeight, depth, frames, frameRate, device
	((BattleState*)mBattlePhase)->SetPlayer(mHero);

	mInventory = new Inventory();
	((BattleState*)mBattlePhase)->SetInventory(mInventory);

	mTestEnemy = new Basilisk();
	((BattleState*)mBattlePhase)->SetEnemy(mTestEnemy);
	
	mInventory->createItemVectors();

	//mTestSprite->Play(true);

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


	std::vector<Sprite::Frame*> frames;

	//XMVECTOR camPos = mCam->GetPos();

	//camPos = XMVectorSet(camPos.m128_f32[0], mTestTerrain->GetHeight(camPos.m128_f32[0],
	//camPos.m128_f32[2]) + 4.0f,
	//camPos.m128_f32[2], 1.0f);

	//mCam->SetPos(camPos);
//	mHero->AddForce(XMVectorSet(0.0f, -20.0f * dt, 0.0f, 0.0f));

//	mHero->Update(dt);
//	mTiles->Update(dt);


	/*XMVECTOR playerPos = mTestSprite->GetPos();
	XMVECTOR toPlayer = playerPos - mCam->GetPos();
	toPlayer = XMVector3Normalize(toPlayer);
	mCam->SetFacing(toPlayer, XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
	mCam->SetPos(XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
	mCam->SetFacing(XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f));
	mCam->Update();*/

	m2DCam->Update();

//	XMStoreFloat3(&mSpotLight.pos, mCam->GetPos());
//	XMStoreFloat3(&mSpotLight.direction, mCam->GetLook());

	//mCurrState->Update(dt);
//	UpdateParticleVB();

//	mTestSprite->Update(dt);

	//sys->update();
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
	
	std::stringstream ss;
	ss << mHero->GetPlayerAttack();
	string s = ss.str();
		
	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	md3dImmediateContext->OMSetBlendState(mTransparentBS, blendFactor, 0xffffffff);
	md3dImmediateContext->OMSetDepthStencilState(mFontDS, 0);
	mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 200.0f, 0.0f, 0.0f), 50, 50, 15, s);
	md3dImmediateContext->OMSetDepthStencilState(0, 0);
	md3dImmediateContext->OMSetBlendState(0, blendFactor, 0xffffffff);

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
			//for (int i = 0; i < mTiles.size(); ++i)
			//{

			//	mTiles[i]->MoveRight(100.0f);
			//}
		}
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		mHero->Attack(mTestEnemy);
		if (mTestEnemy->GetEnemyHealth() <= 0)
		{
			int level = mTestEnemy->GetEnemyLevel();
			mTestEquip = mInventory->SelectEquip(level);
			mTestItem = mInventory->SelectItem(level);
			mHero->GetEquipment(mHero, mTestEquip);
			mHero->GetItem(mTestItem);
			//delete mTestEnemy;
		}
		//else
		//{
		mTestEnemy->Attack(mHero);
		//}
		//if (mHero->GetPlayerHealth() <= 0)
		//{
		//	delete mHero;
		//}
	}


}


//For reference to States, this is not for actual use::: 
/*switch (mCurrentGameState)
{
case gs_START:
//place Home Tile
//Maybe show instructions
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Start Phase");
mCurrentGameState = gs_DRAWPHASE;
break;

case gs_DRAWPHASE:
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Draw Phase");
for (int i = 0; i < mTiles.size(); ++i)
{
mTiles[i] = new Tile(XMVectorSet(mClientWidth / 2.0f, mClientHeight / 2.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f), 512, 512, 0.1f, frames, 0.25f, md3dDevice);//DrawTile();
}


//mCurrentGameState = gs_TILEPLACEMENT;
mCurrentGameState = gs_START;
break;

case gs_TILEPLACEMENT:
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Tile placement");
//Tile move and placement code

mCurrentGameState = gs_PLAYERMOVE;
break;

case gs_PLAYERMOVE:
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Player Move Phase");
//Check to see if the player pauses at any point, and if so:
mCurrentGameState = gs_HANDMENU;

//player move code

//encounter code
//check for encounter
//if no encounter then:

mCurrentGameState = gs_ENEMYPHASE;

//if ecounter then:
mCurrentGameState = gs_BATTLEPHASE;
break;

case gs_BATTLEPHASE:
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Battle Phase");
//Check if Tile Explored
//if explored then check for chance of a monster
//if monster check passes then check the level and terrain of the tile entered
//if unexplored:
//Check level and terrain of tile entered
//monster chooser and spawn code
//BATTLE CODE
//Check if Battle won, if true then:
mCurrentGameState = gs_LOOTPHASE;
//else the player ran away in which case
mCurrentGameState = gs_ENEMYPHASE;
//else check for Loss and if true:
mCurrentGameState = gs_GAMEOVER;
break;

case gs_LOOTPHASE:
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Loot Phase");
//Check level of defeated enemy
//Check if enemy was boss
//If Boss: Give Player the Boss Item
//If no Boss: Spawn items according to Level of enemy

//Move Player Sprite into new Tile

//Check if Player still has moves left
//if yes then
mCurrentGameState = gs_PLAYERMOVE;

//if not then:
mCurrentGameState = gs_ENEMYPHASE;
break;

case gs_ENEMYPHASE:
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Enemy Phase");
//Stalker Spawn, check, and move code

mCurrentGameState = gs_DRAWPHASE;
break;

case gs_HANDMENU:
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Hand Menu");
//all of the game menu code involving the hand and equpiment go here
//the return button will:

mCurrentGameState = gs_PLAYERMOVE;
break;

case gs_MAINMENU:
//Ignore MAINMENU for now as it isn't needed in the Prototype
break;

case gs_GAMEOVER:
mFont->DrawFont(md3dImmediateContext, XMVectorSet(10.0f, 500.0f, 0.0f, 0.0f), 50, 75, 10, "Game Over");
//end the game
break;
}*/