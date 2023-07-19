#include "Font.h"

Font::Font(const char* font_style, int font_size)
	:
	font(TTF_OpenFont(font_style, font_size)),
	font_style(font_style),
	font_size(font_size)
{
	if (font == NULL) throw TTF_GetError();
}

Font::~Font()
{
	TTF_CloseFont(font);
}

void Font::Reload()
{
	TTF_CloseFont(font);
	font = TTF_OpenFont(font_style, font_size);
	if (font == NULL) throw TTF_GetError();
}
