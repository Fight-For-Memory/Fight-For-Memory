#pragma once
#include <SDL_ttf.h>
#include "Renderer.h"
class Font
{
public:
	Font(const char* text, const char* font_style, int font_size, Renderer& renderer, SDL_Rect rect, SDL_Color color);
	~Font();
	void DisplayText();
	void HideText(SDL_Color backGround);
private:
	Renderer& renderer;
	SDL_Surface* surfaceMessage; 
	SDL_Texture* Message;
	TTF_Font* font;
	SDL_Rect rect;
};
