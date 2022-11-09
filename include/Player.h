#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
    //������ ���� ������
    bool currentJump = false;
    int m_JumpSpeed = -50;
    int x = 1; //�̹��� ���ִ� ���¸� ���� ����

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);


    int hitTime = 0;

protected:
    int move_x = 400, move_y = 9893;

public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean() {};

};