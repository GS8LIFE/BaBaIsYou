#pragma once
#include <string>
class helper
{
public:
	static const float TileSize;
	static std::vector<std::vector<std::string>> Tilemap;
	static std::vector<std::string> Nouns;
	static std::vector<std::string> Verbs;
	static std::vector<std::string> Objects;
};

enum TileType
{
	Noun,
	Verb,
	Object
};