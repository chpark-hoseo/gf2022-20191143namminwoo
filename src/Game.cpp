#include "Game.h"
int x = 0; //�̹��� �¿� �ݺ� ��츦 ���� ���� ����

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
        SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        //���������� ����,�ʺ� ����
        SDL_QueryTexture(m_pTexture, NULL, NULL,   //QueryTexture �Լ� ����ؼ� ũ�� ���ϱ�
            &m_sourceRectangle.w, &m_sourceRectangle.h); 
        //�������� ����, �ʺ� ���� -> �������ڿ� �����ϰ�
        m_destinationRectangle.w = m_sourceRectangle.w;
        m_destinationRectangle.h = m_sourceRectangle.h;
        //���� + �������� ��ġ ���� (�����ֻ�� ����)
        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_destinationRectangle.y = m_sourceRectangle.y = 0;
    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    //����ȭ �� �����ҰŶ� ���� ��
    if (x == 0) //�̹����� ���������� ���� ���
    {
        m_destinationRectangle.x += 1;
        SDL_Delay(5);
        if (m_destinationRectangle.x == 567) //�̹����� ������ ���Ĺ濡 ����� �� ���� ��ȯ
        {
            x = 1;
        }
    }
    else if (x == 1) //�̹����� �������� ���� ���
    {
        m_destinationRectangle.x -= 1;
        SDL_Delay(5);
        if (m_destinationRectangle.x == 0) //�̹����� ���� ���Ĺ濡 ����� �� ���� ��ȯ
        {
            x = 0;
        }
    }


}

void Game::render()
{
    //RenderClear = ȭ������
    SDL_RenderClear(m_pRenderer);
    //RenderCopy = �׸��� ����
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
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
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderClear(renderer);

    //SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    //SDL_RenderFillRect(renderer, &fillRect);

    //SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
    //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    //SDL_RenderDrawRect(renderer, &outlineRect);

    //SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    //SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

    //SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    //for (int i = 0; i < SCREEN_HEIGHT; i += 4)
    //{
    //    SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, i);
    //}

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}