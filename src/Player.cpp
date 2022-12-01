#include "Player.h"
#include "InputHandler.h"
#include "Camera.h"
float Player::player_X;
float Player::player_Y;
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
    //std::cout << "x : " << m_position.getX() << " " << "y : " << m_position.getY() << std::endl;
    m_currentFrame = ((SDL_GetTicks() / 100) % 5);

    player_X = m_position.getX();
    player_Y = m_position.getY();

	m_velocity.setX(0); //Ű�Է� �ϴ� ���ȸ� �����̰�
    m_velocity.setY(0);

	handleInput();

	SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 

    if (m_position.getY() <= 650) //�߷� ���ӵ�
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
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);   //Ű�Է� ���߿��� ������ ������
        if ((m_position.getX() + 100 / 2 > LEVEL_WIDTH)) {  //ȭ�� ������ ������ ���ϰ�
            m_velocity.setX(0) ;
        }
        else
        {
            m_velocity.setX(5 - Camera::cameraX);
        }
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        if (m_position.getX() < 0)   //ȭ�� ������ ������ ���ϰ�
        {
            m_velocity.setX(0);
        }
        else
        {
            m_velocity.setX(-5 - Camera::cameraX);
        }
    }
    else  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);

        if (m_position.getY() < 0)  //ȭ�� ������ ������ ���ϰ�
        {
            m_velocity.setY(0);
        }
        else
        {
            m_velocity.setY(-5 - Camera::cameraY);
        }
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);

        if ((m_position.getY() + 100 / 2 > LEVEL_HEIGHT)) {  //ȭ�� ������ ������ ���ϰ�
            m_velocity.setY(0);
        }
        else
        {
            m_velocity.setY(5 - Camera::cameraY);
        }
    }
    else if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_SPACE)) {   //����
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
        //�����ϴ� �߿��� ȭ�� ���� ����� �ʰ�
        if ((m_position.getX() + 100 / 2 > LEVEL_HEIGHT) || m_position.getX() < 0)
        {
            m_acceleration.setY(m_JumpSpeed /*- Camera::cameraY*/);
            m_velocity.setX(0);
        }
        else
        {
            m_acceleration.setY(m_JumpSpeed /*- Camera::cameraY*/);
            m_acceleration.setX(x * 5 /*- Camera::cameraX*/);
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