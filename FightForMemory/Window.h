#pragma once
#include <SDL.h>

class Window
{
public:
	Window();
	//Screen dimension constants
	static constexpr int SCREEN_WIDTH = 640;
	static constexpr int SCREEN_HEIGHT = 480;
private:
	SDL_Window* window;
};