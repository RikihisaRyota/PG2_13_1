#pragma once
#include "Object.h"
class Bullet:public Object
{
public:
	Bullet();
	void Init() override;
	void Update()override;
	void Update(char* keys)override;
	void Collision()override;
	void Draw() override;
	void Draw(Screen& screen)override;
	void Move()override;
	void Move(char* keys) override;
	void Delete() override;

	void Set( Vec2& position);

	enum BulletMode {
		Normal,
		Bezier,
	}mBulletMode;
};

