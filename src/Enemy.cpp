#include "Enemy.h"
#include "InputHandler.h"
#include "Game.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::handleInput()
{	
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	if (m_Enemy == true)
	{
		//마우스 클릭하면 그림 지워지게
		if (vec->getX() >= m_position.getX() && vec->getX() <= m_position.getX() + 147
			&& vec->getY() >= m_position.getY() && vec->getY() <= m_position.getY() + 154)
		{
			if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
			{
				Game::m_gameover += 1;
				m_Enemy = false;
				m_draw = true;
			}
		}
	}
	else if (m_Enemy == false) return;

	//m_velocity = (*vec - m_position) / 100;
}
void Enemy::draw()
{
	if (m_draw == true)
	{

	}
	else
	{
		SDLGameObject::draw();
	}
}
void Enemy::update()
{
	handleInput();
	move();
	m_currentFrame = ((SDL_GetTicks() / 100) % 5);

	if (moove==true)
	{
		m_velocity.setX(-10);
	}
	else if(moove==false)
	{
		m_velocity.setX(10);
	}

	SDLGameObject::update();
}
void Enemy::move()
{
	if (m_position.getX() + 147 >= 1000)
	{
		moove = true;
	}
	else if (m_position.getX() == 0)
	{
		moove = false;
	}
}
void Enemy::clean() {}
