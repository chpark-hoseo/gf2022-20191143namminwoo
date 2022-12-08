#include "Monster.h"
#include "InputHandler.h"
#include "Game.h"
Monster::Monster(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Monster::handleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	if (m_Monster == true)
	{
		if (vec->getX() >= m_position.getX() && vec->getX() <= m_position.getX() + 147
			&& vec->getY() >= m_position.getY() && vec->getY() <= m_position.getY() + 154)
		{	//마우스 클릭하면 그림 지워지게
			if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
			{
				Game::m_gameover += 1;
				m_draw = true;
				m_Monster = false;
			}
		}
	}
	else if (m_Monster == false) return; //한번 클릭되고 나서는 삭제
}
void Monster::draw()
{
	if (m_draw == true)
	{

	}
	else
	{
		SDLGameObject::draw();
	}
}
void Monster::update()
{
	handleInput();
	move();
	m_currentFrame = ((SDL_GetTicks() / 100) % 5);

	if (moove == true)
	{
		m_velocity.setY(-10);
	}
	else if (moove == false)
	{
		m_velocity.setY(10);
	}

	SDLGameObject::update();
}
void Monster::move()
{
	if (m_position.getY() + 154 >= 800)
	{
		moove = true;
	}
	else if (m_position.getY() == 0)
	{
		moove = false;
	}
}

void Monster::clean() {}