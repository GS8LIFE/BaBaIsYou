#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "map.h"
#include "mapdeco.h"
#include "Tile.h"
#include "ContentsConstValue.h"
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

	Tilemap.push_back(std::vector<char>());

	for (int i = 0; i < 4; ++i) {
		Tilemap[0].push_back(' ');
	}

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(630.0f, -360.0f, -100.0f));

	{
	}

	{
		std::shared_ptr<Map> MapPtr = GetWorld()->SpawnActor<Map>("Map");
		std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
		std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
		std::shared_ptr<MapDeco> MapDecoPtr = GetWorld()->SpawnActor<MapDeco>("MapDeco");
		std::shared_ptr<Tile> TilePtr = GetWorld()->SpawnActor<Tile>("Tile");
		std::shared_ptr<Tile> TilePtr1 = GetWorld()->SpawnActor<Tile>("Tile");

		TilePtr->setTileMap(0,1,'C');
		Player->setTileMap(0, 0, 'B');
		TilePtr->SetActorLocation({ 54.0f, -54.0f });
		TilePtr1->SetActorLocation({ 54.0f, -90.0f });
		Player->SetActorLocation({ 18.0f, -18.0f, 0.0f });
		MapPtr->SetActorLocation({ 630.0f, -360.0f, 0.0f });
		MapDecoPtr->SetActorLocation({ 630.0f, -360.0f, 0.0f });

	}
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Tilemap;

}