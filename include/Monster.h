#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
protected:
    int mob1_move = 10;
    int mob2_move = 5;

public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    //void update1();
    //void update2();
    void update(int speed,int length);
    void clean() {};
};