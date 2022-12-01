#include "Camera.h"
#include "Player.h"

float Camera::cameraX;
float Camera::cameraY;
Camera::Camera(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Camera::update()
{
   //std::cout << "Camera X : " << cameraX << std::endl;

   cameraX = (Player::player_X + 100 / 2) - SCREEN_WIDTH / 2;
   cameraY = (Player::player_Y + 91 / 2) - SCREEN_HEIGHT / 2;

   if (cameraX < 0) //���� ��
   {
       cameraX = 0;
   }
   if (cameraY < 0) //��� ��
   {
       cameraY = 0;
   }
   if (cameraX > LEVEL_WIDTH - SCREEN_WIDTH) //������ ��
   {
       cameraX = LEVEL_WIDTH - SCREEN_WIDTH; //160
   }
   if (cameraY > LEVEL_HEIGHT - SCREEN_HEIGHT) //�ϴ� ��
   {
       cameraY = LEVEL_HEIGHT - SCREEN_HEIGHT; //9200
   }
}