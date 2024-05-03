#pragma once
#include "PreCompile.h"
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsConstValue.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "map"
// 설명 :
class Stage0;
class Tile : public AActor , public helper
{
	GENERATED_BODY(AActor)
public:
	friend Stage0;
	// constrcuter destructer
	Tile();
	~Tile();
	void TileTypeCheck();
	void CreateChar();
	bool MoveActive = false;
	void move(float _DeltaTime);
	void TileLocation();
	void Sentence(bool _Noun);
	std::string texterase(std::string _text);
	static bool containsString(const std::vector<std::string>& strings, const std::string& target); // 해당하는 문자가 있는지 확인
	static bool containsString(const std::vector<std::string>& strings, std::vector<std::string> target); // 해당하는 문자가 있는지 확인
	static bool NotcontainsString(const std::vector<std::string>& strings, std::vector<std::string> target); // 해당하는 문자가 있는지 확인
	std::string WhatyourName(const std::vector<std::string>& strings, std::string& target); // 해당하는 문자가 있는지 확인
	// delete Functionvoid 
	void SetTileName(std::string _TileName)
	{
		TileName = _TileName;
	}
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
	bool Noun = false;
	bool Verb = false;
	bool Object = false;	
	int TileY = 0;
	int TileX = 0;
	int high = 0;
	std::string SentenceRow;
	std::string SentenceColumn;
};

