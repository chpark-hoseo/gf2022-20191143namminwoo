#pragma once
#include "main.h"
#include "TextureManager.h"
#include "Player.h"
//#define SCREEN_HEIGHT 500
//#define SCREEN_WIDTH 680 //보이는 화면 넓이
//#define LEVEL_WIDTH 1160 //전체 화면 넓이
//#define LEVEL_HEIGHT 10000

class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	//void keyPad();
	//void Jump();
	//void collider();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

//멤버변수 추가 -> 
	SDL_Texture* m_pTexture;

	SDL_Event event;
	Player player;
	int m_currentFrame = 0;

};
