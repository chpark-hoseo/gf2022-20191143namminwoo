#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
    //if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    //    SDLGameObject::draw();
    //}
    //if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    //    SDLGameObject::draw();
    //}
    SDLGameObject::draw();
}

void Player::update()
{
	handleInput();
	m_velocity.setX(0);
    m_velocity.setY(0);
	SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
}
void Player::handleInput()
{

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5); //키입력 도중에만 프레임 나오게
        m_velocity.setX(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        m_velocity.setX(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        m_velocity.setY(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5);
        m_velocity.setY(2);
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
//void Player::load(int x, int y, int width, int height, std::string textureID)
//{
//    GameObject::load(x, y, width, height, textureID);
//}
//
//void Player::draw(SDL_Renderer* pRenderer)
//{
//    GameObject::draw(pRenderer);
//}
//
//void Player::update()
//{
//    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
//
//    m_x -= 1;
//}