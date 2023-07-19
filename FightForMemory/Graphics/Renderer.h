#pragma once
#include <SDL.h>
#include "Window.h"
#include "Color.h"

class Renderer
{
public: 
	Renderer(Window& window);
	~Renderer();
	void DrawRect(SDL_Rect* rect, SDL_Color color);
	void Update();
	void SetOriginRectColor();
	void Clear();
private:
	SDL_Renderer* sdl_renderer;
	SDL_Color BackgroundColor = {0,0,0};
	friend class Texture;
	friend class Font;
};