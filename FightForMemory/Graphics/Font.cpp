#include "Font.h"

Font::Font(const char* text, Renderer& renderer, SDL_Rect rect, SDL_Color color)
	:
	renderer(renderer),
	rect(rect),
	font_style("Resources/Fonts/Arial.ttf"),
	font_sharpness(35),
	font(TTF_OpenFont(font_style, font_sharpness))
{
	if (TTF_Init() == -1) throw TTF_GetError();
	if (font == NULL) throw TTF_GetError();
	surfaceMessage = TTF_RenderText_Solid(font, text, color);
	Message	= SDL_CreateTextureFromSurface( renderer.sdl_renderer , surfaceMessage);
}

Font::~Font()
{
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(font);
}

void Font::Draw()
{
	if (isVisible) SDL_RenderCopy(renderer.sdl_renderer, Message, NULL, &rect);
}

void Font::DisplayText()
{
	isVisible = true;
}

void Font::HideText()
{
	isVisible = false;
}
