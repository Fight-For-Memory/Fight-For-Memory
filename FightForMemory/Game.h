#pragma once
#include <SDL.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include "Window.h"
#include "Renderer.h"
#include "Texture.h"
#include "Sound.h"
#include "Music.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Font.h"
#include "Sprite.h"

class Game
{
public:
	Game(Keyboard& kbd, Mouse& mouse, Music& music);
    ~Game();
    void Update();
    void Draw();
private:
    Window window = Window();
    Renderer rend = Renderer(window);
    SDL_Rect rect1 = { 175,150,100,200 };
    SDL_Rect rect2 = { 375,150,100,200 };
    SDL_Rect rect3 = { 475,150,100,200 };
    Texture texture1 = Texture("Resources/Images/test.bmp", rend);
    Texture texture2 = Texture("Resources/Images/zdj.jpg", rend, FileType::png);
    Keyboard& kbd;
    Mouse& mouse;
    Music& music;
    Sound PlayerSounds = Sound(1, "Resources/Sounds");
    Font text1 = Font("Witaj Cyprian :)", rend, { 175, 0, 300, 50 }, { 255,100,100 });
    Font text2 = Font("Witaj Hubert  :)", rend, { 175, 75, 300, 50 }, { 100,255,100 });
    Sprite link = Sprite("Resources/Images/link90x90.bmp", rend);
    bool run = true;
};