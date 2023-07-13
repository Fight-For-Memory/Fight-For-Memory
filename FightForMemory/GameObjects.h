#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Texture.h"
#include "Sound.h"
#include "Music.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Font.h"
#include "Settings.h"
#include "Game.h"

Keyboard kbd;
Mouse mouse;
SDL_Event e;
Game* game;
Music music;
Window* window = new Window();
Renderer rend = Renderer(*window);
Settings settings;

bool run = true;

void Init();
void Quit();