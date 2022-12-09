#include "Mouse.h"
#include "InputHandler.h"
Mouse::Mouse(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Mouse::handleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	m_velocity = (*vec - m_position);
}
void Mouse::draw()
{
	SDLGameObject::draw();
}
void Mouse::update()
{
	handleInput();
	
	SDLGameObject::update();
}
void Mouse::clean()
{

}