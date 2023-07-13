#include "GameObjects.h"

void Init()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
        throw ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    Music::Init();
    TTF_Init();
    game = new Game(window, rend, kbd, mouse, music, settings);
}

void Quit()
{
    music.Stop();
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();
    Mix_CloseAudio();
}