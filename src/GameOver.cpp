#include "GameOver.h"
#include "InputHandler.h"
GameOver::GameOver(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void GameOver::draw()
{
	SDLGameObject::draw();
}
void GameOver::update()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	m_currentFrame = ((SDL_GetTicks() / 100) % 2);

	if (vec->getX() >= 350 && vec->getX() <= 540 && vec->getY() >= 400 && vec->getY() <= 430)
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			SDL_Quit();
		}
	}

}
void GameOver::clean()
{

}
