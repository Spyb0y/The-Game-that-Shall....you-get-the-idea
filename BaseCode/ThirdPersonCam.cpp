#include "ThirdPersonCam.h"
#include "Sprite.h"


ThirdPersonCam::ThirdPersonCam(void) : BaseCamera(),
mOffsetLook(0.0f),
mOffsetUp(0.0f),
mTarget(0)
{
}

ThirdPersonCam::ThirdPersonCam(Sprite* target, float offsetLook, float offsetUp, float targetYOffset) : BaseCamera(),
mOffsetLook(offsetLook),
mOffsetUp(offsetUp),
mTarget(target),
mTargetYOffset(targetYOffset)
{
}


ThirdPersonCam::~ThirdPersonCam()
{
}

void ThirdPersonCam::Pitch(float angle)
{
	XMVECTOR right = XMLoadFloat3(&mRight);
	XMVECTOR look = XMLoadFloat3(&mLook);
	XMVECTOR up = XMLoadFloat3(&mUp);

	XMMATRIX rotate = XMMatrixRotationAxis(right, angle);

	look = XMVector3TransformNormal(look, rotate);
	up = XMVector3Cross(look, right);
	up = XMVector3Normalize(up);

	XMStoreFloat3(&mLook, look);
	XMStoreFloat3(&mUp, up);

	mViewUpdated = true;
}

void ThirdPersonCam::YawLocal(float angle)
{
	XMVECTOR right = XMLoadFloat3(&mRight);
	XMVECTOR look = XMLoadFloat3(&mLook);
	XMVECTOR up = XMLoadFloat3(&mUp);

	XMMATRIX rotate = XMMatrixRotationAxis(up, angle);

	right = XMVector3TransformNormal(right, rotate);
	look = XMVector3Cross(up, right);
	look = XMVector3Normalize(look);

	XMStoreFloat3(&mLook, look);
	XMStoreFloat3(&mRight, right);

	mViewUpdated = true;
}

void ThirdPersonCam::Update()
{
	if (mTarget != NULL)
	{
		XMVECTOR targetPos = mTarget->GetPos();
		XMVECTOR targetOffset = XMVectorSet(0.0f, mTargetYOffset, 0.0f, 0.0f);
		targetPos = targetPos;// +targetOffset;

		XMVECTOR pos = targetPos;
		XMStoreFloat3(&mPos, pos);

		targetPos = targetPos + targetOffset;

		XMVECTOR look = targetPos - pos;
		look = XMVector3Normalize(look);
		XMStoreFloat3(&mLook, look);

		XMVECTOR right = XMVector3Cross(look, XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));
		XMStoreFloat3(&mRight, right);
		XMVECTOR up = XMVector3Cross(right, look);
		XMStoreFloat3(&mUp, up);
		mViewUpdated = true;
	}
	BaseCamera::Update();

}