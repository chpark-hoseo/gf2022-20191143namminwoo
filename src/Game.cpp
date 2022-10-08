#include "Game.h"
#include "TextureManager.h"
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
                return false; // ������ ���� ����
            }
        }
        else {
            return false; // ������ ���� ���� l
        }
    }
    else {
        return false; // SDL �ʱ�ȭ ����
    }
    //�ؽ�ó ����
    //{
    //    SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");        
    //    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    //    SDL_FreeSurface(pTempSurface);
    //    m_destinationRectangle.w = m_sourceRectangle.w = 128;
    //    m_destinationRectangle.h = m_sourceRectangle.h = 82;
    //    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    //    m_sourceRectangle.y = 0;
    //    m_destinationRectangle.y = 400;
    //}

    m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
    //o_textureManager.load("Assets/Player_.png", "Player_", m_pRenderer);

    m_bRunning = true;
    return true;
}

void Game::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    //o_currentFrame = ((SDL_GetTicks() / 100) % 5);
    SDL_Delay(10);

   //keyPad();
}

void Game::keyPad()
{
    //if (currentKeyStates[SDL_SCANCODE_LEFT])
    //{
    //    x = -1;
    //    m_destinationRectangle.x += x;
    //    m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 150) % 6);
    //    SDL_Delay(3);
    //}
    //else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    //{
    //    x = 1;
    //    m_destinationRectangle.x += x;
    //    m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 150) % 6);
    //    SDL_Delay(3);
    //}
    //else
    //{
    //    m_sourceRectangle.x = 256;
    //}
}

void Game::render()
{
    //RenderClear = ȭ������
    SDL_RenderClear(m_pRenderer);
    //RenderCopy = �׸��� ����
    //if (x == -1)
    //{
    //    SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle,
    //        NULL, NULL, SDL_FLIP_HORIZONTAL);
    //}
    //else
    //{
    //    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle); 
    //}

    m_textureManager.draw("animate", 0,0, 128, 82, m_pRenderer);
    m_textureManager.drawFrame("animate", 100, 100, 128, 82,
        0, m_currentFrame, m_pRenderer);
    //if (currentKeyStates[SDL_SCANCODE_LEFT])
    //{
    //    o_textureManager.drawFrame("Player_", 200, 200, 63, 63,
    //        0, m_currentFrame, m_pRenderer);
    //}
    //else if((currentKeyStates[SDL_SCANCODE_RIGHT]))
    //{
    //    o_textureManager.drawFrame("Player_", 200, 200, 63, 63,
    //        1, m_currentFrame, m_pRenderer);
    //}
    //else
    //{
    //    o_textureManager.draw("Player_", 200, 200, 63, 63, m_pRenderer);
    //}


    //RenderPresent = �׸��� ȣ��
    SDL_RenderPresent(m_pRenderer);  
}

bool Game::running()
{   
    return m_bRunning;
}

void Game::handleEvents()
{
    /*if (SDL_PollEvent(&event))*/
    while (SDL_PollEvent(&event)) //������ ������ �ƴ� �ܼ�â ���� ���� ���� �����ϰ� ����� ���ؼ���� ������
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
    //SDL_DestroyTexture(m_pTexture); //Texture ���� �߰�
    SDL_Quit();
}