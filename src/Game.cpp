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

    if (!TheTextureManager::Instance()->load("Assets/back.png", "Back", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/obstac.png", "Floor", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/m_Move2.png", "Player_", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/m_Jump.png", "Player_jump", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/m_Smash.png", "Player_hit", m_pRenderer))
    {
        return false;
    }
    m_bRunning = true;
    return true;
}

void Game::update()
{
    keyPad();
    Jump();
    camera();

    o_currentFrame = ((SDL_GetTicks() / 100) % 5); //5칸 프레임
    m_currentFrame = ((SDL_GetTicks() / 100) % 4); //4칸 프레임

    SDL_Delay(10);
}

void Game::keyPad()
{
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        if (move_x <= 0)
        {
            std::cout << move_x << std::endl;
            move_x -= 0;
        }
        else
        {
            move_x -= 5;
        }
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        if (move_x >= 1070)
        {
            std::cout << move_x << std::endl;
            move_x += 0;
        }
        else
        {
            move_x += 5;
        }
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
        if (move_x <= 0)
        {
            move_x = 0;
        }
        else if (move_x >= 1080)
        {
            move_x = 1080;
        }
        else
        {
            move_x += x*-10;   //없으면 제자리 점프, 있으면 전방으로 점프
        }
        SDL_Delay(20);
        m_JumpSpeed += 10;
        if (m_JumpSpeed == 60)
        {
            currentJump = false;
            m_JumpSpeed = -50;
        }
    }
}
void Game::camera()
{
    cameraX = (move_x + 98 / 2) - SCREEN_WIDTH / 2;
    cameraY = (move_y + 87 / 2) - SCREEN_HEIGHT / 2;

    if (cameraX < 0)
    {
        cameraX = 0;
    }
    if (cameraY < 0)
    {
        cameraY = 0;
    }
    if (cameraX > LEVEL_WIDTH - SCREEN_WIDTH)
    {
        cameraX = LEVEL_WIDTH - SCREEN_WIDTH;
    }
    if (cameraY > LEVEL_HEIGHT - SCREEN_HEIGHT)
    {
        cameraY = LEVEL_HEIGHT - SCREEN_HEIGHT;
    }
}
void Game::render()
{
    //RenderClear = 화면지움
    SDL_RenderClear(m_pRenderer);

    TheTextureManager::Instance()->draw("Back", -cameraX, -cameraY, 1160, 10000,
        m_pRenderer); 
    TheTextureManager::Instance()->draw("Floor", 50, 9900, 200, 75,
            m_pRenderer);

    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        x = 1; //왼쪽을 보고 있을때는 case 1
        TheTextureManager::Instance()->drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98,
            87, 0, o_currentFrame, m_pRenderer);
    }
    else if((currentKeyStates[SDL_SCANCODE_RIGHT]))
    {
        x = -1; //오른쪽을 보고 있을 때는 case 2
        TheTextureManager::Instance()->drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98,
            87, 1, o_currentFrame, m_pRenderer);
    }
    else if ((currentKeyStates[SDL_SCANCODE_LCTRL])) //공격
    {
        if (x == 1)
        {
            SDL_Delay(5);
            TheTextureManager::Instance()->drawFrame("Player_hit", move_x - cameraX + 10, move_y - cameraY - 15, 125,
                112, 0, m_currentFrame, m_pRenderer);
        }
        else if (x == -1)
        {
            SDL_Delay(5);
            TheTextureManager::Instance()->drawFrame("Player_hit", move_x - cameraX + 10, move_y - cameraY - 15, 125,
                112, 1, m_currentFrame, m_pRenderer);
        }
    }
    else if (currentJump == true) //점프
    {
        if (x == 1)
        {
            TheTextureManager::Instance()->draw("Player_jump", move_x - cameraX, move_y - cameraY, 90, 103,
                m_pRenderer);
        }
        else if (x == -1)
        {
            TheTextureManager::Instance()->drawFrame("Player_jump", move_x - cameraX, move_y - cameraY, 90,
                103, 1, NULL, m_pRenderer);
        }
    }
    else //멈출 때
    {
        if (x == 1) //왼쪽을 보다가 멈출 때
        {
            TheTextureManager::Instance()->draw("Player_", move_x - cameraX, move_y - cameraY, 98, 87,
                m_pRenderer);
        }
        else if (x == -1) //오른쪽을 보다가 멈출 때
        {
            TheTextureManager::Instance()->drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98,
                87, 1, NULL, m_pRenderer);
        }
    }

    //std::cout << move_x << " " << move_y << std::endl;
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
    //SDL_DestroyTexture(m_pTexture); //Texture 제거 추가
    SDL_Quit();
}