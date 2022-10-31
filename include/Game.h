#pragma once
#include "main.h"
#include "TextureManager.h"
#include "Player.h"
#include "Monster.h"

#define SCREEN_WIDTH 1000 //보이는 화면 넓이
#define SCREEN_HEIGHT 500
#define LEVEL_WIDTH 1920 //전체 화면 넓이
#define LEVEL_HEIGHT 1080

class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();


private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	SDL_Event event;

	int m_currentFrame;

	GameObject m_go;
	Player m_player;
	Monster m_monster1, m_monster2;
};