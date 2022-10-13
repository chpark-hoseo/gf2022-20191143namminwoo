#pragma once
#include "main.h"
#include "TextureManager.h"

#define SCREEN_WIDTH 1000 //���̴� ȭ�� ����
#define SCREEN_HEIGHT 500
#define LEVEL_WIDTH 1920 //��ü ȭ�� ����
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
	//int x = 0; //�̹��� �¿� �ݺ� ��츦 ���� ���� ����

//������� �߰� -> 
	SDL_Texture* m_pTexture;
	// ���� �簢��
	SDL_Rect m_sourceRectangle;
	// ��� �簢��
	SDL_Rect m_destinationRectangle;

	SDL_Event event;

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	TextureManager m_textureManager, o_textureManager;
	int m_currentFrame, o_currentFrame;
	int x=1; //�̹��� ���ִ� ���¸� ���� ����
	int move_x = 400, move_y = 900;
	
	//������ ���� ������
	bool currentJump = false;
	int m_JumpSpeed = -50;

	//ī�޶� �̵��� ���� ������
	int cameraX = 0, cameraY = 0;

	//typedef struct SDL_Rect
	//{
	//	int x, y; //�簢���� ���� ��� ��ġ
	//	int w, h; //�簢���� �ʺ�(w)�� ����(h)
	//} SDL_Rect;
};