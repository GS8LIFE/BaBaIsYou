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
	Renderer->CreateAnimation("fade", "fade", 0.2f, false);
	SetActorScale3D(FVector(1188.0f, 648.0f, 100.0f));
	Renderer->ChangeAnimation("fade");
	Renderer->SetOrder(3);
}

void fade::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (Renderer->IsCurAnimationEnd())
	{
		Destroy();
	}
}
