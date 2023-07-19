#pragma once
#include <vector>
#include "Sprite.h"
#include "mouse.h"

class Animation
{
public:
	Animation(int x, int y, int width, int height, int count, float holdTime, Sprite& sprite);
	void Update(float dt);
	void Draw(int x, int y);
	void Advance();
private:
	Sprite& sprite;
	std::vector<SDL_Rect> frames;
	int iCurFrame = 0;
	float holdTime;
	float curFrameTime = 0.0f;
};
