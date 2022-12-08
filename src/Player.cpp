#include "Player.h"
#include "InputHandler.h"

bool Player::attack;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Player::draw()
{
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

   if (vec->getX()>=500) { //오른쪽 걷기
       x = 1;
       SDLGameObject::m_currentRow = 1;
   }
   else  { //왼쪽 걷기
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

	m_velocity.setX(0); //키입력 하는 동안만 움직이게
    m_velocity.setY(0);

	handleInput();

	SDLGameObject::update(); // ← 부모 클래스의 함수 호출 

    //if (m_position.getY() <= 655) //중력 가속도
    //{
    //    m_acceleration.setY(m_JumpSpeed * -1);
    //}
    //else //땅에 닿았을 때
    //{
    //    m_acceleration.setX(0);
    //    m_acceleration.setY(0);
    //    currentJump = false;
    //}
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
//        ////점프하는 중에도 화면 밖을 벗어나지 않게
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