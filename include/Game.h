#pragma once
#include "main.h"
#include "TextureManager.h"
#include "Player.h"
#include "Monster.h"
#include "Enemy.h"
#include "Background.h"
#include "Floor.h"
#include "MainUI.h"
#include "GameOver.h"
#include "Monster2.h"
#include "BGMing.h"
#include "monster_parent.h"
class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

	static int gamePlay; //0 = ����, 1 = ����, 2 = ���� 

	static Game* Instance() { //���ϰ�ü ����
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	void quit() { m_bRunning = false; }

	static int m_gameover;
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	//Game() {} //������
	static Game* s_pInstance; // ���� ������� 

	bool m_bRunning;

	SDL_Event event;

	std::vector<GameObject*> m_gameStart;
	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_gameObjector;
	std::vector<GameObject*> m_gameEnd;

	//for-each ���� ���� vector�� �迭 ����
	std::vector<int>go = {0,1};

}; typedef Game TheGame;