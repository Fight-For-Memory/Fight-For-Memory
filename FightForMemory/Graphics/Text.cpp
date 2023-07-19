#include "Text.h"

Text::Text(const char* text, Font* font, Renderer** renderer, SDL_Rect rect, SDL_Color color)
	:
	font(font),
	rect(rect),
	color(color),
	renderer(renderer),
	text(text)
{
	surfaceMessage = TTF_RenderText_Solid(font->font, text, color);
	Message = SDL_CreateTextureFromSurface((*renderer)->sdl_renderer, surfaceMessage);
}

Text::~Text()
{
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	delete [] text;
}

void Text::DisplayText()
{
	SDL_RenderCopy((*renderer)->sdl_renderer, Message, NULL, &rect);
}

void Text::HideText(SDL_Color backGround)
{
	SDL_SetRenderDrawColor((*renderer)->sdl_renderer, backGround.r, backGround.g, backGround.b, backGround.a);
	SDL_RenderFillRect((*renderer)->sdl_renderer, &rect);
}

void Text::Reload()
{
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	surfaceMessage = TTF_RenderText_Solid(font->font, text, color);
	Message = SDL_CreateTextureFromSurface((*renderer)->sdl_renderer, surfaceMessage);
}


