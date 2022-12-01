#pragma once
#include "SDLGameObject.h"
class Floor : public SDLGameObject
{
public:
    Floor(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();
};