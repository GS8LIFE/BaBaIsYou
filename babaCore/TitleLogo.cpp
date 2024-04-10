#include "PreCompile.h"
#include "TitleLogo.h"

ATitleLogo::ATitleLogo() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

int Index = 0;

ATitleLogo::~ATitleLogo() 
{
}

void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(700.0f, 300.0f, 100.0f));
	

	// Renderer->SetSamplering(ETextureSampling::LINEAR);
	Renderer->CreateAnimation("Title", "Map", 0.2f);

	Renderer->ChangeAnimation("Title");
	Renderer->SetOrder(1);
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
