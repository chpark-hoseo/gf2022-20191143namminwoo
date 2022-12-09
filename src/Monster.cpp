#include "Monster.h"
#include "InputHandler.h"
#include "Game.h"
#include "Player.h"
Monster::Monster(const LoaderParams* pParams) : monster_parent(pParams) {}
void Monster::handleInput()
{
	monster_parent::handleInput();
}
void Monster::draw()
{
	monster_parent::draw();
}
void Monster::update()
{
	monster_parent::update();
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

	if (moove == true)
	{
		m_velocity.setY(-10);
	}
	else if (moove == false)
	{
		m_velocity.setY(10);
	}
}
void Monster::coliide()
{
	monster_parent::coliide();
}
void Monster::clean() {}