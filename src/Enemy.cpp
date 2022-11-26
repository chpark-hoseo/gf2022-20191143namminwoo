#include "Enemy.h"
#include "InputHandler.h"
Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::handleInput()
{
	//if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
	//	printf("shoot \n");
	//}
	//Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 100;
}
void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::update()
{
	m_x -= 10;
	handleInput();
	m_currentFrame = ((SDL_GetTicks() / 100) % 5);
	SDLGameObject::update();
}
void Enemy::clean() {}
