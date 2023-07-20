#pragma once
#include "Animation.h"
#include "Keyboard.h"

class CharacterAnimation
{
private:
	enum class State
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};
public:
	CharacterAnimation(int x, int y, Renderer& renderer, Keyboard& kbd);
	void SetDirection();
	void Update(float dt);
	void Draw();
private:
	std::vector<Animation> animations;
	Keyboard& kbd;
	Sprite sprite;
	State CurState = State::StandingDown;
	int x;
	int y;
};
