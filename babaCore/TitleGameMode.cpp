#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleLogo.h"
#include "map.h"
#include "MapDeco.h"
#include <EngineCore/Camera.h>
ATitleGameMode::ATitleGameMode() 
{
}

ATitleGameMode::~ATitleGameMode() 
{
}

void ATitleGameMode::BeginPlay() 
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<Map>("Map");
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("PlayLevel");
	}
}

void ATitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}