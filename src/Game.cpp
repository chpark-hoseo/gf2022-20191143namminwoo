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
        SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        m_destinationRectangle.w = m_sourceRectangle.w = 128;
        m_destinationRectangle.h = m_sourceRectangle.h = 82;
        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_destinationRectangle.y = m_sourceRectangle.y = 0;
    }

    m_bRunning = true;
    return true;
}

void Game::update()
{
    ////최적화 더 가능할거라 예상 중
    //if (x == 0) //이미지가 오른쪽으로 가는 경우
    //{
    //    m_destinationRectangle.x += 1;
    //    SDL_Delay(5);
    //    if (m_destinationRectangle.x == 567) //이미지가 오른쪽 최후방에 닿았을 때 변수 전환
    //    {
    //        x = 1;
    //    }
    //}
    //else if (x == 1) //이미지가 왼쪽으로 가는 경우
    //{
    //    m_destinationRectangle.x -= 1;
    //    SDL_Delay(5);
    //    if (m_destinationRectangle.x == 0) //이미지가 왼쪽 최후방에 닿았을 때 변수 전환
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

    m_sourceRectangle.x = 128 * ((SDL_GetTicks()/100) % 6);

}

void Game::render()
{
    //RenderClear = 화면지움
    SDL_RenderClear(m_pRenderer);
    //RenderCopy = 그리기 수행
   // SDL_RenderCopy(m_pRenderer, m_pCart_back, &m_Cart_Back_SRect, &m_Cart_Back_DRect);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    
    
    //SDL_FLIP -> NONE = 원본상태, _VERTICAL = 상하 뒤집기, HORIZONTAL = 좌우 뒤집기
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
    SDL_DestroyTexture(m_pTexture); //Texture 제거 추가
  //  SDL_DestroyTexture(m_pCart_back); //Texture 제거
    //SDL_DestroyRect();  << ?
    SDL_Quit();
}