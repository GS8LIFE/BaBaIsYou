#pragma once
#include "PreCompile.h"
#include <EngineCore/GameMode.h>
#include "ContentsConstValue.h"

// Ό³Έν :
class Stage0 : public AGameMode, public helper
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	Stage0();
	~Stage0();

	// delete Function
	Stage0(const Stage0& _Other) = delete;
	Stage0(Stage0&& _Other) noexcept = delete;
	Stage0& operator=(const Stage0& _Other) = delete;
	Stage0& operator=(Stage0&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

