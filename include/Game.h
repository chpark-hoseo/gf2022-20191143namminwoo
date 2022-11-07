#pragma once
#include "main.h"
#include "TextureManager.h"
#include "Player.h"
#include "Monster.h"

#define SCREEN_WIDTH 1000 //보이는 화면 넓이
#define SCREEN_HEIGHT 500
#define LEVEL_WIDTH 1920 //전체 화면 넓이
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
	
	GameObject* m_go = new GameObject();
	GameObject* m_player = new Player();
	GameObject* m_monster1 = new Monster(10,500);
	GameObject* m_monster2 = new Monster(5,400);

	//Monster* m_monster1 = new Monster();
	//Monster* m_monster2 = new Monster();
	//std::vector<Monster*> m_monsters;
	
	//for-each 문을 위한 vector형 배열 선언
	std::vector<int>go = {0,1,2,3};
};