#include "PreCompile.h"
#include "Tile.h"
#include "PlayGameMode.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/EngineDebugMsgWindow.h>

Tile::Tile() 
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	SetRoot(Root);
	InputOn();

}

Tile::~Tile() 
{
}


/*void Tile::AllTileCheck(bool _Noun)
{
	for (int column = 0; column < 20; column++) 
	{
		for (int Row = 0; Row < 35; Row++)
		{
			Noun = containsString(Nouns, Tilemap[column][Row]);
		}
	}
}
*/

void Tile::TileTypeCheck()
{
	Noun = containsString(Nouns, TileName);
	Verb = containsString(Verbs, TileName);
	Object = containsString(Objects, TileName);
	if (Noun)
	{
		Type = "Noun";
	}
	else if (Verb)
	{
		Type = "Verb";
	}
	else if (Object)
	{
		Type = "Object";
	}
}


std::string Tile::texterase(std::string _text)
{
	std::string erasetext = "Text";
	
	int pos = _text.find(erasetext);
	if (pos != std::string::npos)
	{ 
		return _text.erase(pos, erasetext.length());
	}
}


void Tile::Sentence(bool _Noun)
{
	if (_Noun)
	{
		if (containsString(Verbs, Tilemap[TileY][TileX + 1]))
		{
			if (containsString(Objects, Tilemap[TileY][TileX + 2]))
			{
				if (SentenceRow.empty())
				{
					SentenceRow += texterase(WhatyourName(Nouns, Tilemap[TileY][TileX]));
					SentenceRow += texterase(WhatyourName(Verbs, Tilemap[TileY][TileX + 1]));
					SentenceRow += texterase(WhatyourName(Objects, Tilemap[TileY][TileX + 2]));
					Rule.push_back(SentenceRow);
				}
			}
			else if (containsString(Nouns, Tilemap[TileY][TileX + 2]))
			{
				if (SentenceRow.empty())
				{
					SentenceRow += texterase(WhatyourName(Nouns, Tilemap[TileY][TileX]));
					SentenceRow += texterase(WhatyourName(Verbs, Tilemap[TileY][TileX + 1]));
					SentenceRow += texterase(WhatyourName(Nouns, Tilemap[TileY][TileX + 2]));
					Rule.push_back(SentenceRow);
				}
			}
			else
			{
				auto find = std::find(Rule.begin(), Rule.end(), SentenceRow);
				if 
					(find != Rule.end()) 
				{
					Rule.erase(find);
				}
				SentenceRow.clear();
			}
		}
		else if (containsString(Verbs, Tilemap[TileY + 1][TileX]))
		{
			if (containsString(Objects, Tilemap[TileY + 2][TileX]))
			{
				if(SentenceColumn.empty())
				{
					SentenceColumn += texterase(WhatyourName(Nouns, Tilemap[TileY][TileX]));
					SentenceColumn += texterase(WhatyourName(Verbs, Tilemap[TileY + 1][TileX]));
					SentenceColumn += texterase(WhatyourName(Objects, Tilemap[TileY + 2][TileX]));
					Rule.push_back(SentenceColumn);
				}
			}
			else if (containsString(Nouns, Tilemap[TileY + 2][TileX]))
			{
				if (SentenceColumn.empty())
				{
					SentenceColumn += texterase(WhatyourName(Nouns, Tilemap[TileY][TileX]));
					SentenceColumn += texterase(WhatyourName(Verbs, Tilemap[TileY + 1][TileX]));
					SentenceColumn += texterase(WhatyourName(Nouns, Tilemap[TileY + 2][TileX]));
					Rule.push_back(SentenceColumn);
				}
			}
			else
			{
				auto find = std::find(Rule.begin(), Rule.end(), SentenceColumn);
				if
					(find != Rule.end())
				{
					Rule.erase(find);
				}
				SentenceColumn.clear();
			}
		}
		else
		{
			auto findColumn = std::find(Rule.begin(), Rule.end(), SentenceColumn);
			if
				(findColumn != Rule.end())
			{
				Rule.erase(findColumn);
			}
			auto findRow = std::find(Rule.begin(), Rule.end(), SentenceRow);
			if
				(findRow != Rule.end())
			{
				Rule.erase(findRow);
			}
			SentenceColumn.clear();
			SentenceRow.clear();
		}
	}
	else
	{
		auto findColumn = std::find(Rule.begin(), Rule.end(), SentenceColumn);
		if
			(findColumn != Rule.end())
		{
			Rule.erase(findColumn);
		}
		auto findRow = std::find(Rule.begin(), Rule.end(), SentenceRow);
		if
			(findRow != Rule.end())
		{
			Rule.erase(findRow);
		}
		SentenceColumn.clear();
		SentenceRow.clear();
	}
}

