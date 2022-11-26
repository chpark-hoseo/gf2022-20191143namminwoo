#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:

public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();

    bool attack = false;
    int moveX = 100;
    int moveY = 200;
};