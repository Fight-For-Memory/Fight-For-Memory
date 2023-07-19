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
	Texture(const char* filename, Renderer& renderer, FileType type = FileType::bitmap, Uint32 key = NULL);
	~Texture();
	Texture(const Texture& src) = delete;
	Texture& operator=(const Texture& src) = delete;
	void Draw(SDL_Rect* position) const;
	void Draw(SDL_Rect* position, SDL_Rect* clip) const;
	
private:
	Renderer& renderer;
	SDL_Surface* image;
	SDL_Texture* tex = NULL;

	friend class Sprite;
};

