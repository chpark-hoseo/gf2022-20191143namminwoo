#include <SDL2/SDL.h>
#include <stdlib.h>

#include <render.h>

void render() 		// �׸��� ����  
{
	{
		SDL_RenderClear(g_pRenderer);

		SDL_RenderPresent(g_pRenderer);
	}
}