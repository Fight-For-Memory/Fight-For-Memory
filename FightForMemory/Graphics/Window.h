#pragma once
#include <SDL.h>
#include "Renderer.h"

class Window
{
public:
	Window(int width, int height);
	~Window();
	//Screen dimension constants
	const int width;
	const int height;

	Renderer** GetRenderer();

private:
	SDL_Window* window;
	Renderer* renderer;

	friend class Renderer;
};