#include "Sound.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

Sound::Sound(int channel, const char* folder_path)
	:
	channel(channel)
{
	for (const auto& entry : fs::directory_iterator(folder_path)) 
		if (entry.is_regular_file()) 
			sounds[entry.path().filename().stem().string()] = Mix_LoadWAV(entry.path().string().c_str());
	
}

void Sound::Play(std::string sound)
{
	Mix_PlayChannel(channel, sounds[sound], 0);
}

void Sound::SetVolume(int volume)
{
	Mix_Volume(channel, volume);
}

void Sound::SetVolume(int channel, int volume)
{
	Mix_Volume(channel, volume);
}

Sound::~Sound()
{
	for(auto& sound : sounds)
		Mix_FreeChunk(sound.second);
}


