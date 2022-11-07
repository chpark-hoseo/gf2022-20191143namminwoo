#include "Monster.h"
void Monster::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Monster::update(/*int speed, int length*/)
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);

	m_x += m_speed;
	if (m_x == m_length)
	{
		m_speed = -m_speed;
	}
	else if (m_x == 0)
	{
		m_speed = -m_speed;
	}
}
