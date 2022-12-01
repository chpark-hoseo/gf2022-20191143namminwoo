#pragma once
#include "SDLGameObject.h"
class MainUI : public SDLGameObject
{
private:
    bool exit = false;
    bool play = false;
public:
    MainUI(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
};