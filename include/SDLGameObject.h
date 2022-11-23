#pragma once
// #include "main.h"
#include "GameObject.h"
 #include "Vector2D.h"

//class Vector2D;

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {}
	virtual ~SDLGameObject() {}
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};