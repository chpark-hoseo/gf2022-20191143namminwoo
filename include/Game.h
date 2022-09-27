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

	bool m_bRunning;

//������� �߰� -> 
	SDL_Texture* m_pTexture;
	// ���� �簢��
	SDL_Rect m_sourceRectangle;
	// ��� �簢��
	SDL_Rect m_destinationRectangle;

	SDL_Texture* m_pCart_back;
	SDL_Rect m_Cart_Back_SRect;
	SDL_Rect m_Cart_Back_DRect;




	//typedef struct SDL_Rect
	//{
	//	int x, y; //�簢���� ���� ��� ��ġ
	//	int w, h; //�簢���� �ʺ�(w)�� ����(h)
	//} SDL_Rect;
};