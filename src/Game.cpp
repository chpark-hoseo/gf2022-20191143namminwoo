#include "Game.h"
//#include "SDL_image.h"
#include <SDL2/SDL_image.h>
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
    { //움직이는 강아지
        SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");        
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        m_destinationRectangle.w = m_sourceRectangle.w = 128;
        m_destinationRectangle.h = m_sourceRectangle.h = 82;
        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_sourceRectangle.y = 0;
        m_destinationRectangle.y = 400;
    }
    { //위에서 떨어지는 물체
        SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/Mush.bmp");
        o_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        o_destinationRectangle.w = o_sourceRectangle.w = 147;
        o_destinationRectangle.h = o_sourceRectangle.h = 154;
        o_sourceRectangle.x = 298;
        o_destinationRectangle.x = 500;
        o_destinationRectangle.y = o_sourceRectangle.y = 0;
    }
    m_bRunning = true;
    return true;
}

void Game::update()
{
   keyPad();

   //물체 떨어지는거 구현
   o_destinationRectangle.y += y;
   SDL_Delay(3);
   //SDL_Delay(5);
   if (o_destinationRectangle.y > (SCREEN_HEIGHT - o_sourceRectangle.h + 15))
   {
       y = 0;
       o_sourceRectangle.x = 589;
   }
}

void Game::keyPad()
{
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        x = -1;
        m_destinationRectangle.x += x;
        m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 150) % 6);
        SDL_Delay(3);
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        x = 1;
        m_destinationRectangle.x += x;
        m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 150) % 6);
        SDL_Delay(3);
    }
    else if (currentKeyStates[SDL_SCANCODE_SPACE])
    {
        Jump();
        m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 150) % 6);
    }
    else
    {
        m_sourceRectangle.x = 256;
    }
}

void Game::Jump()
{

}

void Game::render()
{
    //RenderClear = 화면지움
    SDL_RenderClear(m_pRenderer);
    //RenderCopy = 그리기 수행
    if (x == -1)
    {
        SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle,
            NULL, NULL, SDL_FLIP_HORIZONTAL);
    }
    else
    {
        SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle); 
    }
    SDL_RenderCopy(m_pRenderer, o_pTexture, &o_sourceRectangle, &o_destinationRectangle);
    //RenderPresent = 그린거 호출
    SDL_RenderPresent(m_pRenderer);  
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
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
    SDL_DestroyTexture(o_pTexture);
    SDL_Quit();
}