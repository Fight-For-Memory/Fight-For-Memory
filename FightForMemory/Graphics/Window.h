#pragma once
#include <SDL.h>
#include "Renderer.h"

class Window
{
public:
	Window(int width, int height);
	~Window();

	Renderer** GetRenderer();

	void Resize(int width, int height);

private:
	SDL_Window* window;
	Renderer* renderer;

	int width;
	int height;

	friend class Renderer;
};