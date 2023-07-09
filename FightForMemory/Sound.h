#pragma once
#include <SDL.h>
#include <SDL_mixer.h>

class Sound
{
public:
	Sound(const char* filename);
	~Sound();
	void Play();
	void Pause();
private:
	SDL_AudioDeviceID deviceId;
	SDL_AudioSpec wav_spec;
	Uint32 wav_length;
	Uint8* wav_buffer;
};
 