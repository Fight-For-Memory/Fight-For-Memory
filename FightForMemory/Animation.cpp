#include "Animation.h"

Animation::Animation(int x, int y, int width, int height, int count, float holdTime, Sprite& sprite)
	:
	sprite(sprite),
	holdTime(holdTime)
{
	for (int i = 0; i < count; i++)
		frames.emplace_back(SDL_Rect{ x + i * width, y, width, height });
}

void Animation::Update(float dt)
{
	curFrameTime += dt;
	while (curFrameTime >= holdTime)
	{
		Advance();
		curFrameTime -= holdTime;
	}
}

void Animation::Draw(int x, int y)
{
	SDL_Rect pos = { x, y, 90,90 };
	sprite.DrawSprite(&pos, &frames[iCurFrame]);
}

void Animation::Advance()
{
	if (++iCurFrame >= frames.size()) iCurFrame = 0;
}
