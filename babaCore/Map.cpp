#include "PreCompile.h"
#include "Map.h"

Map::Map()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
}

int Index = 0;

Map::~Map()
{
}

void Map::BeginPlay()
{
	Super::BeginPlay();
	// Renderer->SetSamplering(ETextureSampling::LINEAR);
	Renderer->CreateAnimation("Map", "Map", 0.2f);
	SetActorScale3D(FVector(1188.0f, 648.0f, 100.0f));
	Renderer->ChangeAnimation("Map");
}

void Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
