#include "PreCompile.h"
#include "ContentsConstValue.h"

const float helper::TileSize = 36.0f;
bool helper::IsMove = false;
void helper::SetMove(bool _SetMove)
{
	IsMove = _SetMove;
}
std::vector<std::vector<std::string>> helper::Tilemap;
std::vector<std::string> helper::Verbs = { "TextIs", "TextHave" };
std::vector<std::string> helper::Objects = { "TextYou", "TextMelt" };
std::vector<std::string> helper::Nouns = { "TextBaba", "TextKeke", "TextWall" };