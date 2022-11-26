#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
    bool currentJump = false;
    int m_JumpSpeed = -50;
    int x = -1; //�������� ���������� ����, 1 = ������, -1 = ����
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();
    void jump();
    bool attack = false;
};