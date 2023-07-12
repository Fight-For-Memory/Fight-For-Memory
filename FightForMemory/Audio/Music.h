#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
class Music
{
public:
	static void Init();
	static void Play(const char * music, int volume = -1);
	static void SetVolume(int volume);
	static void Stop();
	static void Pause();
	static void Resume();
private:
	static Mix_Music* music;
};

