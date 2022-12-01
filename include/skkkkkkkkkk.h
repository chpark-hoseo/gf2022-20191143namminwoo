#pragma once

if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
{
    m_velocity.setX(-5);
    p_x -= 5;
    if ((p_x < 0)) {
        m_velocity.setX(5);
        p_x += 5;
    }
}
if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
{
    m_velocity.setX(5);
    p_x += 5;
    if ((p_x + 100 / 2 > LEVEL_WIDTH)) {
        m_velocity.setX(-5);
        p_x -= 5;
    }
}

cameraX = (p_x + 100 / 2) - SCREEN_WIDTH / 2;

//Keep the camera in bounds
if (cameraX < 0)
{
    cameraX = 0;
}
if (cameraX > LEVEL_WIDTH - SCREEN_WIDTH)
{
    cameraX = LEVEL_WIDTH - SCREEN_WIDTH;
}
if (cameraY > LEVEL_HEIGHT - SCREEN_HEIGHT)

clipDrawImage(BG, 0, 0, cameraX, cameraY, SCREEN_WIDTH, SCREEN_HEIGHT);
multDrawImage(test, PlayerX - cameraX, PlayerY - cameraY, 0.5, 0.5);
