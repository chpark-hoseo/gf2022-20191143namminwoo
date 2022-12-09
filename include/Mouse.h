#pragma once
#include "SDLGameObject.h"
class Mouse : public SDLGameObject
{
public:
    Mouse(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();
};