#include "BGMing.h"
#include "InputHandler.h"
#include "Game.h"

BGMing::BGMing(const LoaderParams* pParams) : SDLGameObject(pParams) { 
	g_pChunk = Mix_LoadWAV("./assets/jump.wav");
	m_pChunk = Mix_LoadMUS("./assets/Timeless.wav");
}
void BGMing::draw() {}
void BGMing::update()
{ 
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if (Game::gamePlay == 1)
	{
		Mix_FreeMusic(m_pChunk);
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			// chunk에 담긴 사운드 재생, -1은 가장 가까운 채널, 0은 반복 횟수
			Mix_PlayChannel(-1, g_pChunk, 0);
		}
	}

	SDLGameObject::update();
}
void BGMing::clean() {}