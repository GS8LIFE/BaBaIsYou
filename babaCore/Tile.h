#pragma once
#include "PreCompile.h"
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsConstValue.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "map"
// ���� :

class Tile : public AActor , public helper
{
	friend APlayer;
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	Tile();
	~Tile();
	void NounCheck(bool _Noun);
	void VerbCheck(bool _Verb);
	void ObjectCheck(bool _Object);
	void TileTypeCheck(bool _Noun, bool _Verb,bool _Object);
	void CreateChar();
	bool MoveActive = false;
	void move(float _DeltaTime);
	void MoveBase(float _DeltaTime);
	void setTileType(TileType _Type);
	static bool containsString(const std::vector<std::string>& strings, const std::string& target); // �ش��ϴ� ���ڰ� �ִ��� Ȯ��
	// delete Function
	Tile(const Tile& _Other) = delete;
	Tile(Tile&& _Other) noexcept = delete;
	Tile& operator=(const Tile& _Other) = delete;
	Tile& operator=(Tile&& _Other) noexcept = delete;
	void setTileMap(int _a,int _b,std::string _c);
	std::string GetTileName();
	
	void SetMove(bool _SetMove);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	float TileSize = 0.0f;
private:
	std::string Type;
	float MoveTime = 0.0f;
	const float MoveTimeWeight = 0.01f;
	void MoveOneBlock(float _DeltaTime, FVector _MoveDir);
	USpriteRenderer* Renderer;
	void DebugMessageFunction();
	std::map<int, std::vector<char>> Grid;
	FVector MoveDir = FVector::Zero;
	std::string TileName;
	bool IsMove = false;
	bool Numb = false;
	bool Verb = false;
	bool Object = false;
};

