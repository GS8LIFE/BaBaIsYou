#include "PreCompile.h"
#include "fade.h"

fade::fade()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer2");
	SetRoot(Renderer);
}


fade::~fade()
{
}

void fade::BeginPlay()
{
	Super::BeginPlay();
	// Renderer->SetSamplering(ETextureSampling::LINEAR);
	Renderer->CreateAnimation("fade", "fade", 0.03f, false);
	SetActorScale3D(FVector(1260.0f, 720.0f, 100.0f));
	Renderer->ChangeAnimation("fade");
	Renderer->SetOrder(9);
} 

void fade::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (Renderer->IsCurAnimationEnd())
	{
		Destroy();
	}
}
