#pragma once
#include "SDLGameObject.h"
class monster_parent : public SDLGameObject
{
public:
    monster_parent(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
    virtual void move();
    virtual void coliide();
private:
    bool moove = false;
    bool m_draw = true;
    bool m_Monster = true;
};