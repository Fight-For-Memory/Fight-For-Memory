#pragma once
#include <SDL.h>

class Mouse
{
public:
	bool LeftIsPressed() const;
	bool RightIsPressed() const;
	bool MiddleIsPressed() const;
	void Update();
	int GetPosX() const;
	int GetPosY() const;
private:
	int x;
	int y;
	Uint32 mouse = SDL_GetMouseState(&x, &y);
};
