#include "Character.h"

CharacterAnimation::CharacterAnimation(int x, int y, Renderer& renderer, Keyboard& kbd)
	:
	sprite("Resources/Images/link90x90.bmp", renderer),
	kbd(kbd),
	x(x),
	y(y)
{
	for (int i = 0; i < int(State::StandingLeft); i++)
		animations.emplace_back(Animation(90, 90 * i, 90, 90, 4, 1.5f, sprite));

	for (int i = int(State::StandingLeft); i < int(State::Count); i++)
		animations.emplace_back(Animation(0, 90 * (i- int(State::StandingLeft)), 90, 90, 1, 1.5f, sprite));
}

void CharacterAnimation::SetDirection()
{
	if (kbd.IsKeyDown(SDL_SCANCODE_W))
		CurState = State::WalkingUp;
	else if (kbd.IsKeyDown(SDL_SCANCODE_S))
		CurState = State::WalkingDown;
	else if (kbd.IsKeyDown(SDL_SCANCODE_A))
		CurState = State::WalkingLeft;
	else if (kbd.IsKeyDown(SDL_SCANCODE_D))
		CurState = State::WalkingRight;
	else
	{
		switch (CurState)
		{
		case State::WalkingLeft:
			CurState = State::StandingLeft;
			break;
		case State::WalkingRight:
			CurState = State::StandingRight;
			break;
		case State::WalkingUp:
			CurState = State::StandingUp;
			break;
		case State::WalkingDown:
			CurState = State::StandingDown;
			break;
		}
	}
}

void CharacterAnimation::Update(float dt)
{
	SetDirection();
	animations[int(CurState)].Update(dt);
}

void CharacterAnimation::Draw()
{
	SDL_Delay(5);
	animations[int(CurState)].Draw(x, y);
}
