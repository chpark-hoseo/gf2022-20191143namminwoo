#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Player::update()
{
    if (currentHit)
    {
        m_currentFrame = (hitTime / 4) % 4;
        hitTime++;
    }
    else
    {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    }


    { //점프 코드
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
                move_x += x * -10;   //없으면 제자리 점프, 있으면 전방으로 점프
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

    { //키입력 코드
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

    {
        //플레이어와 몬스터1 충돌
        if ((mob1_x + 63 >= move_x) && (mob1_x <= move_x + 98)) //몬스터-플레이어 && 플레이어-몬스터
        {
            mob1_collid = true;
        }
        else //충돌하지 않을 시
        {
            mob1_collid = false;
        }
    }
}