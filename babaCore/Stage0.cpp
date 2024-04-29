#include "PreCompile.h"
#include "Stage0.h"
#include "Map.h"
#include <EngineCore/Camera.h>
Stage0::Stage0() 
{
	for (size_t YY = 0; YY < 19; YY++)
	{
		for (size_t XX = 0; XX < 34; XX++)
		{
			{
				Tilemap[YY][XX] = "";
			}
		}
	}

	for (int t = 0; t < 20; t++)   //타일맵 초기화 가로35,세로20
	{
		if (t == 0 || t == 19)
		{
			for (int i = 0; i < 35; ++i)
			{
				Tilemap[t][i] = "/";
			}
		}
		else {
			for (int i = 0; i < 1; ++i)
			{
				Tilemap[t][i] = "/";
			}
			for (int i = 6; i < 34; ++i)
			{
				Tilemap[t][i] = "";
			}
			for (int i = 34; i < 35; ++i)
			{
				Tilemap[t][i] = "/";
			}
		}
	}
}

Stage0::~Stage0() 
{
}

void Stage0::BeginPlay()
{

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(630.0f, -360.0f, -100.0f));

	std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
	std::shared_ptr<Map> Mapback = GetWorld()->SpawnActor<Map>("Mapback");

	Mapback->Renderer->ChangeAnimation("MapBack");
	Mapback->SetActorLocation({ 630.0f, -360.0f, 0.0f });

	Player->SetActorLocation({ TileSize * 10.5f, -TileSize * 11.5f, 0.0f });     // 18,-18이 0,0 이미지 위치임
	Player->setTileMap(Player->GetActorLocation().Y / TileSize, Player->GetActorLocation().X / TileSize, "Dmove0");
}
void Stage0::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
