#pragma once
#include "main.h"
#include "SDLGameObject.h"
class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
};