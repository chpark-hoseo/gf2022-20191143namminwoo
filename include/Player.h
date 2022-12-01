#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    bool currentJump = false;
    int m_JumpSpeed = -10;
    int x = -1; //왼쪽인지 오른쪽인지 구분, 
                //1 = 오른쪽, -1 = 왼쪽

public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();
    void jump();

    static float player_X;
    static float player_Y;
};