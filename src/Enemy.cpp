#include "Enemy.h"
#include "InputHandler.h"
#include "Game.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::handleInput()
{	
	//if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
	//	printf("shoot \n");
	//}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	//юс╫ц
	if (vec->getX() >= 10 && vec->getX() <= 157 && vec->getY() >= 100 && vec->getY() <= 254)
	{ 
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			Game::gamePlay = 2;
		}
	}
	//m_velocity = (*vec - m_position) / 100;
}
void Enemy::draw()
{

	SDLGameObject::draw();

}
void Enemy::update()
{
	handleInput();
	m_currentFrame = ((SDL_GetTicks() / 100) % 5);

	SDLGameObject::update();
}
void Enemy::clean() {}
