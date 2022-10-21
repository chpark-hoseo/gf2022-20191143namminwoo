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

    if (!TheTextureManager::Instance()->load("Assets/back.png", "Back", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/obstac.png", "Floor", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/ladder.png", "Ladder", m_pRenderer))
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
    if (!TheTextureManager::Instance()->load("Assets/m_Jump.png", "Player_jump", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/m_Smash.png", "Player_hit", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->load("Assets/Orange_mush.png", "Monster", m_pRenderer))
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
    collider();

    //�̹��� �¿��̵� ������(5)
    o_currentFrame = ((SDL_GetTicks() / 100) % 5); 
    //ĳ���� ���� ������
    if (currentHit)
    {
        m_currentFrame = (hitTime/4)%4;
        hitTime++;
    }

    //����1 �¿� �̵�
    if (mob1_x >= 567)
    {
        mob1_move_x = mob1_move_x * -1;
    }
    else if (mob1_x <= 0)
    {
        mob1_move_x = mob1_move_x * -1;
    }
    mob1_x += mob1_move_x;

    //����1 ���ݹ���
    if (mob1_collid == true && currentHit == true)
    {
        if (m_currentFrame == 3)
        {
            mob1_current = true;
        }
    }
    SDL_Delay(10);
}
void Game::collider()
{
    //�÷��̾�� ����1 �浹
    if ((mob1_x + 63 >= move_x) && (mob1_x <= move_x + 98)) //����-�÷��̾� && �÷��̾�-����
    {
        mob1_collid = true;
    }
    else //�浹���� ���� ��
    {
        mob1_collid = false;
    }

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
            move_x -= 3;
        }
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        if (move_x >= 1070)
        {
            move_x += 0;
        }
        else
        {
            move_x += 3;
        }
    }
    else if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
        if (move_y >= 9893)
        {
            move_y += 0;
        }
        else
        {
            move_y += 3;
        }
    }
    else if (currentKeyStates[SDL_SCANCODE_UP])
    {
        if (move_y <= 0)
        {
            move_y += 0;
        }
        else
        {
            move_y -= 3;
        }
    }
    else if (currentKeyStates[SDL_SCANCODE_SPACE])
    {
        currentJump = true;
    }
    else if ((currentKeyStates[SDL_SCANCODE_LCTRL]))
    {
        currentHit = true;
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
        else if (move_x >= 1080)
        {
            move_x = 1080;
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
    //��� �̹���
    TheTextureManager::Instance()->draw("Back", -cameraX, -cameraY, 1160, 10000,
        m_pRenderer); 
    //�ٴ� �̹���
    {
        TheTextureManager::Instance()->draw("Floor", 10 - cameraX, 9950 - cameraY, 200, 75, m_pRenderer);
        TheTextureManager::Instance()->draw("Floor", 210 - cameraX, 9950 - cameraY, 200, 75, m_pRenderer);
        TheTextureManager::Instance()->draw("Floor", 410 - cameraX, 9950 - cameraY, 200, 75, m_pRenderer);
        TheTextureManager::Instance()->draw("Floor", 610 - cameraX, 9950 - cameraY, 200, 75, m_pRenderer);
        TheTextureManager::Instance()->draw("Floor", 810 - cameraX, 9950 - cameraY, 200, 75, m_pRenderer);
        TheTextureManager::Instance()->draw("Floor", 1010 - cameraX, 9950 - cameraY, 200, 75, m_pRenderer);
    } 
    //���� �̹���
    {
        TheTextureManager::Instance()->draw("Floor", 360 - cameraX, 9650 - cameraY, 200, 75, m_pRenderer);
        TheTextureManager::Instance()->draw("Floor", 160 - cameraX, 9650 - cameraY, 200, 75, m_pRenderer);
        TheTextureManager::Instance()->draw("Ladder", 420 - cameraX, 9650 - cameraY, 140, 200, m_pRenderer);

        TheTextureManager::Instance()->draw("Floor", 110 - cameraX, 9400 - cameraY, 200, 75, m_pRenderer);
        TheTextureManager::Instance()->draw("Ladder", 160 - cameraX, 9400 - cameraY, 140, 200, m_pRenderer);
    }
    //Ű�Է¿� ���� �÷��̾� �̹���
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        x = 1; //������ ���� �������� case 1
        TheTextureManager::Instance()->drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98,
            87, 0, o_currentFrame, m_pRenderer);
    }
    else if((currentKeyStates[SDL_SCANCODE_RIGHT]))
    {
        x = -1; //�������� ���� ���� ���� case 2
        TheTextureManager::Instance()->drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98,
            87, 1, o_currentFrame, m_pRenderer);
    }
    else if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
        x = 1; //������ ���� �������� case 1
        TheTextureManager::Instance()->drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98,
            87, 0, o_currentFrame, m_pRenderer);
    }
    else if ((currentKeyStates[SDL_SCANCODE_UP]))
    {
        x = -1; //�������� ���� ���� ���� case 2
        TheTextureManager::Instance()->drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98,
            87, 1, o_currentFrame, m_pRenderer);
    }
    else if (currentJump == true) //����
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
    else if (currentHit == true)
    {
        //std::cout << m_currentFrame << std::endl;
        if (x == 1)
        {
            TheTextureManager::Instance()->drawFrame("Player_hit", move_x - cameraX-15, move_y - cameraY-20, 122,
                112, 0, m_currentFrame, m_pRenderer);
            SDL_Delay(20);
        }
        else if (x == -1)
        {
            TheTextureManager::Instance()->drawFrame("Player_hit", move_x - cameraX-15, move_y - cameraY-20, 122,
                112, 1, m_currentFrame, m_pRenderer);
            SDL_Delay(20);
        }
    }
    else //���� ��
    {
        if (x == 1) //������ ���ٰ� ���� ��
        {
            TheTextureManager::Instance()->draw("Player_", move_x - cameraX, move_y - cameraY, 98, 87,
                m_pRenderer);
        }
        else if (x == -1) //�������� ���ٰ� ���� ��
        {
            TheTextureManager::Instance()->drawFrame("Player_", move_x - cameraX, move_y - cameraY, 98,
                87, 1, NULL, m_pRenderer);
        }
    }
    //���ݸ�� �̹���
    if (m_currentFrame == 3)
    {
        currentHit = false;
        m_currentFrame = 0;
        hitTime = 0;
    }
    //����1 �̹���
    if (mob1_current == false)
    {
        if (mob1_move_x == -1)
        {
            TheTextureManager::Instance()->drawFrame("Monster", mob1_x - cameraX, mob1_y - cameraY, 63,
                69, 0, o_currentFrame, m_pRenderer);
        }
        else if (mob1_move_x == 1)
        {
            TheTextureManager::Instance()->drawFrame("Monster", mob1_x - cameraX, mob1_y - cameraY, 63,
                69, 1, o_currentFrame, m_pRenderer);
        }
    }
    else if (mob1_current == true) //���� �浹&���� ���� �� �̹��� ����
    {
    }


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
    //SDL_DestroyTexture(m_pTexture); //Texture ���� �߰�
    SDL_Quit();
}