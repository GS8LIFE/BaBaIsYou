#pragma once
#include "PreCompile.h"
#include <EngineCore/Actor.h>
#include "ContentsConstValue.h"
#include "PlayGameMode.h"
#include "Tile.h"
#include "vector"
#include "string"
#include <EngineCore/StateManager.h>

// ���� :
class USpriteRenderer;
class APlayer : public AActor , public helper 
{
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

	static std::vector<std::pair<int,int>> visitTile;
	int TileStack(std::vector<std::string> _strings, std::string _text);
	int texterase(std::vector<std::string> _strings, std::string _text);
	void setTileMap(int _a, int _b,std::string _c);
	bool TileAttribute(const std::string& _TileName,std::string _Attribute);
	void PushState(int _Column, int _Row, int _stack,std::string _Dir,char _Dir2); //_Dir -> ���� ���� Dir2 -> +�Ұ��� -�Ұ���
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
	//�����Լ�
	void StateInit();
	float TileSize = helper::TileSize;
	bool MoveActive = false;
	void Idle(float _DeltaTime);
	void moveStart();
	void move(float _DeltaTime);
	int movestack = 0; // ������ Ƚ��
	static char NowDir;
};

