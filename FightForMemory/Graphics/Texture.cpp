#include "Texture.h"


Texture::Texture(const char* filename, Renderer& renderer, FileType type, Uint32 key)
	:
	renderer(renderer)
{
	if (type == FileType::bitmap) image = SDL_LoadBMP(filename);
	else image = IMG_Load(filename);
	SDL_SetColorKey(image, SDL_TRUE, key);
	tex = SDL_CreateTextureFromSurface(renderer.sdl_renderer, image);
	if (tex == NULL) throw SDL_GetError();
}

Texture::~Texture()
{
	SDL_FreeSurface(image);
	SDL_DestroyTexture(tex);
}

void Texture::Draw(SDL_Rect* position ) const
{
	SDL_RenderCopy(renderer.sdl_renderer, tex, NULL, position);
}

void Texture::Draw(SDL_Rect* position, SDL_Rect* clip) const
{
	SDL_RenderCopy(renderer.sdl_renderer, tex, clip, position);
}
