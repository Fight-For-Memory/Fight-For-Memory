#include "Game.h"

Game::Game(Window** window, Keyboard& kbd, Mouse& mouse, Music& music)
    :
    kbd(kbd),
    mouse(mouse),
    music(music),
    window(window),
    rend((*window)->GetRenderer())
{
    music.Play("Resources/Music/gravity_turn_action.mp3", 75);
    assets = new Assets(rend);
}

Game::~Game()
{
   
}

void Game::Update()
{
    if (kbd.IsKeyDown(SDL_SCANCODE_ESCAPE)) 
        SDL_Quit();
    if (mouse.LeftIsPressed())
        printf("%s %d\n%s %d", "mouse xPos:", mouse.GetPosX(), "mouse yPos:", mouse.GetPosY());
    if (mouse.RightIsPressed())
        printf("%s \n", "right is pressed");
    if (mouse.MiddleIsPressed())
        printf("%s \n", "middle is pressed");
    if(kbd.IsKeyDown(SDL_SCANCODE_0))
        assets->Cyprian->HideText({ 0,0,0,255 });
    if (kbd.IsKeyDown(SDL_SCANCODE_1))
        assets->Hubert->HideText({ 255,0,0,255 });
    if (kbd.IsKeyDown(SDL_SCANCODE_2))
        assets->Cyprian->DisplayText();
    if (kbd.IsKeyDown(SDL_SCANCODE_3))
        assets->Hubert->DisplayText();
    if (kbd.IsKeyDown(SDL_SCANCODE_A))
    {
        Resize(1000, 500);
        printf("%s \n", "Resize A");
    }
    if (kbd.IsKeyDown(SDL_SCANCODE_B))
    {
        Resize(640, 480);
        printf("%s \n", "Resize B");
    }
}

void Game::Draw()
{
    assets->GetTexture("test").Draw(&rect1);
    assets->GetTexture("zdj").Draw(&rect2);
    (*rend)->Update();
}

void Game::Resize(int width, int height)
{
    (*window)->Resize(width, height);
    delete assets;
    assets = new Assets(rend);
}
