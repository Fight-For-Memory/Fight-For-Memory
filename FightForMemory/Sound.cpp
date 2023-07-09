#include "Sound.h"

Sound::Sound(const char* filename)
{
	if (SDL_LoadWAV(filename, &wav_spec, &wav_buffer, &wav_length) == NULL)
		throw SDL_GetError();
	deviceId = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
}

Sound::~Sound()
{
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wav_buffer);
}

void Sound::Play()
{
	SDL_QueueAudio(deviceId, wav_buffer, wav_length);
	SDL_PauseAudioDevice(deviceId, 0);
}

void Sound::Pause()
{
	SDL_PauseAudioDevice(deviceId, 1);
}
