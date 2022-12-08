#pragma once
#include "SDLGameObject.h"
class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
    void move();
private:
    bool moove = false;
    bool m_draw = false;
    bool m_Enemy = true;
};