#pragma once
#include "d3dUtil.h"
#include "BaseCamera.h"

class Sprite;

class ThirdPersonCam : public BaseCamera
{
public:
	ThirdPersonCam();
	ThirdPersonCam(Sprite* target, float offsetLook, float offsetUp, float targetYOffset);
	~ThirdPersonCam();

	void Pitch(float angle);

	virtual void Update();
	void SetTarget(Sprite* target)
	{
		mTarget = target;
	}

	void ChangeTargetOffset(float diff)
	{
		mTargetYOffset += diff;
	}

protected:
	float mOffsetLook;
	float mOffsetUp;
	void YawLocal(float angle);
	
	float mTargetYOffset;
	Sprite* mTarget;
};

