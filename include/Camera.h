#pragma once
#include "main.h"
#include "GameObject.h"
#include "Game.h"
#include "Player.h"

class Camera : public Player
{
private:
	int cameraX = (move_x + 98 / 2) - SCREEN_WIDTH / 2;
	int cameraY = (move_y + 87 / 2) - SCREEN_HEIGHT / 2;
public:
	void update();
};