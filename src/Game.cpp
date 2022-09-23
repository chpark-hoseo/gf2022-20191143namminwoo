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
                    m_pRenderer, 154, 225, 50, 0);
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
    //텍스처 생성
    {
        SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        //원본상자의 높이,너비 설정
        SDL_QueryTexture(m_pTexture, NULL, NULL,   //QueryTexture 함수 사용해서 크기 구하기
            &m_sourceRectangle.w, &m_sourceRectangle.h); 
        //대상상자의 높이, 너비 설정 -> 원본상자와 동일하게
        m_destinationRectangle.w = m_sourceRectangle.w;
        m_destinationRectangle.h = m_sourceRectangle.h;
        //원본 + 대상상자의 위치 설정 (좌측최상단 고정)
        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_destinationRectangle.y = m_sourceRectangle.y = 0;
    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    //m_destinationRectangle.x+=1;
    //SDL_Delay(10);

}

void Game::render()
{
    //RenderClear = 화면지움
    SDL_RenderClear(m_pRenderer); //왜 되지?
    //RenderCopy = 그리기 수행
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    //RenderPresent = 그린거 호출
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
    while (SDL_PollEvent(&event)) //조건적 시행이 아닌 콘솔창 시행 내내 동작 가능하게 만들기 위해서라고 추측함
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
    SDL_Quit();
}