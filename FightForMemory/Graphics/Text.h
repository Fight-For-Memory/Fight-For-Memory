#pragma once

#include "Font.h"

class Text
{
public:
	Text(const char* text, Font * font, Renderer** renderer, SDL_Rect rect, SDL_Color color);
	~Text();
	void DisplayText();
	void HideText(SDL_Color backGround);
	void Reload();
private:
	Font* font;
	SDL_Rect rect;
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	SDL_Color color;
	Renderer** renderer;
	const char* text;
};



