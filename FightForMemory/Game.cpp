#include "Game.h"

Game::Game(Window** window, Renderer** rend, Keyboard& kbd, Mouse& mouse, Music& music)
    :
    kbd(kbd),
    mouse(mouse),
    music(music),
    window(window),
    rend(rend)
{
    music.Play("Resources/Music/gravity_turn_action.mp3", 75);
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
        text1.HideText({ 0,0,0,255 });
    if (kbd.IsKeyDown(SDL_SCANCODE_1))
        text2.HideText({ 255,0,0,255 });
    if (kbd.IsKeyDown(SDL_SCANCODE_2))
        text1.DisplayText();
    if (kbd.IsKeyDown(SDL_SCANCODE_3))
        text2.DisplayText();

   
   
    
}

void Game::Draw()
{
    texture1.Draw(&rect1);
    texture2.Draw(&rect2);
    texture1.Draw(&rect1);
    texture2.Draw(&rect2);
    (*rend)->Update();
}
