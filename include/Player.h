#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
    //점프를 위한 변수들
    bool currentJump = false;
    int m_JumpSpeed = -50;
    int x = 1; //이미지 서있는 상태를 위한 변수

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