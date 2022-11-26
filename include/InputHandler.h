#pragma once
#include <SDL2/SDL.h> 
// #include "Vector2D.h"
#include <vector>
class Vector2D;
 
enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};
class InputHandler {
public:
    ~InputHandler() {}
    static InputHandler* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    bool isKeyDown(SDL_Scancode key);
    void update();
    void clean() {}
    bool isKeyOneDown(SDL_Scancode key);

    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();
    Vector2D* m_mousePosition;

    void onMouseMove(SDL_Event event);
    void onMouseButtonDown(SDL_Event event);
    void onMouseButtonUp(SDL_Event event);
    void onKeyDown();
    void onKeyUp();
    const Uint8* m_keystates;

private:
    static InputHandler* s_pInstance;
    std::vector<bool> m_mouseButtonStates;

    InputHandler();
};
typedef InputHandler TheInputHandler;
