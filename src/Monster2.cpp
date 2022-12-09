#include "Monster2.h"
#include "InputHandler.h"
#include "Game.h"
#include "Player.h"
Monster2::Monster2(const LoaderParams* pParams) : monster_parent(pParams) {}
void Monster2::handleInput()
{
	monster_parent::handleInput();
}
void Monster2::draw()
{
	monster_parent::draw();
}
void Monster2::update()
{
	monster_parent::update();
}
void Monster2::move()
{
	if (m_position.getY() + 154 >= 800 || m_position.getX() + 147 >= 1000)
	{
		moove = true;
	}
	else if (m_position.getY() == 0 || m_position.getX() == 0)
	{
		moove = false;
	}
	
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
}
void Monster2::coliide()
{
	monster_parent::coliide();
}
void Monster2::clean() {}