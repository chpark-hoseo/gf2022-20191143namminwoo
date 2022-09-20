#include <SDL2/SDL.h>
#include <stdlib.h>

#include<update.h>

void update() //update 함수 추가 -> 윈도우 색 1초마다 랜덤하게 변경
{
	SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
	SDL_Delay(1000);
	timer++; //update를 불러올 때마다 변수 값 증가
}