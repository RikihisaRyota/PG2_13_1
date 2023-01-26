#include "Player.h"
#include <Novice.h>
Player::Player()
{
	Bullet();
	Init();
}

void Player::Init()
{
	mPosition = { 1280.0f / 2.0f ,720.0f / 2.0f - 200.0f };
	mCircle = { mPosition ,(float)mRadius };
	mVector = { 0.0f,0.0f };
	mVelocity = { 0.0f,0.0f };
	mRadius = 50;
	mSpeed = 10.0f;
	mColor = 0xFFFFFF00;
	mBrightness = 0xFF;
	mIsAlive = true;
	mTextureWidth = 32;
	mTextureHeight = 32;
	mTexture = 0;
	mQuad = { mPosition,mRadius ,mRadius };
	mBulletCount = 0;
	mBulletCoolTime = 10;
	mBulletCoolTimeFlag = false;
	mIsShot = false;
}

void Player::Update()
{
}

void Player::Update(char* keys)
{
	Move(keys);
	
	BulletUpdate(keys);

	Collision();
}

void Player::Collision()
{
}

void Player::Draw()
{
}

void Player::Move(char* keys)
{
	mVector = { 0.0f,0.0f };
	if (keys[DIK_A] != 0) {
		mVector.x = -1.0f;
	}
	if (keys[DIK_D] != 0) {
		mVector.x = 1.0f;
	}
	if (keys[DIK_W] != 0) {
		mVector.y = 1.0f;
	}
	if (keys[DIK_S] != 0) {
		mVector.y = -1.0f;
	}
	mVector = mVector.Normalized();
	mVelocity = mVector * mSpeed;
	mPosition += mVelocity;
	mQuad = { mPosition,mRadius ,mRadius };
}

void Player::Delete()
{
}
  void Player::BulletUpdate(char* keys)
{
	//生成
	{
		if (keys[DIK_SPACE] != 0 && !mBulletCoolTimeFlag) {
			for (int i = 0; i < playerBulletMax; i++) {
				if (!playerBullet[i].GetmIsAlive() && mBulletCount % mBulletCoolTime == 0) {
					playerBullet[i].Set(mPosition);
					break;
				}
			}
			mBulletCoolTimeFlag = true;
			mIsShot = true;
		}
		else {
			mIsShot = false;
		}
		///クールタイム
		if (mBulletCoolTimeFlag) {
			mBulletCount++;
			if (mBulletCount > mBulletCoolTime) {
				mBulletCoolTimeFlag = false;
				mBulletCount = 0;
			}
		}
		
		
	}
	//弾の動き
	for (int i = 0; i < playerBulletMax; i++) {
		playerBullet[i].Update();
	}
}

void Player::Draw(Screen& screen)
{
	screen.DrawQuad2(mQuad, 0.0f, 0.0f, mTextureWidth, mTextureHeight, mTexture,mColor + mBrightness, kFillModeSolid);
	for (int i = 0; i < playerBulletMax; i++) {
		playerBullet[i].Draw(screen);
	}
}

void Player::Move()
{
}