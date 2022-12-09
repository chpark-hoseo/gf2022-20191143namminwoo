#include "Monster2.h"
#include "InputHandler.h"
#include "Game.h"
Monster2::Monster2(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Monster2::handleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	if (m_Monster2 == true)
	{
		if (vec->getX() >= m_position.getX() && vec->getX() <= m_position.getX() + 147
			&& vec->getY() >= m_position.getY() && vec->getY() <= m_position.getY() + 154)
		{	//마우스 클릭하면 그림 지워지게
			if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
			{
				Game::m_gameover += 1;
				m_draw = true;
				m_Monster2 = false;
			}
		}
	}
	else if (m_Monster2 == false) return; //한번 클릭되고 나서는 삭제
}
void Monster2::draw()
{
	if (m_draw == false)
	{
		SDLGameObject::draw();
	}
	else return;
}
void Monster2::update()
{
	handleInput();
	move();
	m_currentFrame = ((SDL_GetTicks() / 100) % 5);

	if (moove == true)
	{
		m_velocity.setY(-10);
		m_velocity.setX(-10);
	}
	else if (moove == false)
	{
		m_velocity.setY(10);
		m_velocity.setX(10);
	}

	SDLGameObject::update();
}
void Monster2::move()
{
	if (m_position.getY() + 154 >= 800|| m_position.getX() + 147 >= 1000)
	{
		moove = true;
	}
	else if (m_position.getY() == 0|| m_position.getX() == 0)
	{
		moove = false;
	}
}

void Monster2::clean() {}