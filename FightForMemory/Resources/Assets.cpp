#include "Assets.h"
#include <filesystem>

namespace fs = std::filesystem;

Assets::Assets(Renderer** rend)
{
	for (const auto& entry : fs::directory_iterator("Resources/Images"))
		if (entry.is_regular_file())
			if(entry.path().filename().extension().string() == ".bmp")
				Textures[entry.path().filename().stem().string()] = new Texture(entry.path().string().c_str(), rend, FileType::bitmap);
			else
				Textures[entry.path().filename().stem().string()] = new Texture(entry.path().string().c_str(), rend, FileType::png);

	font = new Font( "Resources/Fonts/Arial.ttf", 35);
	Cyprian = new Text("Witaj Cyprian :)", font, rend, { 175, 0, 300, 50 }, { 255,100,100 });
	Hubert = new Text("Witaj Hubert  :)", font, rend, { 175, 75, 300, 50 }, { 100,255,100 });
}

Assets::~Assets()
{
	for (auto t : Textures)
		delete t.second;
	delete font;
	delete Cyprian;
	delete Hubert;
}

Texture& Assets::GetTexture(std::string name)
{
	return *Textures[name];
}

