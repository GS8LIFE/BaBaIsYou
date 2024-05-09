#pragma once
#include "PreCompile.h"
#include <EngineCore/Actor.h>
#include "ContentsConstValue.h"
#include "PlayGameMode.h"
#include "Tile.h"
#include "vector"
#include "string"
#include "fade.h"
#include <EngineCore/StateManager.h>
class Stage0;
// ���� :
class USpriteRenderer;
class APlayer : public AActor , public helper
{
	GENERATED_BODY(AActor)
	friend Stage0;
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

	static std::vector<std::tuple<int,int,int>> visitTile;
	int TileStack(std::vector<std::string> _strings, std::string _text);
	std::string GetName();
	bool ContainString(std::vector<std::string> _strings, std::string _text);
	void setTileMap(int _y, int _x, std::string _c);
	void setTileMap(int _y, int _x,int _y2,int _x2,std::string _c);
	bool TileAttribute(const std::string& _TileName,std::string _Attribute);
	void AnimationCollect();
	void PushState(int _Column, int _Row, int _stack,std::string _Dir,char _Dir2); //_Dir -> ���� ���� Dir2 -> +�Ұ��� -�Ұ���
	void PlayerOrObject();
	void SetPlayer(bool _Player)
	{
		IsPlayer = _Player; 
	}
	void Pop_text(std::vector<std::string>& _Tile);
	void TilePop_text(std::vector<std::string>& _Tile);
	bool NotContainString(int _y,int _x,std::string _string);
	bool equalContainString(int _y, int _x, std::string _string);
	std::string earse_Text(const std::string& strings, std::vector<std::string> target);
	std::string earse_Text(const std::string& strings, std::string target);
	std::string earse_Text(const std::vector<std::string>& strings, std::string target);
	std::string GetRule(const std::string& strings, std::vector<std::string> target);
	std::string Checkearse_Text(const std::string& strings, std::vector<std::string> target);
	int isTile(int _x,int _y);
	bool PlayerCheck(const std::string& strings, std::string target);
	std::string texterase(std::string _text);
	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void PlayerChecker();
	void RuleChecker();

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
	void Actmove(float _DeltaTime);
	int movestack = 0; // ������ Ƚ��
	bool IsPlayer = false;
	static char NowDir;
	std::string CharName = "Cursor";
	int TileY = 0;
	int TileX = 0;
	int high = 0;
	int prehigh = 0;
	bool IsMove = false;
	std::string ActorRule;
};

