#include "Game.h"

Keyboard kbd;
Mouse mouse;
SDL_Event e;
bool run = true;
Game* game;
Music music;
Window* window = new Window();

void Init();
void Quit();

int main(int argc, char* args[])
{
    Init();

    while (run)
    {
        kbd.Update();
        mouse.Update();
        while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) run = true; }
        game->Update();
        game->Draw();
    }
    
    Quit();

    return 0;
}

void Init()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
        throw ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    Music::Init();
    TTF_Init();
    game = new Game(&window, kbd, mouse, music);
}

void Quit()
{
    music.Stop();
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();
    Mix_CloseAudio();
}