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
	m_velocity.setX(10 * x);
	m_velocity.setY(5 * y);
	if (m_position.getX() + 147 >= 1000)
	{
		x = -1;
	}
	else if (m_position.getX() == 0)
	{
		x = 1;
	}
	if (m_position.getY() <= 0)
	{
		y = 1;
	}
	else if (m_position.getY() + 154 >= 800)
	{
		y = -1;
	}
}
void Enemy::coliide()
{
	if (m_Enemy == true)
	{
		monster_parent::coliide();
	}	
}
void Enemy::clean() {}