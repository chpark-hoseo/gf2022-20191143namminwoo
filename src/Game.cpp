#include "Game.h"
int x = 0; //이미지 좌우 반복 경우를 위한 변수 선언

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
    //최적화 더 가능할거라 예상 중
    if (x == 0) //이미지가 오른쪽으로 가는 경우
    {
        m_destinationRectangle.x += 1;
        SDL_Delay(5);
        if (m_destinationRectangle.x == 567) //이미지가 오른쪽 최후방에 닿았을 때 변수 전환
        {
            x = 1;
        }
    }
    else if (x == 1) //이미지가 왼쪽으로 가는 경우
    {
        m_destinationRectangle.x -= 1;
        SDL_Delay(5);
        if (m_destinationRectangle.x == 0) //이미지가 왼쪽 최후방에 닿았을 때 변수 전환
        {
            x = 0;
        }
    }


}

void Game::render()
{
    //RenderClear = 화면지움
    SDL_RenderClear(m_pRenderer);
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