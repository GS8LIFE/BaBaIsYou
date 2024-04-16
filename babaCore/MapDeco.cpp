#include "MapDeco.h"
#include "PreCompile.h"
MapDeco::MapDeco() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer1");
	SetRoot(Renderer);
}

MapDeco::~MapDeco() 
{
}

void MapDeco::BeginPlay()
{

	Super::BeginPlay();
	// Renderer->SetSamplering(ETextureSampling::LINEAR);
	Renderer->CreateAnimation("MapDeco", "MapDeco", 0.2f);
	SetActorScale3D(FVector(1188.0f, 648.0f, 80.0f));
	Renderer->ChangeAnimation("MapDeco");
	Renderer->SetOrder(-1);

}
void MapDeco::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
