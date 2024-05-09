#pragma once
#include "PreCompile.h"
#include "Map.h"
#include <EngineCore/GameMode.h>
#include "ContentsConstValue.h"

class APlayer;

// Ό³Έν :
class Stage0 : public AGameMode, public helper
{
	GENERATED_BODY(AGameMode)
	friend APlayer;
public:
	// constrcuter destructer
	Stage0();
	~Stage0();

	// delete Function
	Stage0(const Stage0& _Other) = delete;
	Stage0(Stage0&& _Other) noexcept = delete;
	Stage0& operator=(const Stage0& _Other) = delete;
	Stage0& operator=(Stage0&& _Other) noexcept = delete;
	void RokcTile();
	void RuleTile();
	void SquarTile();
	void WallTile();
	void RuleCheck();
	void SetTile(std::shared_ptr<Tile> _Tile, std::string _Name, float _x, float _y);
	void SetRock(std::shared_ptr<APlayer> _Squar, float _x, float _y);
	void SetWall(std::shared_ptr<APlayer> _Wall, float _x, float _y);
	void SetSquar(std::shared_ptr<Map> _Squar,float _x,float _y);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

