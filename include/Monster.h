#pragma once
#include "SDLGameObject.h"

class Monster : public SDLGameObject
{
protected:
    int mob1_move = 10;
    int mob2_move = 5;

public:
    Monster(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};