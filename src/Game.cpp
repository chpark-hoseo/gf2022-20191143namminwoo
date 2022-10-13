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
    o_textureManager.load("Assets/Player_.png", "Player_", m_pRenderer);

    m_bRunning = true;
    return true;
}

void Game::update()
{
    keyPad();
    Jump();
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    o_currentFrame = ((SDL_GetTicks() / 100) % 5);
    SDL_Delay(10);
   //keyPad();
}

void Game::keyPad()
{
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        move_x -= 1;
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        move_x += 1;
    }
    else if (currentKeyStates[SDL_SCANCODE_SPACE])
    {
        currentJump = true;
    }
}

void Game::Jump()
{
    if (currentJump == false) return; //키 한번 입력 후 중복 입력 방지

    else if (currentJump == true)
    { 
        move_y += m_JumpSpeed;
        move_x += x*-15;   //없으면 제자리 점프, 있으면 전방으로 점프
        SDL_Delay(20);
        m_JumpSpeed += 10;
        if (m_JumpSpeed == 60)
        {
            currentJump = false;
            m_JumpSpeed = -50;
        }
    }
}
void Game::render()
{
    //RenderClear = 화면지움
    SDL_RenderClear(m_pRenderer);

    m_textureManager.draw("animate", 0,0, 128, 82, m_pRenderer);
    m_textureManager.drawFrame("animate", 100, 100, 128, 82,
        0, m_currentFrame, m_pRenderer);

    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        x = 1; //왼쪽을 보고 있을때는 case 1
        o_textureManager.drawFrame("Player_", move_x, move_y, 65, 63,
            0, o_currentFrame, m_pRenderer);
    }
    else if((currentKeyStates[SDL_SCANCODE_RIGHT]))
    {
        x = -1; //오른쪽을 보고 있을 때는 case 2
        o_textureManager.drawFrame("Player_", move_x, move_y, 65, 63,
            1, o_currentFrame, m_pRenderer);
    }
    else if (currentKeyStates[SDL_SCANCODE_SPACE])
    {
        stop();
    }
    else //멈출 때
    {
        stop();
    }

    //RenderPresent = 그린거 호출
    SDL_RenderPresent(m_pRenderer);  
}

void Game::stop() //움직이다가 멈추는 경우를 위한 함수
{
    if (x == 1) //왼쪽을 보다가 멈출 때
    {
        o_textureManager.draw("Player_", move_x, move_y, 65, 63, m_pRenderer);
    }
    else if (x == -1) //오른쪽을 보다가 멈출 때
    {
        o_textureManager.drawFrame("Player_", move_x, move_y, 65, 63, 1, NULL, m_pRenderer);
    }
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
    //SDL_DestroyTexture(m_pTexture); //Texture 제거 추가
    SDL_Quit();
}