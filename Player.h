#pragma once
#include "Object.h"
#include "Bullet.h"
class Player :public Object
{
public:
	static const int playerBulletMax = 50;
	Bullet playerBullet[playerBulletMax];

	Player();
	//ƒeƒ“ƒvƒŒ
	void Init() override;
	void Update()override;
	void Update(char* keys)override;
	void Collision()override;
	void Draw() override;
	void Draw(Screen& screen)override;
	void Move()override;
	void Move(char* keys) override;
	void Delete() override;

	void BulletUpdate(char* key);

private:
	int mBulletCount;
	int mBulletCoolTime;
	bool mBulletCoolTimeFlag;
	bool mIsShot;
};

