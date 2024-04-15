#include "PreCompile.h"
#include "Tile.h"
Tile::Tile() 
{
	
}

Tile::~Tile() 
{
}

void Tile::BeginPlay()
{
	TileSize = UContentsConstValue::TileSize;
	
}

void Tile::MoveBase(float _Deltatime)
{
	if (IsMove == true)
	{

	}
}
void Tile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
