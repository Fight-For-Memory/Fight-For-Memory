#pragma once
#include <SDL_ttf.h>
#include "Renderer.h"
class Font
{
public:
	Font(const char* text, Renderer& renderer, SDL_Rect rect, SDL_Color color);
	~Font();
	void Draw();
	void DisplayText();
	void HideText();
private:
	const char* font_style;
	int font_sharpness;
	bool isVisible = false;
	Renderer& renderer;
	SDL_Surface* surfaceMessage; 
	SDL_Texture* Message;
	TTF_Font* font;
	SDL_Rect rect;
};
