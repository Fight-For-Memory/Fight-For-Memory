#pragma once
#include <SDL.h>
#include "Window.h"

class Renderer
{
public: 
	Renderer(Window& window);
	~Renderer();
	void DrawRect(SDL_Rect* rect);
	void Update();
private:
	SDL_Renderer* renderer;
};