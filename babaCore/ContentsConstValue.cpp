#include "PreCompile.h"
#include "ContentsConstValue.h"

const float helper::TileSize = 36.0f;
bool helper::IsMove = false;
void helper::SetMove(bool _SetMove)
{
	IsMove = _SetMove;
}
std::vector<std::vector<char>> helper::Tilemap;