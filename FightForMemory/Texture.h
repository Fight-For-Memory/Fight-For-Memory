#pragma once
#include <SDL.h>
#include "Renderer.h"
class Texture
{
public:
	Texture(const char* filename, Renderer& renderer);
	~Texture();
	Texture(const Texture& src) = delete;
	Texture& operator=(const Texture& src) = delete;
	void Draw(SDL_Rect* position) const;
private:
	Renderer& renderer;
	SDL_Surface* image;
	SDL_Texture* tex = NULL;
};
