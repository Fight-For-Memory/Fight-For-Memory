#include "Game.h"

Keyboard kbd;
Mouse mouse;
SDL_Event e;
bool run = true;

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
        throw ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    Music::Init();
    TTF_Init();
    Game game(kbd, mouse);

    while (run)
    {
        kbd.Update();
        mouse.Update();
        while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) run = true; }
        game.Update();
        game.Draw();
    }
    
    return 0;
}