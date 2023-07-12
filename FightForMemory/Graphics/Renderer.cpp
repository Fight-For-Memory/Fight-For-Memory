#include "Renderer.h"

Renderer::Renderer(Window& window)
{
	sdl_renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RenderClear(sdl_renderer);
	SDL_SetRenderDrawColor(sdl_renderer, DrawColor.r, DrawColor.g, DrawColor.b , DrawColor.a);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(sdl_renderer);
}

void Renderer::DrawRect(SDL_Rect* rect)
{
	SDL_RenderDrawRect(sdl_renderer, rect);
}

void Renderer::Update()
{
	SDL_RenderPresent(sdl_renderer);
}

void Renderer::SetDrawColor(Color Color)
{
	DrawColor = Color;
	SDL_SetRenderDrawColor(sdl_renderer, DrawColor.r, DrawColor.g, DrawColor.b, DrawColor.a);
}
