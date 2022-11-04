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


private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	SDL_Event event;

	std::vector<GameObject*> m_gameObjects;
	//std::vector<Monster*> m_monsters;

	GameObject* m_go = new GameObject();
	GameObject* m_player = new Player();
	Monster* m_monster1 = new Monster();
	Monster* m_monster2 = new Monster();

};