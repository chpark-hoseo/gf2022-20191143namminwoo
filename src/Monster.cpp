#include "Monster.h"
void Monster::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Monster::update1()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);

	m_x += mob1_move;
	if (m_x == 500)
	{
		mob1_move = -10;
	}
	else if (m_x == 0)
	{
		mob1_move = 10;
	}
}
void Monster::update2()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);

	m_x += mob2_move;
	if (m_x == 400)
	{
		mob2_move = -5;
	}
	else if (m_x == 0)
	{
		mob2_move = 5;
	}
}
