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
    { //�����̴� ������
        SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");        
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        m_destinationRectangle.w = m_sourceRectangle.w = 128;
        m_destinationRectangle.h = m_sourceRectangle.h = 82;
        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_sourceRectangle.y = 0;
        m_destinationRectangle.y = 400;
    }
    { //������ �������� ��ü
        SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/Mush.bmp");
        o_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        o_destinationRectangle.w = o_sourceRectangle.w = 147;
        o_destinationRectangle.h = o_sourceRectangle.h = 154;
        o_sourceRectangle.x = 298;
        o_destinationRectangle.x = 500;
        o_destinationRectangle.y = o_sourceRectangle.y = 0;
    }
    {//������ ���� ������
        SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");
        f_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
        SDL_FreeSurface(pTempSurface);
        f_destinationRectangle.w = f_sourceRectangle.w = 128;
        f_destinationRectangle.h = f_sourceRectangle.h = 82;
        f_destinationRectangle.x = f_sourceRectangle.x = 0;
        f_sourceRectangle.y = 0;
        f_destinationRectangle.y = 200;
    }
    m_bRunning = true;
    return true;
}

void Game::update()
{
   keyPad();
   Jump();
   ////��ü ���� ����
   //m_destinationRectangle.y += j;
   ////SDL_Delay(5);
   //if (m_destinationRectangle.y<350)
   //{
   //    j = 1;
   //}
   //else if (m_destinationRectangle.y > 401)
   //{
   //    j = 0;
   //}
   ////��ü ������ ���� ����
   //f_destinationRectangle.y += j1;
   //f_destinationRectangle.x += j2;
   ////SDL_Delay(5);
   //if (f_destinationRectangle.y < 150)
   //{
   //    j1 = 1;
   //}
   //else if (f_destinationRectangle.y > 201)
   //{
   //    j1 = 0;
   //    j2 = 0;
   //}

   //��ü �������°� ����
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
        SDL_Delay(1);
    }
    else if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        x = 1;
        m_destinationRectangle.x += x;
        m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 150) % 6);
        SDL_Delay(1);
    }
    else if (currentKeyStates[SDL_SCANCODE_SPACE])
    {
        currentJump = true;       
    }
    else
    {
        m_sourceRectangle.x = 0;
    }
}

void Game::Jump()
{
    if (currentJump == false) return; //Ű �ѹ� �Է� �� �ߺ� �Է� ����

    else if (currentJump == true)
    {
        m_sourceRectangle.x = 256; //���� ������� �̹��� ����
        std::cout << m_destinationRectangle.y << " " << m_JumpSpeed << std::endl;
        m_destinationRectangle.y += m_JumpSpeed;
        //m_destinationRectangle.x += x*15;   //������ ���ڸ� ����, ������ �������� ����
        SDL_Delay(20);
        m_JumpSpeed += 10;
        if (m_JumpSpeed == 60)
        {
            currentJump = false;
            m_JumpSpeed = -50;
        }
 /*       if (m_JumpSpeed < 0)
        {
            m_JumpSpeed += 2;
        }
        else if (m_JumpSpeed == 0)
        {
            m_JumpSpeed += 2;
        }*/

    }
}
void Game::render()
{
    //RenderClear = ȭ������
    SDL_RenderClear(m_pRenderer);
    //RenderCopy = �׸��� ����
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
    SDL_RenderCopy(m_pRenderer, f_pTexture, &f_sourceRectangle, &f_destinationRectangle);
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
    while (SDL_PollEvent(&event)) //������ ������ �ƴ� �ܼ�â ���� ����
                                 //���� �����ϰ� ����� ���ؼ���� ������
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
    SDL_Quit();
}