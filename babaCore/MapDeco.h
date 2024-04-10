#pragma once
#include "PreCompile.h"
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class MapDeco : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	MapDeco();
	~MapDeco();

	// delete Function
	MapDeco(const MapDeco& _Other) = delete;
	MapDeco(MapDeco&& _Other) noexcept = delete;
	MapDeco& operator=(const MapDeco& _Other) = delete;
	MapDeco& operator=(MapDeco&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* Renderer = nullptr;
};

