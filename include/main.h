#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <conio.h>
#include <map>
const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

int SCREEN_HEIGHT = 500;
int SCREEN_WIDTH = 680;
int LEVEL_WIDTH = 1160;
int LEVEL_HEIGHT = 10000;
