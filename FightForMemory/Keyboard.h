#pragma once
#include <SDL.h>

class Keyboard
{
public:
	bool IsKeyDown(SDL_Scancode key);
	bool IsKeyUp(SDL_Scancode key);
	void Update();
private:
	const Uint8* currentKeyState = SDL_GetKeyboardState(NULL);
};