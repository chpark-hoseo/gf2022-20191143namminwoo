#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        SDLGameObject::m_currentRow = 1;
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        SDLGameObject::m_currentRow = 0;
    }
    SDLGameObject::draw();
}

void Player::update()
{
	m_velocity.setX(0);
    m_velocity.setY(0);
	handleInput();
	SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5); //키입력 도중에만 프레임 나오게
        attack = false;
        x = 1;
        m_velocity.setX(5);
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        attack = false;
        x = -1;
        m_velocity.setX(-5);
    }
    else  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        attack = false;
        m_velocity.setY(-5);
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        attack = false;
        m_velocity.setY(5);
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) { //점프
        m_currentFrame = 0;
        currentJump = true;
        attack = false;
        jump();
    }
    //else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LCTRL)) //공격
    //{
    //    m_currentFrame = ((SDL_GetTicks() / 100) % 4);
    //    attack = true;
    //}
    else
    {
        m_currentFrame = 0;
    }
}
void Player::jump()
{
    if (currentJump == false) return; //키 한번 입력 후 중복 입력 방지

    else if (currentJump == true)
    {
        m_velocity.setY(m_JumpSpeed);
        m_velocity.setX(x * 10);//없으면 제자리 점프, 있으면 전방으로 점프
        m_JumpSpeed += 10;

        if (m_JumpSpeed == 60)
        {
            currentJump = false;
            m_JumpSpeed = -50;
        }
    }
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