#include "PreCompile.h"
#include "Stage0.h"
#include "Map.h"
#include "fade.h"
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

	std::shared_ptr<fade> fadeout = GetWorld()->SpawnActor<fade>("fade");
	std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
	SquarTile();
	std::shared_ptr<Map> Mapback = GetWorld()->SpawnActor<Map>("Mapback");


	fadeout->Renderer->ChangeAnimation("fadeOut");
	fadeout->SetActorLocation({ 630.0f, -360.0f, 0.0f });
	fadeout->Level = 3;
	fadeout->Renderer->ChangeAnimation("fadeOut");

	Mapback->Renderer->ChangeAnimation("MapBack");
	Mapback->SetActorLocation({ 630.0f, -360.0f, 0.0f });

	Player->SetActorLocation({ TileSize * 13.5f, -TileSize * 11.5f, 0.0f });     // 18,-18이 0,0 이미지 위치임
	Player->SetActorScale3D({35.0f,35.0f,30.0f});
	Player->setTileMap(Player->GetActorLocation().Y / TileSize, Player->GetActorLocation().X / TileSize, "Dmove0");
}
void Stage0::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}

void Stage0::SquarTile()
{
	std::shared_ptr<Map> Squar1 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar2 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar3 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar4 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar5 = GetWorld()->SpawnActor<Map>("Squar");

	std::shared_ptr<Map> Squar6 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar7 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar8 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar9 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar10 = GetWorld()->SpawnActor<Map>("Squar");

	std::shared_ptr<Map> Squar11 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar12 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar13 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar14 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar15 = GetWorld()->SpawnActor<Map>("Squar");

	std::shared_ptr<Map> Squar16 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar17 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar18 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar19 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar20 = GetWorld()->SpawnActor<Map>("Squar");

	std::shared_ptr<Map> Squar21 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar22 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar23 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar24 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar25 = GetWorld()->SpawnActor<Map>("Squar");

	std::shared_ptr<Map> Squar26 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar27 = GetWorld()->SpawnActor<Map>("Squar");
	std::shared_ptr<Map> Squar28 = GetWorld()->SpawnActor<Map>("Squar");


	SetSquar(Squar1,12,10);
	SetSquar(Squar2,12,11);
	SetSquar(Squar3,12,12);
	SetSquar(Squar4,13,10);	
	SetSquar(Squar5,13,12);
	
	SetSquar(Squar6,14,10);
	SetSquar(Squar7,14,11);
	SetSquar(Squar8,14,12);
	SetSquar(Squar9,15,10);	
	SetSquar(Squar10,15,11);
	
	SetSquar(Squar11,15,12);
	SetSquar(Squar12,16,10);
	SetSquar(Squar13,16,11);
	SetSquar(Squar14,16,12);	
	SetSquar(Squar15,18,10);
	
	SetSquar(Squar16,18,11);
	SetSquar(Squar17,18,12);
	SetSquar(Squar18,19,10);
	SetSquar(Squar19,19,11);	
	SetSquar(Squar20,19,12);
	
	SetSquar(Squar21,20,10);
	SetSquar(Squar22,20,11);
	SetSquar(Squar23,20,12);
	SetSquar(Squar24,21,10);	
	SetSquar(Squar25,21,12);

	SetSquar(Squar26,22,10);
	SetSquar(Squar27,22,11);
	SetSquar(Squar28,22,12);

}


void Stage0::SetSquar(std::shared_ptr<Map> _Squar,float _x,float _y)
{
	_Squar->SetActorLocation({ TileSize * (_x+0.5f), -TileSize * (_y+0.5f), 0.0f });
	_Squar->Renderer->ChangeAnimation("Squar");
	_Squar->SetActorScale3D({ 35.0f,35.0f });
}