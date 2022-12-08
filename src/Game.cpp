#include "Game.h"
#include "InputHandler.h"
#include "Player.h"

int Game::gamePlay = 0;
int Game::m_gameover = 0;

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
                    m_pRenderer, 0, 0, 0, 255);
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
    if (!TheTextureManager::Instance()->load("Assets/m_move2.png", "player", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/obstac.png", "floor", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/main.jpg", "mainbg", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/button.png", "playbt", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/exit.png", "exitbt", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/gameover.png", "gameoverbt", m_pRenderer))
    {
        return false;
    }


    { //메인화면
        m_gameStart.push_back(new MainUI(new LoaderParams(0, 0, 1000, 800, "mainbg")));
        m_gameStart.push_back(new MainUI(new LoaderParams(300, 300, 400, 100, "playbt")));
        m_gameStart.push_back(new MainUI(new LoaderParams(300, 500, 400, 100, "exitbt")));
    }
    { //게임씬
        m_gameObjects.push_back(new Background(new LoaderParams(0, 0, 1000, 1000, "background")));        
        m_gameObjects.push_back(new Floor(new LoaderParams(1000, 725, 200, 75, "floor")));
        m_gameObjects.push_back(new Floor(new LoaderParams(800, 725, 200, 75, "floor")));
        m_gameObjects.push_back(new Floor(new LoaderParams(600, 725, 200, 75, "floor")));
        m_gameObjects.push_back(new Floor(new LoaderParams(400, 725, 200, 75, "floor")));
        m_gameObjects.push_back(new Floor(new LoaderParams(200, 725, 200, 75, "floor")));
        m_gameObjects.push_back(new Floor(new LoaderParams(0, 725, 200, 75, "floor")));
        //m_gameObjects.push_back(new BGMing(new LoaderParams(0, 0, 0, 0, "BGM")));
        m_gameObjects.push_back(new Player(new LoaderParams(450, 665, 100, 91, "player")));

        m_gameObjector.push_back(new Enemy(new LoaderParams(10, 100, 147, 154, "mush")));
        m_gameObjector.push_back(new Monster(new LoaderParams(400, 600, 147, 154, "mush")));
        m_gameObjector.push_back(new Monster2(new LoaderParams(0, 0, 147, 154, "mush")));
    }
    { //종료
        m_gameEnd.push_back(new GameOver(new LoaderParams(400, 400, 190, 30, "gameoverbt")));
    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    std::cout << m_gameover << std::endl;
    if (gamePlay == 0)
    {
        for (int i = 0; i != m_gameStart.size(); i++)
        {
            m_gameStart[i]->update();
        }
    }
    else if (gamePlay == 1)
    {
        for (int i = 0; i != m_gameObjects.size(); i++)
        {
            m_gameObjects[i]->update();
        }
        for (int i = 0; i != m_gameObjector.size(); i++)
        {
            m_gameObjector[i]->update();
        }
    }
    else if (gamePlay == 2)
    {
        for (int i = 0; i != m_gameEnd.size(); i++)
        {
            m_gameEnd[i]->update();
        }
    }

    if (m_gameover == m_gameObjector.size())
    {
        gamePlay = 2;
    }

    SDL_Delay(10);
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    if (gamePlay == 0)
    {
        for (int i = 0; i != m_gameStart.size(); i++)
        {
            m_gameStart[i]->draw();
        }
    }
    else if (gamePlay == 1)
    {
        for (int i = 0; i != m_gameObjects.size(); i++)
        {
            m_gameObjects[i]->draw();
        }
        for (int i = 0; i != m_gameObjector.size(); i++)
        {
            m_gameObjector[i]->draw();
        }
    }
    else if (gamePlay == 2)
    {
        for (int i = 0; i != m_gameEnd.size(); i++)
        {
            m_gameEnd[i]->draw();
        }
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