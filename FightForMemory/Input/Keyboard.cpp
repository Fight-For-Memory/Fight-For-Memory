#include "Keyboard.h"

bool Keyboard::IsKeyDown(SDL_Scancode key)
{
	return currentKeyState[key];
}

bool Keyboard::IsKeyUp(SDL_Scancode key)
{
	return !currentKeyState[key];
}

void Keyboard::Update()
{ 
   SDL_PumpEvents();
}
