#pragma once
#include "monster_parent.h"
class Monster2 : public monster_parent
{
public:
    Monster2(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
    void move();
    void coliide();
private:
    bool moove = true;
    bool m_draw = false;
    bool m_Monster2 = true;
    int x = -1;
};