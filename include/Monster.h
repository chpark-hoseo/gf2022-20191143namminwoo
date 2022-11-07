#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
private:
    int m_speed;
    int m_length;

protected:
    int mob1_move = 10;
    int mob2_move = 5;
    int speed = 5;

public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    //void update1();
    //void update2();
    //void update(int speed,int length);
    void update();
    void clean() {};

    Monster(int speed, int length) {
        m_speed = speed;
        m_length = length;
    };
};