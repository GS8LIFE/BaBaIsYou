#pragma once
#include "PreCompile.h"
#include <EngineCore/GameMode.h>
#include "ContentsConstValue.h"

// Ό³Έν :
class Stage1 : public AGameMode, public helper
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	Stage1();
	~Stage1();

	// delete Function
	Stage1(const Stage1& _Other) = delete;
	Stage1(Stage1&& _Other) noexcept = delete;
	Stage1& operator=(const Stage1& _Other) = delete;
	Stage1& operator=(Stage1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};

