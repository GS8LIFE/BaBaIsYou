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

void Tile::setTileType(TileType _Type)
{
	Type = _Type;
}
void Tile::TileCheck()
{
	for (int column = 0; column < 20; column++) 
	{
		for (int Row = 0; Row < 35; Row++)
		{
			bool a = containsString(Nouns, Tilemap[column][Row]);
		}
	}
}

void Tile::CreateChar()
{

}

std::string Tile::GetTileName()
{
	int Y = GetActorLocation().Y/TileSize;
	int X = GetActorLocation().X/TileSize;
	return Tilemap[Y][X];
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
void Tile::move(float _DeltaTime)
{
	//if (true == Renderer->IsCurAnimationEnd())
	//{
	//	int a = 0;
	//}
	if (IsDown('A') || IsDown('D') || IsDown('W') || IsDown('S'))
	{
		int Column = GetActorLocation().Y * -1 / TileSize;
		int Row = GetActorLocation().X / TileSize;
		std::pair Tilepair = std::make_pair(Column,Row);
		for (std::pair<int,int> pair : APlayer::visitTile) {

			if (pair.first == Tilepair.first)
			{
				if (pair.second == Tilepair.second)
				{
					IsMove = true;
					APlayer::visitTile.erase(std::remove(APlayer::visitTile.begin(), APlayer::visitTile.end(), pair), APlayer::visitTile.end());
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

	if (true == IsUp('D'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {TileSize, 0.0f};
	}

	if (true == IsUp('W'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {0.0f, TileSize};
	}

	if (true == IsUp('S'))
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

void Tile::setTileMap(int _a, int _b,std::string _c)
{
	Tilemap[-_a][_b] = _c;
	TileName = _c;
}
void Tile::BeginPlay()
{
	Super::BeginPlay();
	TileSize = helper::TileSize;


	Renderer->CreateAnimation("Dmove0", "baba", 0.2f, true, 0, 2);
	Renderer->CreateAnimation("babablock", "textbaba", 0.2f);

	SetActorScale3D(FVector(36.0f, 36.0f, -100.0f));
	Renderer->ChangeAnimation("babablock");
}

void Tile::MoveBase(float _Deltatime)
{
	if (IsMove == true)
	{

	}
}
void Tile::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
	move(_DeltaTime);
	MoveOneBlock(_DeltaTime, MoveDir);
	TileCheck();
	DebugMessageFunction();
}

void Tile::DebugMessageFunction()
{
	int TileY = 0;
	int TileX = 0;

	if (GetActorLocation().Y < 0)
	{
		TileY = -GetActorLocation().Y / TileSize;
	}
	if (GetActorLocation().X > 0)
	{
		TileX = GetActorLocation().X / TileSize;
	}

	{
		std::string Msg = std::format("{} Location : {},{}\n",TileName, TileX, TileY);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("Name : {}\n", Tilemap[TileY][TileX]);
		UEngineDebugMsgWindow::PushMsg(Msg);
	} 
	{
		std::string Msg = std::format("------------------------------");
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}