void Tile::CreateChar()
{

}

std::string Tile::GetTileName()
{
	std::string TileName;
	int Y = GetActorLocation().Y/TileSize;
	int X = GetActorLocation().X/TileSize;
	for (const std::string& str : Tilemap[Y][X]) {
		TileName += str;
	}
	return TileName;
}
void Tile::SetMove(bool _SetMove)
{
	Tile::IsMove = _SetMove;
}

bool Tile::containsString(const std::vector<std::string>& strings, const std::string& target) {
	for (const auto& str : strings) {
		if (str == target) {
			return true;
		}
	}
	return false;
}

std::string Tile::WhatyourName(const std::vector<std::string>& strings, std::string& target) {
	for (const auto& str : strings) {
		if (str == target) {
			return target;
		}
	}
	return "Empthy";
}

void Tile::move(float _DeltaTime)
{
	//if (true == Renderer->IsCurAnimationEnd())
	//{
	//	int a = 0;
	//}
	if (IsUp('A') || IsUp('D') || IsUp('W') || IsUp('S'))
	{
		int Column = GetActorLocation().Y * -1 / TileSize;
		int Row = GetActorLocation().X / TileSize;
		std::pair Tilepair = std::make_pair(Column,Row);
		for (std::pair<int,int,int> pair : APlayer::visitTile) {

			if (pair.first == Tilepair.first)
			{
				if (pair.second == Tilepair.second)
				{
					IsMove = true;
					auto it = std::find(APlayer::visitTile.begin(), APlayer::visitTile.end(), pair);
					if (it != APlayer::visitTile.end()) {
						APlayer::visitTile.erase(it);
					}
					break;
				}
			}
		}
	}
	if(IsMove == true)
	{
	if (true == IsUp('A'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {-TileSize, 0.0f};
	}

	else if (true == IsUp('D'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {TileSize, 0.0f};
	}

	else if (true == IsUp('W'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {0.0f, TileSize};
	}

	else if (true == IsUp('S'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {0.0f, -TileSize};
	}


	//float4 Pos = GetActorLocation();


	//Pos /= UContentsConstValue::TileSize;
	//Pos.Y = -Pos.Y;

	//Color8Bit Color = Tex->GetColor(Pos, Color8Bit::Black);

	//if (Color != Color8Bit::Black)
	//{
	//	AddActorLocation(float4::Down * _DeltaTime * 100.0f);
	//}
	}
}

void Tile::MoveOneBlock(float _DeltaTime, FVector _MoveDir)
{
	if (MoveActive == true)
	{

		InputOff();
		MoveTime += _DeltaTime + MoveTimeWeight;
		FVector CurLocation = GetActorLocation();

		FVector NextPos = FVector::LerpClamp(CurLocation, _MoveDir, MoveTime);
		SetActorLocation(NextPos);

		if (MoveTime >= 1.0f)
		{

			MoveTime = 0.0f;
			MoveDir = FVector::Zero;
			MoveActive = false;
			IsMove = false;
			InputOn();
		}
	}
}
void Tile::TileLocation()
{
	if (GetActorLocation().Y < 0)
	{
		TileY = -GetActorLocation().Y / TileSize;
	}
	if (GetActorLocation().X > 0)
	{
		TileX = GetActorLocation().X / TileSize;
	}
}

void Tile::setTileMap(int _a, int _b,std::string _c)
{
	high = Tilemap[-_a][_b].size();
	Tilemap[-_a][_b].push_back(_c);
 	TileName = _c;
}


void Tile::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
	TileLocation();
	TileTypeCheck();
	move(_DeltaTime);
	MoveOneBlock(_DeltaTime, MoveDir);
	Sentence(Noun);
	DebugMessageFunction();
	if (TileName != "") 
	{
	Renderer->ChangeAnimation(TileName);
	}
}
