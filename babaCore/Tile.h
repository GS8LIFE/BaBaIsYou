#pragma once
#include "PreCompile.h"
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include "Map.h"
// Ό³Έν :
class Tile : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	Tile();
	~Tile();

	void MoveBase(float _DeltaTime);
	// delete Function
	Tile(const Tile& _Other) = delete;
	Tile(Tile&& _Other) noexcept = delete;
	Tile& operator=(const Tile& _Other) = delete;
	Tile& operator=(Tile&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	float TileSize = 0.0f;
private:
	std::map<__int64, std::vector<char>> Tilemap;

	bool IsMove = false;
};

