#pragma once
#include "main.h"
#include "TextureManager.h"
#include "Player.h"
#include "Monster.h"

#define SCREEN_WIDTH 1000 //���̴� ȭ�� ����
#define SCREEN_HEIGHT 500
#define LEVEL_WIDTH 1920 //��ü ȭ�� ����
#define LEVEL_HEIGHT 1080

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

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	Game() {} //������
	static Game* s_pInstance; // ���� ������� 

	bool m_bRunning;

	SDL_Event event;

	std::vector<GameObject*> m_gameObjects;
	std::vector<Monster*> m_monsters;

	GameObject* m_go = new GameObject();
	GameObject* m_player = new Player();
	Monster* m_monster1 = new Monster();
	Monster* m_monster2 = new Monster();

	//for-each ���� ���� vector�� �迭 ����
	std::vector<int>go = {0,1};
}; typedef Game TheGame;