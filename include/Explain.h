#pragma once
#pragma once
#include "SDLGameObject.h"

class Explain : public SDLGameObject
{
public:
    Explain(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleinput();
};