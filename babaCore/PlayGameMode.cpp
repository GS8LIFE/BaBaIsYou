#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "map.h"
#include "mapdeco.h"
#include "fade.h"
#include "Tile.h"
#include "ContentsConstValue.h"
#include <EngineCore/Camera.h>
#include <EngineCore/EngineDebugMsgWindow.h>

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();
	for (int t = 0; t < 20; t++)   //타일맵 초기화 가로35,세로20
	{
	Tilemap.push_back(std::vector<std::string>());

	for (int i = 0; i < 35; ++i) 
	{
		Tilemap[t].push_back("");
	}
	}
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(630.0f, -360.0f, -100.0f));

	{
	}

	{
		std::shared_ptr<Map> MapPtr = GetWorld()->SpawnActor<Map>("Map");
		std::shared_ptr<MapDeco> MapDecoPtr = GetWorld()->SpawnActor<MapDeco>("MapDeco");
		std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
		std::shared_ptr<Tile> TilePtr0 = GetWorld()->SpawnActor<Tile>("Tile", 4);
		std::shared_ptr<Tile> TilePtr1 = GetWorld()->SpawnActor<Tile>("Tile", 4);
		std::shared_ptr<Tile> TilePtr2 = GetWorld()->SpawnActor<Tile>("Tile", 5);
		std::shared_ptr<Tile> TilePtr3 = GetWorld()->SpawnActor<Tile>("Tile", 5);
		std::shared_ptr<Tile> TilePtr4 = GetWorld()->SpawnActor<Tile>("Tile",5);
		std::shared_ptr<Tile> TilePtr5 = GetWorld()->SpawnActor<Tile>("Tile", 5);
		std::shared_ptr<Tile> TilePtr6 = GetWorld()->SpawnActor<Tile>("Tile", 5);
		std::shared_ptr<Tile> TilePtr7 = GetWorld()->SpawnActor<Tile>("Tile", 5);


		Tilemap[12][10] = "/";
		Tilemap[13][10] = "/";
		Tilemap[14][10] = "/";
		Tilemap[15][10] = "/";
		Tilemap[17][10] = "/";
		Tilemap[18][10] = "/";
		Tilemap[16][9] = "/";
		Tilemap[11][11] = "/";
		Tilemap[17][11] = "/";
		Tilemap[15][12] = "/";
		Tilemap[16][12] = "/";
		Tilemap[11][12] = "/";
		Tilemap[11][13] = "/";
		Tilemap[15][13] = "/";
		Tilemap[12][14] = "/";
		Tilemap[13][14] = "/";
		Tilemap[14][14] = "/";
		TilePtr0->SetActorLocation({ TileSize * 10.5f, -TileSize * 16.5f });
		TilePtr0->setTileMap(TilePtr0->GetActorLocation().Y / TileSize, TilePtr0->GetActorLocation().X / TileSize, "00");
		TilePtr1->SetActorLocation({ TileSize * 11.5f, -TileSize * 14.5f });
		TilePtr1->setTileMap(TilePtr1->GetActorLocation().Y / TileSize, TilePtr1->GetActorLocation().X / TileSize, "00");
		TilePtr2->SetActorLocation({ TileSize * 11.5f, -TileSize * 13.5f });
		TilePtr2->setTileMap(TilePtr2->GetActorLocation().Y / TileSize, TilePtr2->GetActorLocation().X / TileSize, "00");
		TilePtr3->SetActorLocation({ TileSize * 12.5f, -TileSize * 14.5f });
		TilePtr3->setTileMap(TilePtr3->GetActorLocation().Y / TileSize, TilePtr3->GetActorLocation().X / TileSize, "00");
		TilePtr4->SetActorLocation({ TileSize * 12.5f, -TileSize * 13.5f });
		TilePtr4->setTileMap(TilePtr4->GetActorLocation().Y / TileSize, TilePtr4->GetActorLocation().X / TileSize, "00");
		TilePtr5->SetActorLocation({ TileSize * 11.5f, -TileSize * 12.5f });
		TilePtr5->setTileMap(TilePtr5->GetActorLocation().Y / TileSize, TilePtr5->GetActorLocation().X / TileSize, "00");
		TilePtr6->SetActorLocation({ TileSize * 13.5f, -TileSize * 13.5f });
		TilePtr6->setTileMap(TilePtr6->GetActorLocation().Y / TileSize, TilePtr6->GetActorLocation().X / TileSize, "00");
		TilePtr7->SetActorLocation({ TileSize * 12.5f, -TileSize * 12.5f });
		TilePtr7->setTileMap(TilePtr7->GetActorLocation().Y / TileSize, TilePtr7->GetActorLocation().X / TileSize, "00");

		Player->SetActorLocation({ TileSize * 10.5f, -TileSize * 16.5f, 0.0f });     // 18,-18이 0,0 이미지 위치임
		Player->SetActorScale3D({ 100.0f, 100.0f, 100.0f });
		Player->setTileMap(Player->GetActorLocation().Y / TileSize, Player->GetActorLocation().X / TileSize, "Cursor");

		MapPtr->SetActorLocation({ 630.0f, -360.0f, 0.0f });
		MapDecoPtr->SetActorLocation({ 630.0f, -360.0f, 0.0f });

	}
}

void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}