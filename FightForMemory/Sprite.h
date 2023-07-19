#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Texture.h"

class Sprite
{
public:
	Sprite(const char* filename, Renderer& renderer);
	void DrawSprite(SDL_Rect* position, SDL_Rect* clip);
private:
	Texture tex;
	Renderer& rend;
};
