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

	m_velocity.setX(0); //키입력 하는 동안만 움직이게
    m_velocity.setY(0);

	handleInput();
    player_collide();

	SDLGameObject::update(); // ← 부모 클래스의 함수 호출 

}

void Player::handleInput()
{
    if (x == 1 && TheInputHandler::Instance()->getMouseButtonState(LEFT)) //오른쪽
    {
        attack = true;
    }
    else if (x == -1 && TheInputHandler::Instance()->getMouseButtonState(LEFT)) //왼쪽
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
        //std::cout << "부딪혔다!" << std::endl;
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
                return false; //누르고 있을땐 2가됨
            else
                return ++push; //한번 눌렀을 때 1이되어 한번만 처리가 된다.
        }
        else {
            push = 0;// 떼었을 때
            return false;
        }
    }
    return false;
}