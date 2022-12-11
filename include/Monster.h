#pragma once
#include "monster_parent.h"

class Monster : public monster_parent
{
public:
    Monster(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
    void move();
    void coliide();
private:
    bool m_draw = true;
    bool moove = false;
    bool m_Monster = true;
    int x = 1;
};