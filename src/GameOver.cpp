#include "GameOver.h"
GameOver::GameOver(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void GameOver::draw()
{
	SDLGameObject::draw();
}
void GameOver::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 2);
}
void GameOver::clean()
{

}
