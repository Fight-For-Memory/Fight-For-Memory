#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Renderer.h"
#include "Texture.h"

int main(int argc, char* args[])
{
    //The window we'll be rendering to
    Window window;
    Renderer rend(window);
    SDL_Rect rect = { 275,150,100,200 };
    Texture texture("test.bmp", rend);
    texture.Draw(&rect);
    rend.Update();
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
        throw ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    
    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}