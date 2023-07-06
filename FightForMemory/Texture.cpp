#include "Texture.h"

Texture::Texture( const char* filename, Renderer& renderer)
	:
	renderer(renderer)
{
	image = SDL_LoadBMP(filename);

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
