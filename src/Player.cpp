#include "Player.h"
#include "InputHandler.h"
#include "Game.h"

bool Player::attack;
bool Player::player_hit;
int Player::player_X;
int Player::player_Y;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {
    player_hit = false;
}
void Player::draw()
{
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

   SDLGameObject::draw();
}

void Player::update()
{
    //if (attack == true)
    //{
    //    m_currentFrame = (hitTime / 4) % 4;
    //    hitTime++;
    //}
    //if (m_currentFrame == 3)
    //{
    //    m_currentFrame = 0;
    //    hitTime = 0;
    //}
    m_currentFrame = 0;

    player_X = m_position.getX();
    player_Y = m_position.getY();

	m_velocity.setX(0); //Ű�Է� �ϴ� ���ȸ� �����̰�
    m_velocity.setY(0);

	handleInput();
    player_collide();

	SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 

}

void Player::handleInput()
{
    if (x == 1 && TheInputHandler::Instance()->getMouseButtonState(LEFT)) //������
    {
        attack = true;
    }
    else if (x == -1 && TheInputHandler::Instance()->getMouseButtonState(LEFT)) //����
    {
        attack = true;
    }
    else
    {
        attack = false;
    }

    if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_A))
    {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        m_velocity.setX(-5);
        SDLGameObject::m_currentRow = 0;
        if (m_position.getX() <= 0)
        {
            m_velocity.setX(5);
        }
    }
    if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_D))
    {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        m_velocity.setX(5);
        SDLGameObject::m_currentRow = 1;
        if(m_position.getX()+100>=1000)
        {
            m_velocity.setX(-5);
        }
    }
}
void Player::player_collide()
{
    if (player_hit == true)
    {
        //std::cout << "�ε�����!" << std::endl;
        Game::gamePlay = 1.5;
    }
    else return;
}

void Player::clean() {}

bool InputHandler::isKeyOneDown(SDL_Scancode key) {
    static int push = 0;
    if (m_keystates != 0) {
        if (m_keystates[key] == 1)
        {
            if (push == 2)
                return false; //������ ������ 2����
            else
                return ++push; //�ѹ� ������ �� 1�̵Ǿ� �ѹ��� ó���� �ȴ�.
        }
        else {
            push = 0;// ������ ��
            return false;
        }
    }
    return false;
}