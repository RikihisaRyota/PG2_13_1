#pragma once
#include "Vec2.h"
#include "Quad.h"
#include "Circle.h"
#include "Screen.h"
class Object
{
protected:
	Quad mQuad;
	Circle mCircle;
	Vec2 mPosition;
	Vec2 mVector;
	Vec2 mVelocity;
	unsigned int mColor;
	unsigned int mBrightness;
	int mRadius;
	float mSpeed;
	bool mIsAlive;
	int mTextureWidth;
	int mTextureHeight;
	int mTexture;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Update(char* keys) = 0;
	virtual void Collision() = 0;
	virtual void Draw() = 0;
	virtual void Draw(Screen& screen) = 0;
	virtual void Move() = 0;
	virtual void Move(char* keys) = 0;
	virtual void Delete() = 0;

	///テンプレ
	/*
	void Init() override;
	void Update()override;
	void Update(char* keys)override;
	void Collision()override;
	void Draw() override;
	void Draw(Screen& screen)override;
	void Move()override;
	void Move(char* keys) override;
	void Delete() override;
	*/
	//ゲッター
	Quad GetmQuad() {
		return mQuad;
	}
	Circle GetmCircle() {
		return mCircle;
	}
	Vec2 GetmPosition() {
		return mPosition;
	}
	Vec2 GetmVector() {
		return mVector;
	}
	Vec2 GetmVelocity() {
		return mVector;
	}
	unsigned int GetmColor() {
		return mColor;
	}
	unsigned int GetmBrightness() {
		return mBrightness;
	}
	int GetmRadius() {
		return mRadius;
	}
	float GetmSpeed() {
		return mSpeed;
	}
	bool GetmIsAlive() {
		return mIsAlive;
	}
	int GetmTextureWidth() {
		return mTextureWidth;
	}
	int GetmTextureHeight() {
		return mTextureHeight;
	}
	int GetmTexture() {
		return mTexture;
	}
};