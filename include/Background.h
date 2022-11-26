#pragma once
#include "SDLGameObject.h"
class Background : public SDLGameObject
{
public:
    Background(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};