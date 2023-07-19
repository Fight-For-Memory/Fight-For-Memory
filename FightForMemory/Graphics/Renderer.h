#pragma once
#include <SDL.h>
#include "Color.h"

class Renderer
{
public: 
	Renderer(SDL_Window* window);
	~Renderer();
	void DrawRect(SDL_Rect* rect);
	void Update();
private:
	void SetDrawColor(Color Color);
	SDL_Renderer* sdl_renderer;
	Color DrawColor = {0,0,0};

	friend class Texture;
	friend class Font;
	friend class Text;
};