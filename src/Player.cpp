#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Player::draw()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) { //오른쪽 걷기
        x = 1;
        SDLGameObject::m_currentRow = 1;
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) { //왼쪽 걷기
        x = -1;
        SDLGameObject::m_currentRow = 0;
    }
    SDLGameObject::draw();
}

void Player::update()
{
    std::cout << "x : " << m_position.getX() << " " << "y : " << m_position.getY() << std::endl;
    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
	m_velocity.setX(0);
    m_velocity.setY(0);
	handleInput();
	SDLGameObject::update(); // ← 부모 클래스의 함수 호출 

    if (m_position.getY() < 500) //중력 가속도
    {
        m_acceleration.setY(m_JumpSpeed * -1);
    }
    else //땅에 닿았을 때
    {
        m_acceleration.setX(0);
        m_acceleration.setY(0);
        currentJump = false;
    }
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5); //키입력 도중에만 프레임 나오게
        m_velocity.setX(5);
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        m_velocity.setX(-5);
    }
    else  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        m_velocity.setY(-5);
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        m_velocity.setY(5);
    }
    else if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_SPACE)) { //점프
        m_currentFrame = 0;
        currentJump = true;
        jump();
    }
    else
    {
        m_currentFrame = 0; //움직이지 않을 때는 가만히
    }
}
void Player::jump()
{
    if (currentJump == false)  return;
    else if (currentJump == true)
    {
        m_acceleration.setY(m_JumpSpeed);
        m_acceleration.setX(x * 25);
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