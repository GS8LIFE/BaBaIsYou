#include "PreCompile.h"
#include "Stage0.h"
#include "Map.h"
#include "fade.h"
#include <EngineCore/Camera.h>
#include "Player.h"

Stage0::Stage0() 
{
	for (size_t YY = 0; YY < 19; YY++)
	{
		for (size_t XX = 0; XX < 34; XX++)
		{
			{
				Tilemap[YY][XX].push_back("");
			}
		}
	}

	for (int t = 0; t < 20; t++)   //타일맵 초기화 가로35,세로20
	{
		if (t == 0 || t == 19)
		{
			for (int i = 0; i < 35; ++i)
			{
				Tilemap[t][i].push_back("/");
			}
		}
		else {
			for (int i = 0; i < 1; ++i)
			{
				Tilemap[t][i].push_back("/");
			}
			for (int i = 6; i < 34; ++i)
			{
				Tilemap[t][i].push_back("");
			}
			for (int i = 34; i < 35; ++i)
			{
				Tilemap[t][i].push_back("/");
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
	RokcTile();
	RuleTile();
	std::shared_ptr<Map> Mapback = GetWorld()->SpawnActor<Map>("Mapback");


	fadeout->Renderer->ChangeAnimation("fadeOut");
	fadeout->SetActorLocation({ 630.0f, -360.0f, 0.0f });
	fadeout->Level = 0;
	fadeout->Renderer->ChangeAnimation("fadeOut");

	Mapback->Renderer->ChangeAnimation("MapBack");
	Mapback->SetActorLocation({ 630.0f, -360.0f, 0.0f });

	Player->SetActorLocation({ TileSize * 13.5f, -TileSize * 11.5f, 0.0f });     // 18,-18이 0,0 이미지 위치임
	Player->SetActorScale3D({35.0f,35.0f,30.0f});
	Player->setTileMap(Player->GetActorLocation().Y / TileSize, Player->GetActorLocation().X / TileSize, "BabaDmove0");

	
}
void Stage0::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	RuleCheck();
	int a = 0;
}

void Stage0::RokcTile()
{
	std::shared_ptr<APlayer> rock1 = GetWorld()->SpawnActor<APlayer>("rock");
	std::shared_ptr<APlayer> rock2 = GetWorld()->SpawnActor<APlayer>("rock");
	std::shared_ptr<APlayer> rock3 = GetWorld()->SpawnActor<APlayer>("rock");
	SetRock(rock1, 17, 10);
	SetRock(rock2, 17, 11);
	SetRock(rock3, 17, 12);
}

void Stage0::RuleTile()
{
	std::shared_ptr<Tile> Tilebaba = GetWorld()->SpawnActor<Tile>("Tilebaba");
	std::shared_ptr<Tile> Tileis = GetWorld()->SpawnActor<Tile>("Tileis");
	std::shared_ptr<Tile> TileYou = GetWorld()->SpawnActor<Tile>("Tileyou");
	SetTile(Tilebaba,"TextBaba", 12, 7);
	SetTile(Tileis,"TextIs", 13, 7);
	SetTile(TileYou,"TextYou", 14, 7);
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

void Stage0::SetTile(std::shared_ptr<Tile> _Tile,std::string _Name,float _x,float _y)
{
	_Tile->setTileMap(-(_y + 0.5f) , (_x + 0.5f), _Name);
	_Tile->SetActorLocation({ TileSize * (_x + 0.5f), -TileSize * (_y + 0.5f), 0.0f });
	_Tile->SetActorScale3D({ 35.0f,35.0f });
}
void Stage0::SetRock(std::shared_ptr<APlayer> _Rock, float _x, float _y)
{
	_Rock->SetActorLocation({ TileSize * (_x + 0.5f), -TileSize * (_y + 0.5f), 0.0f });
	_Rock->SetActorScale3D({ 35.0f,35.0f });
	_Rock->setTileMap(_Rock->GetActorLocation().Y / TileSize, _Rock->GetActorLocation().X / TileSize, "Rock");
	_Rock->InputOff();
}

void Stage0::RuleCheck()
{
	if (Tile::containsString(Rule, "BabaIsYou"))
	{
		int a = 0;
	}
}