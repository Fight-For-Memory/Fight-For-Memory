#include "Font.h"

Font::Font(const char* font_style, int font_size)
	:
	font(TTF_OpenFont(font_style, font_size))
{
	if (font == NULL) throw TTF_GetError();
}

Font::~Font()
{
	TTF_CloseFont(font);
}
