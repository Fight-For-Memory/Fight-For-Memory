#pragma once
#include <SDL.h>
#include "Renderer.h"

class Window
{
public:
	Window();
	~Window();
	//Screen dimension constants
	static constexpr int SCREEN_WIDTH = 640;
	static constexpr int SCREEN_HEIGHT = 480;

	Renderer** GetRenderer();

private:
	SDL_Window* window;
	Renderer* renderer;

	friend class Renderer;
};