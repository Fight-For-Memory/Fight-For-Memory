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
	void SetVolume(int volume);
	static void SetVolume(int channel, int volume);
private:
	std::map<std::string,Mix_Chunk*> sounds;
	const int channel;
};
 