#include "Sprite.h"

Sprite::Sprite(const char* filename, Renderer& renderer)
	:
	rend(renderer),
	tex(filename, renderer, FileType::bitmap, Colors::Magenta)
{}

void Sprite::DrawSprite(SDL_Rect* position, SDL_Rect* clip)
{
	tex.Draw(position, clip);
}
