#include <Novice.h>
#include "Player.h"
#include "Screen.h"
#include "Enemy1.h"

Player* player = new Player();
Enemy1* enemy_1 = new Enemy1({ 1280.0f * 0.5f , 720.0f * 0.5f + 200 }, 1.0f);
Enemy1* enemy_2 = new Enemy1({ 1280.0f * 0.5f , 720.0f * 0.5f + 100 }, -1.0f);
Screen screen;