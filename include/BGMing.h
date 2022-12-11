#pragma once
#include "SDLGameObject.h"

class BGMing : public SDLGameObject
{
public:
    BGMing(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    Mix_Chunk* g_pChunk;
    Mix_Music* m_pChunk;
};