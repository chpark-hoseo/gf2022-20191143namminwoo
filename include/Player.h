#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    bool currentJump = false;
    int m_JumpSpeed = -40;
    int x = -1; //�������� ���������� ����, 
                //1 = ������, -1 = ����
    int p_x = 300;
    int p_y = 600;

    int hitTime = 0; //���� �� ������

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