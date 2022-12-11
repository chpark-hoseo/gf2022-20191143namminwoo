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
	m_velocity.setY(10*x);

	if (m_position.getY() + 154 >= 800)
	{
		x = -1;
	}
	else if (m_position.getY() == 0)
	{
		x = 1;
	}
}
void Monster::coliide()
{
	monster_parent::coliide();
}
void Monster::clean() {}