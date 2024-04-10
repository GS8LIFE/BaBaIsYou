#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "map.h"
#include "mapdeco.h"
#include <EngineCore/Camera.h>

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();


	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	{
	}

	{
		std::shared_ptr<Map> MapPtr = GetWorld()->SpawnActor<Map>("Map");
		std::shared_ptr<MapDeco> MapDecoPtr = GetWorld()->SpawnActor<MapDeco>("MapDeco");

		MapPtr->SetActorLocation({ 640.0f, -360.0f, 200.0f });
		MapDecoPtr->SetActorLocation({ 640.0f, -360.0f, 200.0f });

		float TileSize = UContentsConstValue::TileSize;
		float4 TexScale = UContentsConstValue::MapTexScale;
		float4 ImageScale = { TexScale.X * TileSize, TexScale.Y * TileSize, 0.0f };

	}
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}