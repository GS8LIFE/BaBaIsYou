#include "PreCompile.h"
#include "ContentsConstValue.h"

int helper::StageLevel = -1;
const float helper::TileSize = 36.0f;
std::vector<std::string> helper::Rule = {};
std::vector<std::vector<std::string>> helper::Tilemap;
std::vector<std::string> helper::Nouns = { "TextBaba", "TextKeke", "TextWall" };
std::vector<std::string> helper::Verbs = { "TextIs", "TextHave" };
std::vector<std::string> helper::Objects = { "TextYou", "TextMelt" };
std::vector<std::string> helper::AllTile = { "TextYou", "TextMelt","TextIs", "TextHave","TextBaba", "TextKeke", "TextWall" };