#pragma once
#pragma once
#include "SDLGameObject.h"
class Monster2 : public SDLGameObject
{
public:
    Monster2(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
    void move();
private:
    bool moove = false;
    bool m_draw = false;
    bool m_Monster2 = true;
};