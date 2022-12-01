#include "Background.h"
#include "Camera.h"
#include "InputHandler.h"
Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Background::draw()
{
	SDLGameObject::draw();
}
void Background::update()
{
	std::cout << "BG X : " << m_position.getX() << " BG Y : " << m_position.getY() << std::endl; //-160
	m_velocity.setX(0);
	//m_velocity.setY(0);
	handleInput();
	SDLGameObject::update();
}
void Background::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(-Camera::cameraX);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(Camera::cameraX);
	}
	//else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	//{
	//	m_velocity.setY();
	//}
	//else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	//{
	//	m_velocity.setY();
	//}
}
void Background::clean() {}