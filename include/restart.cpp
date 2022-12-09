#include "Restart.h"
#include "InputHandler.h"
#include "Game.h"
Restart::Restart(const LoaderParams* pParams) : SDLGameObject(pParams) {}
//200,80
void Restart::draw()
{
	SDLGameObject::draw();
}
void Restart::update()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	m_currentFrame = ((SDL_GetTicks() / 100) % 3);

	if (vec->getX() >= m_position.getX() && vec->getX() <= m_position.getX() + 200
		&& vec->getY() >= m_position.getY() && vec->getY() <= m_position.getY() + 80)
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			Game::gamePlay = 1;
		}
	}
	SDLGameObject::update();
}
void Restart::clean()
{

}
