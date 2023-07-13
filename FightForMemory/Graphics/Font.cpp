#include "Font.h"

Font::Font(const char* text, const char* font_style, int font_size, Renderer** renderer, SDL_Rect rect, SDL_Color color)
	:
	renderer(renderer),
	rect(rect),
	font(TTF_OpenFont(font_style, font_size))
{
	if (TTF_Init() == -1) throw TTF_GetError();
	if (font == NULL) throw TTF_GetError();
	surfaceMessage = TTF_RenderText_Solid(font, text, color);
	Message	= SDL_CreateTextureFromSurface( (*renderer)->sdl_renderer , surfaceMessage);
}

Font::~Font()
{
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(font);
	TTF_Quit();
}

void Font::DisplayText()
{
	SDL_RenderCopy((*renderer)->sdl_renderer, Message, NULL, &rect);
}

void Font::HideText(SDL_Color backGround)
{
	SDL_SetRenderDrawColor((*renderer)->sdl_renderer, backGround.r, backGround.g, backGround.b, backGround.a);
	SDL_RenderFillRect((*renderer)->sdl_renderer, &rect);
}
