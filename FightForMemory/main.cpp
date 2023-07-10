#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Renderer.h"
#include "Texture.h"
#include "Sound.h"
#include <SDL_mixer.h>

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    //The window we'll be rendering to
    Window window;
    Renderer rend(window);
    SDL_Rect rect1 = { 175,150,100,200 };
    SDL_Rect rect2 = { 375,150,100,200 };
    Texture texture1("Resources/test.bmp", rend, FileType::bitmap);
    Texture texture2("Resources/zdj.jpg", rend, FileType::png);
    Sound PlayerSounds(1,"Resources/Sounds");

    texture1.Draw(&rect1);
    texture2.Draw(&rect2);

    PlayerSounds.Play("zombie");
    
    rend.Update();
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
        throw ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    
    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();
    Mix_CloseAudio();

    return 0;
}