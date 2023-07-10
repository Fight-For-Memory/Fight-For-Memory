#include "Mouse.h"

bool Mouse::LeftIsPressed() const
{
	return mouse & SDL_BUTTON(SDL_BUTTON_LEFT);
}

bool Mouse::RightIsPressed() const
{
	return mouse & SDL_BUTTON(SDL_BUTTON_RIGHT);
}

bool Mouse::MiddleIsPressed() const
{
	return mouse & SDL_BUTTON(SDL_BUTTON_MIDDLE);
}

void Mouse::Update()
{
	SDL_PumpEvents();
	mouse = SDL_GetMouseState(&x, &y);
}

int Mouse::GetPosX() const
{
	return x;
}

int Mouse::GetPosY() const
{
	return y;
}
