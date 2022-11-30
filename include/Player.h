#pragma once
#include "SDLGameObject.h"

#define SCREEN_WIDTH 1000 //보이는 화면 넓이
#define SCREEN_HEIGHT 500
#define LEVEL_WIDTH 1920 //전체 화면 넓이
#define LEVEL_HEIGHT 1080

class Player : public SDLGameObject
{
private:
    bool currentJump = false;
    int m_JumpSpeed = -50;
    int x = -1; //왼쪽인지 오른쪽인지 구분, 
                //1 = 오른쪽, -1 = 왼쪽
    int cameraX = (m_position.getX() + 100 / 2) - SCREEN_WIDTH / 2;
    int cameraY = (m_position.getY() + 91 / 2) - SCREEN_HEIGHT / 2;

public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();
    void jump();
    void cameraMove();
};