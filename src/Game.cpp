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
        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_destinationRectangle.y = m_sourceRectangle.y = 0;
    }
    {
        SDL_Surface* oTempSurface = SDL_LoadBMP("assets/Mush.bmp");
        o_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, oTempSurface);
        SDL_FreeSurface(oTempSurface);
        o_destinationRectangle.w = o_sourceRectangle.w = 147;
        o_destinationRectangle.h = o_sourceRectangle.h = 154;
        o_sourceRectangle.x = 0;
        o_sourceRectangle.y = 0;
        o_destinationRectangle.x = 0;
        o_destinationRectangle.y = 200;
    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    ////����ȭ �� �����ҰŶ� ���� ��
    //if (x == 0) //�̹����� ���������� ���� ���
    //{
    //    m_destinationRectangle.x += 1;
    //    SDL_Delay(5);
    //    if (m_destinationRectangle.x == 567) //�̹����� ������ ���Ĺ濡 ����� �� ���� ��ȯ
    //    {
    //        x = 1;
    //    }
    //}
    //else if (x == 1) //�̹����� �������� ���� ���
    //{
    //    m_destinationRectangle.x -= 1;
    //    SDL_Delay(5);
    //    if (m_destinationRectangle.x == 0) //�̹����� ���� ���Ĺ濡 ����� �� ���� ��ȯ
    //    {
    //        x = 0;
    //    }
    //}
    //if (m_destinationRectangle.x == 567)
    //{
    //    x = x *+1;
    //}
    //else if (m_destinationRectangle.x == 0)
    //{
    //    x = x * -1;
    //}
    //m_destinationRectangle.x += x;
    //SDL_Delay(5);

    m_sourceRectangle.x = 147 * ((SDL_GetTicks()/150) % 5);

    o_sourceRectangle.x = 147 * ((SDL_GetTicks() / 50) % 5);
}

void Game::render()
{
    //RenderClear = ȭ������
    SDL_RenderClear(m_pRenderer);
    //RenderCopy = �׸��� ����
   // SDL_RenderCopy(m_pRenderer, m_pCart_back, &m_Cart_Back_SRect, &m_Cart_Back_DRect);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderCopy(m_pRenderer, o_pTexture, &o_sourceRectangle, &o_destinationRectangle);
    
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
    SDL_Event event;
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
    SDL_DestroyTexture(o_pTexture);
  //  SDL_DestroyTexture(m_pCart_back); //Texture ����
    //SDL_DestroyRect();  << ?
    SDL_Quit();
}