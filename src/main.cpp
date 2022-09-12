#include <SDL2/SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		//윈도우 이름 및 크기
		g_pWindow = SDL_CreateWindow("Game Framework",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1024, 768,
			//윈도우 생성 다르게 해보기
			SDL_WINDOW_BORDERLESS|SDL_WINDOW_MAXIMIZED);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else
	{
		return 1;
	}

	//윈도우 바탕화면 색 바꾸기
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0,255, 255);
	SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);

	//프로그램 10초 후 종료
	SDL_Delay(10000);
	SDL_Quit();

	return 0;
}