#include "Assets.h"
#include <filesystem>

namespace fs = std::filesystem;

Assets::Assets(Renderer** rend)
{
	for (const auto& entry : fs::directory_iterator("Resources/Images"))
		if (entry.is_regular_file())
			if(entry.path().filename().extension().string() == "bmp")
				Textures[entry.path().filename().stem().string()] = new Texture(entry.path().string().c_str(), rend);
			else
				Textures[entry.path().filename().stem().string()] = new Texture(entry.path().string().c_str(), rend, FileType::png);

	text1 = new Font("Witaj Cyprian :)", "Resources/Fonts/Arial.ttf", 35, rend, { 175, 0, 300, 50 }, { 255,100,100 });
	text2 = new Font("Witaj Hubert  :)", "Resources/Fonts/Arial.ttf", 35, rend, { 175, 75, 300, 50 }, { 100,255,100 });
}

Assets::~Assets()
{
	for (auto t : Textures)
		delete t.second;
	delete text1;
	delete text2;
}

Texture& Assets::GetTexture(std::string name)
{
	return *Textures[name];
}

