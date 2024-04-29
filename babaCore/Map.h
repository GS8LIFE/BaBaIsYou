#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class Map : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	Map();
	~Map();

	// delete Function
	Map(const Map& _Other) = delete;
	Map(Map&& _Other) noexcept = delete;
	Map& operator=(const Map& _Other) = delete;
	Map& operator=(Map&& _Other) noexcept = delete;

	USpriteRenderer* Renderer = nullptr;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};

