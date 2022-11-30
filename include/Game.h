#pragma once
#include "main.h"
#include "TextureManager.h"
#include "Player.h"
#include "Monster.h"
#include "Enemy.h"
#include "Background.h"


class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

	static Game* Instance() { //���ϰ�ü ����
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	void quit() { m_bRunning = false; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	//Game() {} //������
	static Game* s_pInstance; // ���� ������� 

	bool m_bRunning;

	SDL_Event event;

	std::vector<GameObject*> m_gameObjects;

	//for-each ���� ���� vector�� �迭 ����
	std::vector<int>go = {0,1};

}; typedef Game TheGame;