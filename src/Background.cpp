#include "Background.h"
#include "Camera.h"
#include "InputHandler.h"
#include "Player.h"
Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Background::draw()
{
	SDLGameObject::draw();
}
void Background::update()
{
	m_velocity.setX(0);
	//m_velocity.setY(0);
	handleInput();
	SDLGameObject::update();
}
void Background::handleInput()
{
	//m_velocity.setX(Camera::cameraX / 32);
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		if (Player::player_X >= 660)
		{
			m_velocity.setX(0);
		}
		else
		{
			m_velocity.setX(-1);
		}
		
		//if (Camera::cameraX >= 160)
		//{
		//	m_velocity.setX(0);
		//}
		//else
		//{
		//	m_velocity.setX(-Camera::cameraX / 32);
		//}
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{		
		if (Player::player_X <= 500)
		{
			m_velocity.setX(0);
		}
		else
		{
			m_velocity.setX(1);
		}
		
		//if (Camera::cameraX <= 0)
		//{
		//	m_velocity.setX(0);
		//}
		//else
		//{
		//	m_velocity.setX(Camera::cameraX / 32);
		//}
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