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
    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
	m_velocity.setX(0);
    m_velocity.setY(0);
	handleInput();
	SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 
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
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) { //����
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
    //if (currentJump == false) return; //Ű �ѹ� �Է� �� �ߺ� �Է� ����

    //else if (currentJump == true)
    //{
    //    m_velocity.setY(m_JumpSpeed);
    //    m_velocity.setX(x * 10);    //������ ���ڸ� ����, ������ �������� ����
    //    m_JumpSpeed += 10;

    //    if (m_JumpSpeed == 60)
    //    {
    //        currentJump = false;
    //        m_JumpSpeed = -50;
    //    }
    //}

    if (currentJump == false) return;
    else if (currentJump == true)
    {
        m_velocity.setY(m_JumpSpeed);
        m_velocity.setX(x * 10);
        m_JumpSpeed += 4;
        std::cout << m_JumpSpeed << std::endl;

        if (m_JumpSpeed == 24)
        {
            currentJump = false;
            m_JumpSpeed = -20;
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