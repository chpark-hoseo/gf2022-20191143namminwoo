#pragma once
#include "main.h"
#include "LoaderParams.h"
class GameObject {
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual ~GameObject() {}

protected:
	std::string m_textureID;

	GameObject(const LoaderParams* pParams) {}

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	int m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	int m_currentRow;

};
