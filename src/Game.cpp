#include "Game.h"

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
                    m_pRenderer, 255, 255, 255, 255);
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
    {
        SDL_Surface* pTempSurface = SDL_LoadBMP("assets/Mush.bmp");
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        m_destinationRectangle.w = m_sourceRectangle.w = 147;
        m_destinationRectangle.h = m_sourceRectangle.h = 154;
        m_sourceRectangle.x = 589;
        m_sourceRectangle.y = 0;
        m_destinationRectangle.x = 400;
        m_destinationRectangle.y = 346;
    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    //if (m_destinationRectangle.x == 0)
    //{
    //    x = 1;
    //}
    //else if(m_destinationRectangle.x == 853)
    //{
    //    x = x * -1;
    //}
    //m_destinationRectangle.x += x;
    //SDL_Delay(5);
    //m_sourceRectangle.x = 147 * ((SDL_GetTicks() / 150) % 5);
    keyPad();
}

void Game::keyPad()
{

    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        x = -1;
        m_destinationRectangle.x += x;
        m_sourceRectangle.x = 147 * ((SDL_GetTicks() / 150) % 5);
        SDL_Delay(3);
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        x = 1;
        m_destinationRectangle.x += x;
        m_sourceRectangle.x = 147 * ((SDL_GetTicks() / 150) % 5);
        SDL_Delay(3);
    }
    else
    {
        m_sourceRectangle.x = 589;
    }
}

void Game::render()
{
    //RenderClear = ȭ������
    SDL_RenderClear(m_pRenderer);
    //RenderCopy = �׸��� ����
    if (x == -1)
    {
        SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    }
    else
    {
        SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle,
            NULL, NULL, SDL_FLIP_HORIZONTAL);
    }   
    //SDL_FLIP -> NONE = ��������, _VERTICAL = ���� ������, HORIZONTAL = �¿� ������
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
    SDL_DestroyTexture(m_pTexture); //Texture ���� �߰�
    SDL_Quit();
}