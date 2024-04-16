#include "PreCompile.h"
#include "Tile.h"
#include "PlayGameMode.h"
#include <EngineCore/DefaultSceneComponent.h>

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

	if(IsMove == true)
	{
	if (true == IsUp('A'))
	{
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
		MoveDir = GetActorLocation();
		MoveDir += {0.0f, TileSize};
	}

	if (true == IsUp('S'))
	{
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
		MoveTime += _DeltaTime + MoveTimeWeight;
		FVector CurLocation = GetActorLocation();

		FVector NextPos = FVector::LerpClamp(CurLocation, _MoveDir, MoveTime);
		SetActorLocation(NextPos);

		if (MoveTime >= 1.0f)
		{
			MoveTime = 0.0f;
			MoveDir = FVector::Zero;
			MoveActive = false;
		}
	}
}

void Tile::setTileMap(int _a, int _b,char _c)
{
	Tilemap[_a][_b] = _c;
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
}