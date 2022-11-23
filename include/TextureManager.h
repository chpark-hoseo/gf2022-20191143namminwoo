#pragma once
#include <SDL2/SDL.h> 
// #include "main.h"
#include <map>
#include <string>
class TextureManager {

private:
    std::map<std::string, SDL_Texture*> m_textureMap;
    TextureManager() {}
    ~TextureManager() {}
    static TextureManager* s_pInstance;

public:
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

    void draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    static TextureManager* Instance()
    {
        if (s_pInstance == 0)
            s_pInstance = new TextureManager();
        return s_pInstance;
    }

    //클래스가 유일객체라는 것을 쉽게 파악할 수 있도록 별칭 생성
};     typedef TextureManager TheTextureManager;