#include <SDL2/SDL.h>
#include <stdlib.h>

#include<update.h>

void update() //update �Լ� �߰� -> ������ �� 1�ʸ��� �����ϰ� ����
{
	SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
	SDL_Delay(1000);
	timer++; //update�� �ҷ��� ������ ���� �� ����
}