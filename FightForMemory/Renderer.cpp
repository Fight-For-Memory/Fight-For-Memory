#include "Renderer.h"

Renderer::Renderer(Window& window)
{
	renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 100, 10, 100);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

void Renderer::DrawRect(SDL_Rect* rect)
{
	SDL_RenderDrawRect(renderer, rect);
}

void Renderer::Update()
{
	SDL_RenderPresent(renderer);
}
