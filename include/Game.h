#pragma once
#include "main.h"

class Game
{
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Window* b_pWindow;
	SDL_Renderer* b_pRenderer;

	bool m_bRunning;

//멤버변수 추가 -> 
	SDL_Texture* m_pTexture;
	// 원본 사각형
	SDL_Rect m_sourceRectangle;
	// 대상 사각형
	SDL_Rect m_destinationRectangle;

	SDL_Texture* b_pTexture;
	SDL_Rect b_SRect;
	SDL_Rect b_DRect;

	typedef struct SDL_Rect
	{
		int x, y; //사각형의 좌측 상단 위치
		int w, h; //사각형의 너비(w)와 높이(h)
	} SDL_Rect;
};