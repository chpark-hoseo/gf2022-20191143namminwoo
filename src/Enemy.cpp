#include "Enemy.h"
#include "InputHandler.h"
#include "Game.h"
#include "Player.h"
Enemy::Enemy(const LoaderParams* pParams) : monster_parent(pParams) {}
void Enemy::handleInput()
{
	monster_parent::handleInput();
}
void Enemy::draw()
{
	monster_parent::draw();
}
void Enemy::update()
{
	monster_parent::update();
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

	if (moove == true)
	{
		m_velocity.setX(-10);
	}
	else if (moove == false)
	{
		m_velocity.setX(10);
	}
}
void Enemy::coliide()
{
	monster_parent::coliide();
}
void Enemy::clean() {}