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
#include "Resources/Assets.h"

class Game
{
public:
	Game(Window** window, Keyboard& kbd, Mouse& mouse, Music& music);
    ~Game();
    void Update();
    void Draw();
    void Resize(int width, int height);
private:
    Window** window;
    Renderer** rend;
    Assets* assets;
    SDL_Rect rect1 = { 175,150,100,200 };
    SDL_Rect rect2 = { 375,150,100,200 };
    Keyboard& kbd;
    Mouse& mouse;
    Music& music;

    bool run = true;
};