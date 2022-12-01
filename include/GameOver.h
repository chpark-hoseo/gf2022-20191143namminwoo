#pragma once
#include "SDLGameObject.h"
class GameOver : public SDLGameObject
{
public:
    GameOver(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};