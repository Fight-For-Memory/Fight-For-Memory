#pragma once
#include <SDL_ttf.h>
#include "Renderer.h"
class Font
{
public:
	Font(const char* font_style, int font_size);
	~Font();
	
private:
	Renderer** renderer;
	TTF_Font* font;

	friend class Text;
};
