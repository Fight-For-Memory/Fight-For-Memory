#pragma once
#include <map>
#include <string>
#include "GameObjects.h"

class Settings
{
public:
	int* ScreenWidth ;
	int* ScreenHeight ;
	int* PlayerSoundVolume;
	int* MusicVolume;
	std::string SettingsFile = "";
	std::string SettingsLocation = "";
	Window** windowPointer;
};