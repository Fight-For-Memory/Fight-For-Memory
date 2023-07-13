#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Renderer.h"

enum class FileType 
{
	bitmap,
	png
};

class Texture
{
public:
	Texture(const char* filename, Renderer& renderer, FileType type = FileType::bitmap);
	~Texture();
	Texture(const Texture& src) = delete;
	Texture& operator=(const Texture& src) = delete;
	void Draw(SDL_Rect* position) const;
private:
	Renderer& renderer;
	SDL_Surface* image;
	SDL_Texture* tex = NULL;
};

