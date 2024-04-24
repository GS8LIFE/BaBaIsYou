#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// Ό³Έν :
class fade : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	fade();
	~fade();

	// delete Function
	fade(const fade& _Other) = delete;
	fade(fade&& _Other) noexcept = delete;
	fade& operator=(const fade& _Other) = delete;
	fade& operator=(fade&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
};

