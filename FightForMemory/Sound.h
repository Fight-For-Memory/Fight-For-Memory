#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <map>
#include <string>


class Sound
{
public:
	Sound(int channel, const char* folder_path);
	~Sound();
	void Play(std::string sound);
private:
	std::map<std::string,Mix_Chunk*> sounds;
	const int channel;
};
 