#include "Window.h"

Window::Window(int width, int height)
    :
    width(width),
    height(height)
{
    //Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) throw("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    renderer = new Renderer(window);    
}

Window::~Window()
{
    delete renderer;
    SDL_DestroyWindow(window);
}

Renderer** Window::GetRenderer()
{
    return &renderer;
}

void Window::Resize(int width, int height)
{
    delete renderer;
    SDL_DestroyWindow(window);
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) throw("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    renderer = new Renderer(window);
    
}
