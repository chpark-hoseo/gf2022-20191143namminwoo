#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
    {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m_pRenderer, 255, 255, 0, 255);
            }
            else {
                return false; // 랜더러 생성 실패
            }
        }
        else {
            return false; // 윈도우 생설 실패 l
        }
    }
    else {
        return false; // SDL 초기화 실패
    }

    if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }

    m_go->load(100, 100, 128, 82, "animate");
    m_player->load(200, 200, 128, 82, "animate");

    m_gameObjects.push_back(m_go);
    m_gameObjects.push_back(m_player);

    m_monster1->load(300, 300, 128, 82, "animate");
    m_monster2->load(300, 400, 128, 82, "animate");

    m_bRunning = true;
    return true;
}

void Game::update()
{
    //for (int i = 0; i < m_gameObjects.size(); i++)
    //{
    //    m_gameObjects[i]->update();
    //}

    //for-each 문 적용
    for(int num : go)
    {
        m_gameObjects[num]->update();
    }

    m_monster1->update1();
    m_monster2->update2();

    SDL_Delay(10);
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    //for (int i = 0; i < m_gameObjects.size(); i++)
    //{
    //    m_gameObjects[i]->draw(m_pRenderer);
    //}
    for (int num : go)
    {
        m_gameObjects[num]->draw(m_pRenderer);
    }

    //for (int i = 0; i < m_monsters.size(); i++)
    //{
    //    m_monsters[i]->draw(m_pRenderer);
    //}
    m_monster1->draw(m_pRenderer);
    m_monster2->draw(m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{   
    return m_bRunning;
}

void Game::handleEvents()
{
    while (SDL_PollEvent(&event)) //조건적 시행이 아닌 콘솔창 시행 내내 
                                  //동작 가능하게 만들기 위해서 라고 추측함
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
   // SDL_DestroyTexture();
    SDL_Quit();
}