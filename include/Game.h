#pragma once
#include "main.h"
#include "TextureManager.h"

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 680 //보이는 화면 넓이
#define LEVEL_WIDTH 1160 //전체 화면 넓이
#define LEVEL_HEIGHT 10000

class Game
{
public:

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	void keyPad();
	void Jump();
	void camera();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

//멤버변수 추가 -> 
	SDL_Texture* m_pTexture;

	SDL_Event event;

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	int m_currentFrame = 0, o_currentFrame;
	int x=1; //이미지 서있는 상태를 위한 변수
	int move_x = 400, move_y = 9893;
	
	//점프를 위한 변수들
	bool currentJump = false;
	int m_JumpSpeed = -50;

	//공격을 위한 변수들
	bool currentHit = false;
	bool practice = false;
	int hitTime = 0;

	//카메라 이동을 위한 변수들
	int cameraX = 0, cameraY = 0;

};