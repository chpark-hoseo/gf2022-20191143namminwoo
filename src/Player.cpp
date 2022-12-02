#include "Player.h"
#include "InputHandler.h"
#include "Camera.h"

float Player::player_X;
float Player::player_Y;
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
    //std::cout << Player::m_x << std::endl;
    //std::cout << "x : " << m_position.getX() << " " << "y : " << m_position.getY() << std::endl;
    m_currentFrame = ((SDL_GetTicks() / 100) % 5);

    player_X = p_x;
    player_Y = p_x;

	m_velocity.setX(0); //키입력 하는 동안만 움직이게
    m_velocity.setY(0);

	handleInput();

	SDLGameObject::update(); // ← 부모 클래스의 함수 호출 

    if (m_position.getY() <= 655) //중력 가속도
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
    //if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    //    m_currentFrame = ((SDL_GetTicks() / 100) % 5);   //키입력 도중에만 프레임 나오게
    //    if ((m_position.getX() + 100 / 2 > LEVEL_WIDTH)) {  //화면 밖으로 나가지 못하게
    //        m_velocity.setX(0) ;
    //    }
    //    else
    //    {
    //        m_velocity.setX(5 - Camera::cameraX);
    //    }
    //}
    //else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    //    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    //    if (m_position.getX() < 0)   //화면 밖으로 나가지 못하게
    //    {
    //        m_velocity.setX(0);
    //    }
    //    else
    //    {
    //        m_velocity.setX(-5 - Camera::cameraX);
    //    }
    //}
    //else  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
    //    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    //    if (m_position.getY() < 0)  //화면 밖으로 나가지 못하게
    //    {
    //        m_velocity.setY(0);
    //    }
    //    else
    //    {
    //        m_velocity.setY(-5 - Camera::cameraY);
    //    }
    //}
    //else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
    //    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    //    if ((m_position.getY() + 100 / 2 > LEVEL_HEIGHT)) {  //화면 밖으로 나가지 못하게
    //        m_velocity.setY(0);
    //    }
    //    else
    //    {
    //        m_velocity.setY(5 - Camera::cameraY);
    //    }
    //}
    //else if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_SPACE)) {   //점프
    //    m_currentFrame = 0;
    //    currentJump = true;
    //    jump();
    //}
    //else
    //{
    //    m_currentFrame = 0; //움직이지 않을 때는 가만히                                                               
    //}

    std::cout << "x : " << p_x << " y : " << p_y << std::endl;

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);   //키입력 도중에만 프레임 나오게
        if (p_x > 1060)
        {
            m_velocity.setX(0);
        }
        else if (p_x >= 500 && p_x <= 660)
        {
            m_velocity.setX(0);
            p_x += 5;
        }
        else
        {
            m_velocity.setX(5);
            p_x += 5;
        }
    }
    else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        if (p_x < 0)
        {
            m_velocity.setX(0);
        }
        else if (p_x >= 500 && p_x <= 660)
        {
            m_velocity.setX(0);
            p_x -= 5;
        }
        else
        {
            m_velocity.setX(-5);
            p_x -= 5;
        }
    }
    //else  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
    //    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    //    m_velocity.setY(-5);
    //    p_y -= 5;
    //}
    //else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
    //    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    //    m_velocity.setY(5);
    //    p_y += 5;
    //}
    else if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_SPACE)) {   //점프
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
        m_acceleration.setX(x * 20);



        ////점프하는 중에도 화면 밖을 벗어나지 않게
        //if ((m_position.getX() + 100 / 2 > LEVEL_HEIGHT) || m_position.getX() < 0)
        //{
        //    m_acceleration.setY(-10 /*- Camera::cameraY*/);
        //    m_velocity.setX(0);
        //}
        //else
        //{
        //    m_acceleration.setY(-10 /*- Camera::cameraY*/);
        //    m_acceleration.setX(x * 5 /*- Camera::cameraX*/);
        //}
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