#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
private:
    //int m_speed;
    //int m_length;

    //몬스터1 이동을 위한 변수들
    int mob1_x = 10, mob1_y = 9910;
    int mob1_move_x = 1;
    bool mob1_current = false;
    bool mob1_collid = false;

protected:
    int mob1_move = 10;
    int mob2_move = 5;
    int speed = 5;

public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    //void update(int speed,int length);
    void update();
    void clean() {};

    //Monster(int speed, int length) {
    //    m_speed = speed;
    //    m_length = length;
    //};
};