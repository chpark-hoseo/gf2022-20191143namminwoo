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
	SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 
}
void Player::handleInput()
{

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_currentFrame = ((SDL_GetTicks() / 100) % 5); //Ű�Է� ���߿��� ������ ������
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