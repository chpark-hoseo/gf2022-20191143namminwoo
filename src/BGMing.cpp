//#include "BGMing.h"
//#include "InputHandler.h"
//#include "Game.h"
//
//BGMing::BGMing(const LoaderParams* pParams) : SDLGameObject(pParams) {}
//void BGMing::update()
//{
//	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
//	if (Game::gamePlay == 1)
//	{
//		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
//		{
//			// chunk�� ��� ���� ���, -1�� ���� ����� ä��, 0�� �ݺ� Ƚ��
//			Mix_PlayChannel(-1, g_pChunk, 0);
//		}
//	}
//
//	SDLGameObject::update();
//}