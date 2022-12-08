#pragma once
#include "SDLGameObject.h"

class Monster : public SDLGameObject
{
public:
    Monster(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
    void move();
private:
    bool m_draw = false;
    bool moove = false;
    bool m_Monster = true;
};