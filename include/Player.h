#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    bool currentJump = false;
    int m_JumpSpeed = -50;
    int x = -1; //왼쪽인지 오른쪽인지 구분, 1 = 오른쪽, -1 = 왼쪽
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();
    void jump();
    bool attack = false;
};