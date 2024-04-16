#pragma once

class helper
{
public:
	static const float TileSize;
	static std::vector<std::vector<char>> Tilemap;
	static bool IsMove;
	static void SetMove(bool _SetMove);
};