#pragma once
#include "main.h"
#include "TextureManager.h"

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 680 //���̴� ȭ�� ����
#define LEVEL_WIDTH 1160 //��ü ȭ�� ����
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

//������� �߰� -> 
	SDL_Texture* m_pTexture;

	SDL_Event event;

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	int m_currentFrame = 0, o_currentFrame;
	int x=1; //�̹��� ���ִ� ���¸� ���� ����
	int move_x = 400, move_y = 9893;
	
	//������ ���� ������
	bool currentJump = false;
	int m_JumpSpeed = -50;

	//������ ���� ������
	bool currentHit = false;
	bool practice = false;
	int hitTime = 0;

	//ī�޶� �̵��� ���� ������
	int cameraX = 0, cameraY = 0;

};