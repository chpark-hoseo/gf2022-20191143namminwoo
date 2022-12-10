#include "MainUI.h"
#include "InputHandler.h"
#include "Game.h"
MainUI::MainUI(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void MainUI::handleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if (vec->getX() >= 200 && vec->getX() <= 600 && vec->getY() >= 300 && vec->getY() <= 400)
	{ //play 버튼
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			play = true;
		}
	}
	if (vec->getX() >= 200 && vec->getX() <= 600 && vec->getY() >= 500 && vec->getY() <= 600)
	{	//exit 버튼
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			exit = true;
		}
	}
}
void MainUI::draw()
{
	SDLGameObject::draw();
}
void MainUI::update() 
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 3);
	handleInput();
	if (exit==true)
	{
		SDL_Quit();
	}
	if (play == true)
	{
		Game::gamePlay = 0.5;
	}
}
void MainUI::clean() 
{

}