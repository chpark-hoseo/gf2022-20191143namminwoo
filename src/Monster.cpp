#include "Monster.h"
#include "main.h"
Monster::Monster(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Monster::draw()
{
	SDLGameObject::draw();
}
void Monster::update()
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
void Monster::clean() {}

