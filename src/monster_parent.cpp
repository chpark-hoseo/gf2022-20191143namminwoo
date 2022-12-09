#include "monster_parent.h"
#include "InputHandler.h"
#include "Game.h"
#include "Player.h"
monster_parent::monster_parent(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void monster_parent::handleInput()
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
				m_draw = false;
				m_Monster = false;
			}
		}
	}
	else if (m_Monster == false) return; //한번 클릭되고 나서는 삭제
}
void monster_parent::draw()
{
	if (m_draw == true)
	{
		SDLGameObject::draw();
	}
	else return;
}
void monster_parent::update()
{
	handleInput();
	move();
	coliide();
	m_currentFrame = ((SDL_GetTicks() / 100) % 5);

	SDLGameObject::update();
}
void monster_parent::move() {}
void monster_parent::coliide()
{
	if (Player::player_X + 100 >= m_position.getX() &&
		Player::player_Y + 91 >= m_position.getY() &&
		Player::player_X <= m_position.getX() + 147 &&
		Player::player_Y <= m_position.getY() + 154)
	{
		Player::player_hit = true;
	}
	else
	{
		Player::player_hit = false;
	}

}
void monster_parent::clean() {}