#include "Bullet.h"

Bullet::Bullet()
{
	Init();
}

void Bullet::Init()
{
	mPosition = { 1280.0f / 2.0f ,720.0f / 2.0f };
	mCircle = { mPosition ,(float)mRadius };
	mVector = { 0.0f,0.0f };
	mVelocity = { 0.0f,0.0f };
	mRadius = 20;
	mSpeed = 20.0f;
	mColor = 0xFFFFFF00;
	mBrightness = 0xFF;
	mIsAlive = false;
	mTextureWidth=32;
	mTextureHeight=32;
	mTexture = 0;
	mQuad = { mPosition,mRadius ,mRadius };

	mBulletMode = Normal;
}

void Bullet::Update()
{
	Move();
	Delete();
}

void Bullet::Update(char* keys)
{
}

void Bullet::Collision()
{
}

void Bullet::Draw()
{
}

void Bullet::Move()
{
	if (mIsAlive) {
		switch (mBulletMode)
		{
		case Normal:
			mVector = { 0.0f,1.0f };
			mVelocity = mVector * mSpeed;
			mPosition += mVelocity;
			mQuad = { mPosition,mRadius ,mRadius };
			break;
		case Bezier:
			break;
		default:
			break;
		}
	}
}

void Bullet::Move(char* keys)
{
}

void Bullet::Set(Vec2& position)
{
	if (!mIsAlive) {
		mPosition = position;
		mIsAlive = true;
	}
}

void Bullet::Delete()
{
	if (mIsAlive) {
		if (mPosition.y > SCREEN_HEIGHT + mRadius) {
			mIsAlive = false;
		}
	}
}

void Bullet::Draw(Screen& screen)
{
	if (mIsAlive) {
		screen.DrawQuad2(mQuad,0.0f, 0.0f,mTextureWidth,mTextureHeight,mTexture, mColor + mBrightness);
	}
}