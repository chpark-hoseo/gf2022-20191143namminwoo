#include "Explain.h"
#include "InputHandler.h"
#include "Game.h"
Explain::Explain(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Explain::draw()
{
	SDLGameObject::draw();
}
void Explain::update()
{
	handleinput();
	SDLGameObject::update();
}
void Explain::clean() {}
void Explain::handleinput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_KP_ENTER))
	{
        Game::gamePlay = 1;
	}
}