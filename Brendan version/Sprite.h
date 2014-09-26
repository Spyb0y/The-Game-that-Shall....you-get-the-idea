#pragma once
#include "GraphicalGeometry.h"
#include "Effect.h"

class Sprite :
	public GraphicalGeometry
{
public:
	struct Frame
	{
		ID3D11ShaderResourceView* image;
		unsigned short x; //frame x location in pixels
		unsigned short y; //frame y location in pixels

		unsigned short imageWidth;
		unsigned short imageHeight;
	};

public:
	Sprite(FXMVECTOR pos2D, FXMVECTOR scale2D, unsigned short frameWidth, unsigned short frameHeight, float depth, const std::vector<Frame*>& frames, float frameRate, ID3D11Device* device);
	virtual ~Sprite();

	XMVECTOR GetPos() const
	{
		return XMLoadFloat2(&mPos);
	}

	void SetPos(FXMVECTOR pos)
	{
		XMStoreFloat2(&mPos, pos);
	}

	XMVECTOR GetScale() const
	{
		return XMLoadFloat2(&mScale);
	}

	void SetScale(FXMVECTOR scale)
	{
		XMStoreFloat2(&mScale, scale);
	}

	float GetDepth() const
	{
		return mDepth;
	}

	void SetDepth(float depth)
	{
		mDepth = depth;
	}

	float GetFrameRate() const
	{
		return mFrameRate;
	}

	void SetFrameRate(float frameRate)
	{
		mFrameRate = frameRate;
	}

	void Play(bool loop)
	{
		mLoop = loop;
		mPlaying = true;
	}

	void Pause()
	{
		mPlaying = false;
	}

	void Stop()
	{
		mPlaying = false;
		mFrameIndex = 0;
	}

	void SetFrame(unsigned short frame)
	{
		mFrameIndex = frame;
	}
	
	float GetAngle() const
	{
		return mAngle;
	}

	//note: angle is in radians
	void SetAngle(float angle)
	{
		mAngle = angle;
	}

	//note: angle is in radians
	void Rotate(float angle)
	{
		mAngle += angle;
	}

	void Draw(CXMMATRIX vp,
		ID3D11DeviceContext* context,
		LitTexEffect* litTexEffect);

	void Update(float dt);

protected:
	XMFLOAT2 mPos;
	XMFLOAT2 mScale;
	unsigned short mFrameWidth;
	unsigned short mFrameHeight;
	float mDepth;
	std::vector<Frame*> mFrames;
	float mFrameRate;
	bool mLoop;
	bool mPlaying;
	unsigned short mFrameIndex;
	float mAngle; //in radians
	float mCurrFrameTime;

	virtual void InitVB(ID3D11Device* device);
	virtual void InitIB(ID3D11Device* device);

	XMMATRIX GetWorld();

};

