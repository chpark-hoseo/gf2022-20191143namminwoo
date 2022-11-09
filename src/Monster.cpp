#include "Monster.h"
#include "Player.h"
void Monster::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Monster::update(/*int speed, int length*/)
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	//m_x += m_speed;
	//if (m_x == m_length)
	//{
	//	m_speed = -m_speed;
	//}
	//else if (m_x == 0)
	//{
	//	m_speed = -m_speed;
	//}

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
}
