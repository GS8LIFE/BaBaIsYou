#pragma once
#include "PreCompile.h"
#include <EngineCore/Actor.h>
#include "ContentsConstValue.h"
#include "PlayGameMode.h"
#include "Tile.h"
#include <EngineCore/StateManager.h>

// 설명 :
class USpriteRenderer;
class APlayer : public AActor , public helper 
{
	friend Tile;
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	APlayer();
	~APlayer();
	void MoveOneBlock(float _DeltaTime, FVector _MoveDir);
	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void setTileMap(int _a, int _b,std::string _c);
	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer;
	float4 Color;	
	float MoveTime = 0.0f;
	const float MoveTimeWeight = 0.01f;
	void DebugMessageFunction();
	FVector MoveDir = FVector::Zero;
	//상태함수
	void StateInit();
	float TileSize = helper::TileSize;
	bool MoveActive = false;
	void Idle(float _DeltaTime);
	void moveStart();
	void move(float _DeltaTime);
	int movestack = 0; // 움직인 횟수
};

