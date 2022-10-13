#pragma once
#include "main.h"
#include "TextureManager.h"

#define SCREEN_WIDTH 1000 //보이는 화면 넓이
#define SCREEN_HEIGHT 500
#define LEVEL_WIDTH 1920 //전체 화면 넓이
#define LEVEL_HEIGHT 1080

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
	void keyPad();
	void Jump();
	void stop();
	void camera();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
	//int x = 1, y = 1;
	char key;
	//int x = 0; //이미지 좌우 반복 경우를 위한 변수 선언

//멤버변수 추가 -> 
	SDL_Texture* m_pTexture;
	// 원본 사각형
	SDL_Rect m_sourceRectangle;
	// 대상 사각형
	SDL_Rect m_destinationRectangle;

	SDL_Event event;

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	TextureManager m_textureManager, o_textureManager;
	int m_currentFrame, o_currentFrame;
	int x=1; //이미지 서있는 상태를 위한 변수
	int move_x = 400, move_y = 900;
	
	//점프를 위한 변수들
	bool currentJump = false;
	int m_JumpSpeed = -50;

	//카메라 이동을 위한 변수들
	int cameraX = 0, cameraY = 0;

	//typedef struct SDL_Rect
	//{
	//	int x, y; //사각형의 좌측 상단 위치
	//	int w, h; //사각형의 너비(w)와 높이(h)
	//} SDL_Rect;
};