#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

int timer = 0; //무한루트를 일정시간 후 빠져나오게 하는 변수 추가
//main함수를 맨 위로 올리기 위해 다른 함수들을 먼저 선언
bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
void update();
void render();

int main(int argc, char* argv[])
{
	{
		if (init("Breaking Up HelloSDL", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 640, 480,
			SDL_WINDOW_SHOWN))
		{
			g_bRunning = true;
		}
		else
		{
			return 1; // something's wrong
		}

		while (g_bRunning) //!g_bRunning -> g_bRunning = ture 인데 !이므로 false가 되서 실행 x --> while문 종료 후 SDL_Quit()실행 = 창 종료
		{
			// handle input - update - render
			update();
			render();

			if (timer == 10) //변수값이 설정한 값이 되면 while문의 조건을 거짓으로 변경 -> while문 종료
			{
				g_bRunning = false;
			}
		}

		SDL_Quit();
		return 0;
	}
}

bool init(const char* title, int xpos, int ypos, int height, int width, int flags) //윈도우 초기화 및 초기값 설정?
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else
		{
			return false;
		}

		SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

		return true;
	}
}

void update() //update 함수 추가 -> 윈도우 색 1초마다 랜덤하게 변경
{
	SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
	SDL_Delay(1000);
	timer++; //update를 불러올 때마다 변수 값 증가
}

void render() 		// 그리기 수행  
{
	{
		SDL_RenderClear(g_pRenderer);

		SDL_RenderPresent(g_pRenderer);
	}
}