#pragma once
#include "PreCompile.h"
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsConstValue.h"
#include "PlayGameMode.h"
#include "map"
// 설명 :

class Tile : public AActor , public helper
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	Tile();
	~Tile();
	void TileCheck();
	void CreateChar();
	bool MoveActive = false;
	void move(float _DeltaTime);
	void MoveBase(float _DeltaTime);
	void setTileType(TileType _Type);
	static bool containsString(const std::vector<std::string>& strings, const std::string& target); // 해당하는 문자가 있는지 확인
	// delete Function
	Tile(const Tile& _Other) = delete;
	Tile(Tile&& _Other) noexcept = delete;
	Tile& operator=(const Tile& _Other) = delete;
	Tile& operator=(Tile&& _Other) noexcept = delete;
	void setTileMap(int _a,int _b,std::string _c);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	float TileSize = 0.0f;
private:
	int Type;
	float MoveTime = 0.0f;
	const float MoveTimeWeight = 0.01f;
	void MoveOneBlock(float _DeltaTime, FVector _MoveDir);
	USpriteRenderer* Renderer;
	std::map<int, std::vector<char>> Grid;
	FVector MoveDir = FVector::Zero;
	std::string TileName;
};

