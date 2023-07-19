#pragma once
#include <SDL.h>
#include "Renderer.h"
#include "Texture.h"

class Sprite
{
public:
	Sprite(const char* filename, Renderer& renderer);
	void DrawSprite();
private:
	Texture tex;
	Renderer& rend;
};
