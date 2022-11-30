#pragma once
#include "SDLGameObject.h"
#include "Player.h"

class Camera : public SDLGameObject
{
protected :
	int cameraX = 0, cameraY = 0;

public:
	virtual void cameraMove();
};
