#pragma once
#include <map>
#include <string>
#include "Texture.h"
#include "Sound.h"
#include "Font.h"

class Assets
{
public:
	Assets(Renderer** rend);
	~Assets();
	Texture& GetTexture(std::string name);
	Font& GetFont(std::string name);
	Font* text1;
	Font* text2;
private:
	std::map<std::string, Texture*> Textures;
	Sound PlayerSounds = Sound(1, "Resources/Sounds");

};