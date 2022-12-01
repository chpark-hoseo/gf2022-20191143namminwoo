#include "Game.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

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

    if (!TheTextureManager::Instance()->load("Assets/Mush.bmp", "mush", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/back.png", "background", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/m_Move2.png", "player_move", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/obstac.png", "floor", m_pRenderer))
    {
        return false;
    }

    m_gameObjects.push_back(new Background(new LoaderParams(0, 0, 1160, 10000, "background")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(10, 100, 147, 154, "mush")));
    m_gameObjects.push_back(new Player(new LoaderParams(300, 600, 100, 91, "player_move")));
    m_gameObjects.push_back(new Floor(new LoaderParams(1000, 725, 200, 75, "floor")));
    m_gameObjects.push_back(new Floor(new LoaderParams(800, 725, 200, 75, "floor")));
    m_gameObjects.push_back(new Floor(new LoaderParams(600, 725, 200, 75, "floor")));
    m_gameObjects.push_back(new Floor(new LoaderParams(400, 725, 200, 75, "floor")));
    m_gameObjects.push_back(new Floor(new LoaderParams(200, 725, 200, 75, "floor")));
    m_gameObjects.push_back(new Floor(new LoaderParams(0, 725, 200, 75, "floor")));
    m_gameObjects.push_back(new Camera(new LoaderParams(500, 500, 0, 0, "")));

    m_bRunning = true;
    return true;
}

void Game::update()
{
    for (int i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
    SDL_Delay(10);
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    for (int i = 0; i != m_gameObjects.size(); i++) 
    {
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{   
    return m_bRunning;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    TheInputHandler::Instance()->clean();
    SDL_Quit();
}