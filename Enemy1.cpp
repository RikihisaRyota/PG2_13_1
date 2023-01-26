#include "Enemy1.h"
#include "Collision.h"

bool Enemy1::Flag;

Enemy1::Enemy1()
{
	mInitPosition = { 1280.0f * 0.5f,720.0f * 0.5f };
	Init();
}

Enemy1::Enemy1(Vec2& pos)
{
	mInitPosition = pos;
	Init();
}

Enemy1::Enemy1(Vec2 pos,float t)
{
	mInitPosition = pos;
	Init();
	mVector.x = t;
}

void Enemy1::Init()
{
	mPosition = mInitPosition;
	mCircle = { mPosition ,(float)mRadius };
	mVector = { 0.0f,0.0f };
	mVelocity = { 0.0f,0.0f };
	mRadius = 30;
	mSpeed = 2.0f;
	mColor = 0xFFFFFF00;
	mBrightness = 0xFF;
	mIsAlive = false;
	mTextureWidth = 32;
	mTextureHeight = 32;
	mTexture = 0;
	mQuad = { mPosition,mRadius ,mRadius };


	Flag = true;
}

void Enemy1::Update()
{
}

void Enemy1::Update(Player& player)
{
	Move();

	Collision(player);
}

void Enemy1::Update(char* keys)
{
}

void Enemy1::Collision()
{
}

void Enemy1::Collision(Player& player)
{
	if (mPosition.x < 0 + mRadius || mPosition.x > 1280 - mRadius) {
		mVector.x *= -1;
	}
	if (Collision::QuadToQuad(player.playerBullet->GetmQuad(), mQuad)) {
		Delete();
	}
}

void Enemy1::Draw()
{
}

void Enemy1::Draw(Screen& screen)
{
	if (Flag) {
		screen.DrawQuad2(mQuad, 0.0f, 0.0f, mTextureWidth, mTextureHeight, mTexture, mColor + mBrightness, kFillModeSolid);
	}
}
	

void Enemy1::Move()
{
	mVelocity = mVector * mSpeed;
	mPosition += mVelocity;
	mQuad = { mPosition,mRadius ,mRadius };
}

void Enemy1::Move(char* keys)
{
}

void Enemy1::Delete()
{
	Flag = false;
}
