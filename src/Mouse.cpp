#include "Mouse.h"
#include "InputHandler.h"
Mouse::Mouse(const LoaderParams* pParams) : SDLGameObject(pParams) {}
void Mouse::handleInput()
{ //420, 370 -> 210, 185
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	m_velocity = (*vec - Vector2D(150,132) - m_position);
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