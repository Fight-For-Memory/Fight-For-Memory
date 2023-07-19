#pragma once
#include <SDL_ttf.h>
#include "Renderer.h"
class Font
{
public:
	Font(const char* font_style, int font_size);
	~Font();
	void Reload();
private:
	TTF_Font* font;
	const char* font_style;
	int font_size;
	friend class Text;
};
