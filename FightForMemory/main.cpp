#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Renderer.h"
#include "Texture.h"
#include "Sound.h"
#include "Keyboard.h"

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_AUDIO);
    //The window we'll be rendering to
    Window window;
    Renderer rend(window);
    SDL_Rect rect1 = { 175,150,100,200 };
    SDL_Rect rect2 = { 375,150,100,200 };
    Texture texture1("Resources/test.bmp", rend, FileType::bitmap);
    Texture texture2("Resources/zdj.jpg", rend, FileType::png);
    Sound sample1("Resources/magic-space.wav");
    Keyboard kbd;

    texture1.Draw(&rect1);
    texture2.Draw(&rect2);
    
    sample1.Play();
    SDL_Delay(2000);
    sample1.Pause();

    while (true)
    {
        kbd.Update();
        if (kbd.IsKeyDown(SDL_SCANCODE_ESCAPE))
        {
           printf("%s", "key is down");
           break;
        }
    }
    
    while (true)
    {
        kbd.Update();
        if (kbd.IsKeyUp(SDL_SCANCODE_ESCAPE))
        {
            printf("%s", "key is up");
            break;
        }
    } 
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