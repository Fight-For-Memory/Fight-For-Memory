#include "Sprite.h"

Sprite::Sprite(const char* filename, Renderer& renderer)
	:
	rend(renderer),
	tex(filename, renderer, FileType::bitmap, Colors::Magenta)
{}

void Sprite::DrawSprite()
{
	SDL_Rect position = { 100,100,100,100 };
	SDL_Rect clip = { 0, 0, 100, 100 };
	tex.Draw(&position, &clip);
}
