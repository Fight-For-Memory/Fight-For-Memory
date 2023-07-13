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

class Game
{
public:
	Game(Keyboard& kbd, Mouse& mouse);
    ~Game();
    void Update();
    void Draw();
private:
    Window window = Window();
    Renderer rend = Renderer(window);
    SDL_Rect rect1 = { 175,150,100,200 };
    SDL_Rect rect2 = { 375,150,100,200 };
    Texture texture1 = Texture("Resources/test.bmp", rend);
    Texture texture2 = Texture("Resources/zdj.jpg", rend, FileType::png);
    Keyboard& kbd;
    Mouse& mouse;
    Sound PlayerSounds = Sound(1, "Resources/Sounds");
    Font text1 = Font("Witaj Cyprian :)", "Resources/Arial.ttf", 35, rend, { 175, 0, 300, 50 }, { 255,100,100 });
    Font text2 = Font("Witaj Hubert  :)", "Resources/Arial.ttf", 35, rend, { 175, 75, 300, 50 }, { 100,255,100 });
    bool run = true;
};