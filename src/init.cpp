#include <SDL2/SDL.h>
#include <stdlib.h>

#include<init.h>

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