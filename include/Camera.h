#pragma once
#include "SDLGameObject.h"

#define SCREEN_WIDTH 1000 //���̴� ȭ�� ����
#define SCREEN_HEIGHT 800
#define LEVEL_WIDTH 11600 //��ü ȭ�� ����
#define LEVEL_HEIGHT 10000

class Camera : public SDLGameObject
{
public :
	Camera(const LoaderParams* pParams);
	virtual void update();	

	static float cameraX;
	static float cameraY;

};