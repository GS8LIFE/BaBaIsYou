#include "Tile.h"

void Tile::BeginPlay()
{
	Super::BeginPlay();
	TileSize = helper::TileSize;


	Renderer->CreateAnimation("TextBaba", "textbaba", 0.2f);
	Renderer->CreateAnimation("TextIs", "textis", 0.2f);
	Renderer->CreateAnimation("TextYou", "textyou", 0.2f);
	Renderer->CreateAnimation("TextMelt", "textMelt", 0.2f);
	Renderer->CreateAnimation("00", "01.png", 0.2f);

	SetActorScale3D(FVector(36.0f, 36.0f, -100.0f));
	Renderer->ChangeAnimation("TextBaba");	
}