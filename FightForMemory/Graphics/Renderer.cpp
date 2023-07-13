#include "Renderer.h"

Renderer::Renderer(Window& window)
{
	sdl_renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(sdl_renderer);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(sdl_renderer);
}

void Renderer::DrawRect(SDL_Rect* rect, Color color)
{
	SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(sdl_renderer, rect);
}

void Renderer::Update()
{
	SDL_RenderPresent(sdl_renderer);
	Clear();
}

void Renderer::SetOriginRectColor()
{
	SDL_SetRenderDrawColor(sdl_renderer, BackgroundColor.r, BackgroundColor.g, BackgroundColor.b, BackgroundColor.a);
}

void Renderer::Clear()
{
	SetOriginRectColor();
	SDL_RenderClear(sdl_renderer);
}
