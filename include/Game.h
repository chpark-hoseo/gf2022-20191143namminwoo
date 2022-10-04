#pragma once
#include "main.h"
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500
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

	//int SDL_RenderCopyEx(SDL_Renderer* renderer,
	//	SDL_Texture* texture,
	//	const SDL_Rect* srcrect,
	//	const SDL_Rect* dstrect,
	//	const double angle,
	//	const SDL_Point* center,
	//	const SDL_RendererFlip flip);

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
	int x=1;
	char key;
	//int x = 0; //이미지 좌우 반복 경우를 위한 변수 선언

//멤버변수 추가 -> 
	SDL_Texture* m_pTexture;
	// 원본 사각형
	SDL_Rect m_sourceRectangle;
	// 대상 사각형
	SDL_Rect m_destinationRectangle;



	//typedef struct SDL_Rect
	//{
	//	int x, y; //사각형의 좌측 상단 위치
	//	int w, h; //사각형의 너비(w)와 높이(h)
	//} SDL_Rect;
};