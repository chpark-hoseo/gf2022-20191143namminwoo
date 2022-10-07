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
	void keyPad();
	void Jump();


private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
	int x = 1, y = 1;
	char key;
	//int x = 0; //�̹��� �¿� �ݺ� ��츦 ���� ���� ����

//������� �߰� -> 
	SDL_Texture* m_pTexture;
	// ���� �簢��
	SDL_Rect m_sourceRectangle;
	// ��� �簢��
	SDL_Rect m_destinationRectangle;

	SDL_Event event;

	SDL_Texture* o_pTexture;
	SDL_Rect o_sourceRectangle;
	SDL_Rect o_destinationRectangle;

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	//������ ���� ����
	float JumpTime = 0.f;
	float JumpHeight = 0;
	float JumpPower = 50.f;
	bool m_JumpPress = false;

	//typedef struct SDL_Rect
	//{
	//	int x, y; //�簢���� ���� ��� ��ġ
	//	int w, h; //�簢���� �ʺ�(w)�� ����(h)
	//} SDL_Rect;
};