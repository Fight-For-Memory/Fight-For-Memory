#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
class Music
{
public:
	static void Init();
	void Play(const char * music, int volume = -1);
	void SetVolume(int volume);
	void Stop();
	void Pause();
	void Resume();
private:
	Mix_Music* music = nullptr;
};

