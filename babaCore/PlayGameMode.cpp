#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "map.h"
#include "mapdeco.h"
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
		std::shared_ptr<Tile> TilePtr1 = GetWorld()->SpawnActor<Tile>("Tile",4);
		std::shared_ptr<Tile> TilePtr = GetWorld()->SpawnActor<Tile>("Tile",5);
		std::shared_ptr<Tile> TilePtr2 = GetWorld()->SpawnActor<Tile>("Tile", 5);
		std::shared_ptr<Tile> TilePtr3 = GetWorld()->SpawnActor<Tile>("Tile", 5);
		
		Tilemap[0][8] = "/";
		Player->SetActorLocation({ TileSize*0.5f, -TileSize*0.5f, 0.0f });     // 18,-18이 0,0 이미지 위치임
 		Player->setTileMap(Player->GetActorLocation().Y /TileSize , Player->GetActorLocation().X/TileSize, "Baba");
		TilePtr1->SetActorLocation({ TileSize * 1.5f, -TileSize * 4.5f });
		TilePtr3->SetActorLocation({ TileSize * 3.5f, -TileSize * 4.5f });
		TilePtr1->setTileMap(TilePtr1->GetActorLocation().Y / TileSize, TilePtr1->GetActorLocation().X / TileSize, "TextBaba");
		TilePtr3->SetActorLocation({ TileSize*3.5f, -TileSize*4.5f });
		TilePtr3->setTileMap(TilePtr3->GetActorLocation().Y / TileSize, TilePtr3->GetActorLocation().X / TileSize, "TextMelt");
		TilePtr2->SetActorLocation({ TileSize * 6.5f, -TileSize * 4.5f });
		TilePtr2->setTileMap(TilePtr2->GetActorLocation().Y / TileSize, TilePtr2->GetActorLocation().X / TileSize, "TextIs");
		TilePtr->SetActorLocation({ TileSize * 6.5f, -TileSize * 4.5f });
		TilePtr->setTileMap(TilePtr->GetActorLocation().Y / TileSize, TilePtr->GetActorLocation().X / TileSize, "TextBaba");

		MapPtr->SetActorLocation({ 630.0f, -360.0f, 0.0f });
		MapDecoPtr->SetActorLocation({ 630.0f, -360.0f, 0.0f });


	}
}

void APlayGameMode::DebugMessageFunction()
{
	std::string Msg;
	for (size_t YY = 0; YY < 19; YY++)
	{
		for (size_t XX = 0; XX < 34; XX++)
		{
			{
				Msg = std::format("map : {} = {},{}", Tilemap[YY][XX], YY, XX);
				UEngineDebugMsgWindow::PushMsg(Msg);
			}
		}
		UEngineDebugMsgWindow::PushMsg("\n");
	}
}
void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DebugMessageFunction();

}