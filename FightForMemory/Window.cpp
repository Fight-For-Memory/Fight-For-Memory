#include "Window.h"

Window::Window()
{
    //Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) throw("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    
}
