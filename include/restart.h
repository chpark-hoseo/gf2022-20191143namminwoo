#pragma once
#pragma once
#include "SDLGameObject.h"
class Restart : public SDLGameObject
{
public:
    Restart(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};