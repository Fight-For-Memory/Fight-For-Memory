#include "Game.h"

Game::Game(Keyboard& kbd, Mouse& mouse, Music& music)
    :
    kbd(kbd),
    mouse(mouse),
    music(music)
{
    music.Play("Resources/Music/gravity_turn_action.mp3", 75);

    for (int i = 0; i < 4; i++)
    {
        animations.emplace_back(Animation(90, 90 * i, 90, 90, 4, 10000.f, link));
    }
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
    if(kbd.IsKeyDown(SDL_SCANCODE_1))
        text1.DisplayText();
    if (kbd.IsKeyDown(SDL_SCANCODE_2))
        text2.DisplayText();
    if (kbd.IsKeyDown(SDL_SCANCODE_3))
        text1.HideText();
    if (kbd.IsKeyDown(SDL_SCANCODE_4))
        text2.HideText();
    if (kbd.IsKeyDown(SDL_SCANCODE_5))
        rend.SetOriginRectColor();
    if (kbd.IsKeyDown(SDL_SCANCODE_6))
        animations[0].Draw(mouse.GetPosX(), mouse.GetPosY());
    if (kbd.IsKeyDown(SDL_SCANCODE_7))
        animations[1].Draw(mouse.GetPosX(), mouse.GetPosY());
}

void Game::Draw()
{
    texture1.Draw(&rect1);
    texture2.Draw(&rect2);
    texture1.Draw(&rect1);
    texture2.Draw(&rect2);
    text1.Draw();
    text2.Draw();
    rend.DrawRect(&rect3, {0,0,255});
    rend.Update();
}
