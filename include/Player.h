#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    bool currentJump = false;
    int m_JumpSpeed = -10;
    int x = -1; //�������� ���������� ����, 
                //1 = ������, -1 = ����

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