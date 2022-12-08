#include "Player.h"
#include "InputHandler.h"

bool Player::attack;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Player::draw()
{
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

   if (vec->getX()>=500) { //������ �ȱ�
       x = 1;
       SDLGameObject::m_currentRow = 1;
   }
   else  { //���� �ȱ�
       x = -1;
       SDLGameObject::m_currentRow = 0;
   }
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

    //std::cout << attack << std::endl;

	m_velocity.setX(0); //Ű�Է� �ϴ� ���ȸ� �����̰�
    m_velocity.setY(0);

	handleInput();

	SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 

    //if (m_position.getY() <= 655) //�߷� ���ӵ�
    //{
    //    m_acceleration.setY(m_JumpSpeed * -1);
    //}
    //else //���� ����� ��
    //{
    //    m_acceleration.setX(0);
    //    m_acceleration.setY(0);
    //    currentJump = false;
    //}
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
}
//void Player::jump()
//{
//    if (currentJump == false)  return;
//    else if (currentJump == true)
//    {
//        m_acceleration.setY(m_JumpSpeed);
//        m_acceleration.setX(x * 20);
//
//
//
//        ////�����ϴ� �߿��� ȭ�� ���� ����� �ʰ�
//        //if ((m_position.getX() + 100 / 2 > LEVEL_HEIGHT) || m_position.getX() < 0)
//        //{
//        //    m_acceleration.setY(-10 /*- Camera::cameraY*/);
//        //    m_velocity.setX(0);
//        //}
//        //else
//        //{
//        //    m_acceleration.setY(-10 /*- Camera::cameraY*/);
//        //    m_acceleration.setX(x * 5 /*- Camera::cameraX*/);
//        //}
//    }
//}
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