#include "Music.h"

void Music::Init()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void Music::Play(const char* music, int volume)
{
	if (this->music != nullptr) Mix_FreeMusic(this->music);
	this->music = Mix_LoadMUS(music);
	Mix_PlayMusic(this->music, -1);
	Mix_VolumeMusic(volume);
}

void Music::SetVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

void Music::Stop()
{
	Mix_HaltMusic();
	if (music == nullptr) return;
	Mix_FreeMusic(music);
	music = nullptr;
}

void Music::Pause()
{
	Mix_PauseMusic();
}

void Music::Resume()
{
	Mix_ResumeMusic();
}
