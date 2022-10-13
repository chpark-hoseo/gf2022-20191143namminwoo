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

    o_textureManager.load("Assets/m_Move.png", "Player_", m_pRenderer);
    m_textureManager.load("Assets/Maple_bg.jfif", "Maple_bg", m_pRenderer);
    o_textureManager.load("Assets/m_Jump.png", "Player_jump", m_pRenderer);

    m_bRunning = true;
    return true;
}

void Game::update()
{
    keyPad();
    Jump();
    camera();

    o_currentFrame = ((SDL_GetTicks() / 100) % 5);

    SDL_Delay(10);
   //keyPad();
}

void Game::keyPad()
{
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        if (move_x <= 0)
        {
            move_x -= 0;
        }
        else
        {
            move_x -= 5;
        }
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        if (move_x >= 1855)
        {
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
    if (currentJump == false) return; //Ű �ѹ� �Է� �� �ߺ� �Է� ����

    else if (currentJump == true)
    { 
        move_y += m_JumpSpeed;
        if (move_x <= 0)
        {
            move_x = 0;
        }
        else if (move_x >= 1822)
        {
            move_x = 1810;
        }
        else
        {
            move_x += x*-10;   //������ ���ڸ� ����, ������ �������� ����
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

    //Keep the camera in bounds
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
    //RenderClear = ȭ������
    SDL_RenderClear(m_pRenderer);

    m_textureManager.draw("Maple_bg", -cameraX, -cameraY, 1920, 1080, m_pRenderer);

    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        x = 1; //������ ���� �������� case 1
        o_textureManager.drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98, 87,
            0, o_currentFrame, m_pRenderer);
    }
    else if((currentKeyStates[SDL_SCANCODE_RIGHT]))
    {
        x = -1; //�������� ���� ���� ���� case 2
        o_textureManager.drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98, 87,
            1, o_currentFrame, m_pRenderer);
    }
    else if (currentKeyStates[SDL_SCANCODE_SPACE]) //����
    {
        stop();
    }
    else //���� ��
    {
        stop();
    }

    //RenderPresent = �׸��� ȣ��
    SDL_RenderPresent(m_pRenderer);  
}

void Game::stop() //�����̴ٰ� ���ߴ� ��츦 ���� �Լ�
{
    if (x == 1) //������ ���ٰ� ���� ��
    {
        m_textureManager.draw("Player_jump", move_x - cameraX, move_y - cameraY, 98, 87, m_pRenderer);
    }
    else if (x == -1) //�������� ���ٰ� ���� ��
    {
        o_textureManager.drawFrame("Player_jump", move_x - cameraX, move_y - cameraY, 98, 87, 1, NULL, m_pRenderer);
    }
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