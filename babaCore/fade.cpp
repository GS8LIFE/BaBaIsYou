#include "PreCompile.h"
#include "Stage0.h"
#include "Stage1.h"
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
	Renderer->CreateAnimation("fadeIn", "fadeIn", 0.03f, false);
	Renderer->CreateAnimation("fadeOut", "fadeOut", 0.03f, false);
	SetActorScale3D(FVector(1260.0f, 720.0f, 100.0f));
	Renderer->SetSprite("babaisfefa.png");
	Renderer->SetOrder(9);
	Level = helper::StageLevel;
} 

void fade::ChangeLevel(int _Level)
{
	Level = _Level;
	switch (Level)
	{
	case 0:
		GEngine->CreateLevel<Stage0>("stage0");
		Renderer->ChangeAnimation("fadeIn");
		Name = "fadeIn";
		break;
	case 1:
		GEngine->CreateLevel<Stage1>("stage1");
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		break;
	}
}
void fade::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (Level != helper::StageLevel)
	{
		Level = helper::StageLevel;
		Name = "fadeIn";
		Renderer->ChangeAnimation("fadeIn");
	}
	if (Name == "fadeIn")
	{
		if (Renderer->IsCurAnimationEnd())
		{
			switch (Level)
			{
			case 0:
				GEngine->ChangeLevel("stage0");
				break;
			case 1:
				GEngine->ChangeLevel("stage1");
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				break;
			}

			Destroy();
		}
	}
	else
	{
	}
}
