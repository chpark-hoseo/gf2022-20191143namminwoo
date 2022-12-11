#pragma once
#include "monster_parent.h"
class Enemy : public monster_parent
{
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
    void move();
    void coliide();
private:
    bool moove = true;
    bool m_draw = false;
    bool m_Enemy = true;
    int x = 1;
    int y = 1;
};