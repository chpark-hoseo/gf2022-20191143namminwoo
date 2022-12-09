#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    bool currentJump = false;
    int m_JumpSpeed = -40;
    int x = -1; //왼쪽인지 오른쪽인지 구분, 
                //1 = 오른쪽, -1 = 왼쪽
    int p_x = 300;
    int p_y = 600;

    int hitTime = 0; //공격 시 프레임

public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();

    static bool attack;
    static int player_X;
    static int player_Y;
};