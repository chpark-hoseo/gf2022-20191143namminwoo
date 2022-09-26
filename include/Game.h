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

//������� �߰� -> 
	SDL_Texture* m_pTexture;
	// ���� �簢��
	SDL_Rect m_sourceRectangle;
	// ��� �簢��
	SDL_Rect m_destinationRectangle;

	SDL_Texture* b_pTexture;
	SDL_Rect b_SRect;
	SDL_Rect b_DRect;

	typedef struct SDL_Rect
	{
		int x, y; //�簢���� ���� ��� ��ġ
		int w, h; //�簢���� �ʺ�(w)�� ����(h)
	} SDL_Rect;
};