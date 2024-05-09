#include "PreCompile.h"
#include "ContentsConstValue.h"

int helper::StageLevel = -1;
const float helper::TileSize = 36.0f;
std::vector<std::string> helper::Rule = {};
std::vector<std::vector<std::vector<std::string>>> helper::Tilemap;
std::vector<std::string> helper::Nouns = { "TextBaba", "TextKeke", "TextWall" };
std::vector<std::string> helper::Verbs = { "TextIs", "TextHave" };
std::vector<std::string> helper::Objects = { "TextYou", "TextMelt" };
std::vector<std::string> helper::AllTile = { "TextYou", "TextMelt","TextIs", "TextHave","TextBaba", "TextKeke", "TextWall","00"};
std::vector<std::string> helper::State = { "Push", "Stop","You", "Win","Sink", "Deafeat", "Melt","Hot"};
std::vector<std::string> helper::AnimationState = { 
	"Cursor", 
	//커서
	"BabaDmove0","BabaDmove1", "BabaDmove2","BabaDmove3", "BabaWmove0", "BabaWmove1","BabaWmove2","BabaWmove2","BabaWmove2","BabaWmove2","BabaWmove2","BabaWmove2","BabaWmove2",
	"BabaWmove3","BabaAmove0","BabaAmove1","BabaAmove2","BabaAmove3","BabaSmove0","BabaSmove1","BabaSmove2","BabaSmove3",
	//바바
	"Rock",
	//돌
	"Wall"

};
