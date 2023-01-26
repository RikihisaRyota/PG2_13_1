#pragma once
#include "Object.h"
#include "Player.h"
class Enemy1:public Object
{
public:
	static bool Flag;

	Enemy1();
	Enemy1(Vec2& pos);
	Enemy1(Vec2 pos, float t);
	void Init() override;
	void Update()override;
	void Update(char* keys)override;
	void Collision()override;
	void Draw() override;
	void Draw(Screen& screen)override;
	void Move()override;
	void Move(char* keys) override;
	void Delete() override;

	void Update(Player& player);
	void Collision(Player& player);

private:
	Vec2 mInitPosition;
};

