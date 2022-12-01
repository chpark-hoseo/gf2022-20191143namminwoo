#include "Camera.h"

float Camera::cameraX;
float Camera::cameraY;
Camera::Camera(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Camera::update()
{
    cameraX = (m_position.getX() + 100 / 2) - SCREEN_WIDTH / 2;
    cameraY = (m_position.getY() + 91 / 2) - SCREEN_HEIGHT / 2;

    if (cameraX < 0)
    {
        cameraX = 0;
    }
    if (cameraY < 0)
    {
        cameraY = 0;
    }
    if (cameraX > LEVEL_WIDTH - SCREEN_WIDTH)
    {
        cameraX = LEVEL_WIDTH - SCREEN_WIDTH;
    }
    if (cameraY > LEVEL_HEIGHT - SCREEN_HEIGHT)
    {
        cameraY = LEVEL_HEIGHT - SCREEN_HEIGHT;
    }
}