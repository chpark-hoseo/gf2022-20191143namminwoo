#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Player::draw()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) { //������ �ȱ�
        x = 1;
        SDLGameObject::m_currentRow = 1;
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) { //���� �ȱ�
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
	SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 

    if (m_position.getY() < 500) //�߷� ���ӵ�
    {
        m_acceleration.setY(m_JumpSpeed * -1);
    }
    else //���� ����� ��
    {
        m_acceleration.setX(0);
        m_acceleration.setY(0);
        currentJump = false;
    }
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5); //Ű�Է� ���߿��� ������ ������
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
    else if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_SPACE)) { //����
        m_currentFrame = 0;
        currentJump = true;
        jump();
    }
    else
    {
        m_currentFrame = 0; //�������� ���� ���� ������
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