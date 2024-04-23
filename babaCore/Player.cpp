#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/EngineDebugMsgWindow.h>
char APlayer::NowDir;
std::vector<std::pair<int, int>> APlayer::visitTile;

APlayer::APlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	SetRoot(Root);
	InputOn();
}

void APlayer::MoveOneBlock(float _DeltaTime, FVector _MoveDir)
{
	if(MoveActive == true)
	{ 
		InputOff();
		MoveTime += _DeltaTime + MoveTimeWeight;
		FVector CurLocation = GetActorLocation();

		FVector NextPos = FVector::LerpClamp(CurLocation, _MoveDir, MoveTime);
		SetActorLocation(NextPos);

		if (MoveTime >= 1.0f)
		{
			MoveTime = 0.0f;
			MoveDir = FVector::Zero; 
			InputOn();
			MoveActive = false;
		}
	}
}
APlayer::~APlayer()
{


}

void APlayer::setTileMap(int _a, int _b,std::string _c)
{
	Tilemap[_a][_b] = _c;
}
void APlayer::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Dmove0", "baba", 0.2f, true, 0, 2);
	Renderer->CreateAnimation("Dmove1", "baba", 0.2f, true, 3, 5);
	Renderer->CreateAnimation("Dmove2", "baba", 0.2f, true, 6, 8);
	Renderer->CreateAnimation("Dmove3", "baba", 0.2f, true, 9, 11);
	Renderer->CreateAnimation("Wmove0", "baba", 0.2f, true, 12, 14);
	Renderer->CreateAnimation("Wmove1", "baba", 0.2f, true, 15, 17);
	Renderer->CreateAnimation("Wmove2", "baba", 0.2f, true, 18, 20);
	Renderer->CreateAnimation("Wmove3", "baba", 0.2f, true, 21, 23);
	Renderer->CreateAnimation("Amove0", "baba", 0.2f, true, 30, 32);
	Renderer->CreateAnimation("Amove1", "baba", 0.2f, true, 33, 35);
	Renderer->CreateAnimation("Amove2", "baba", 0.2f, true, 36, 38);
	Renderer->CreateAnimation("Amove3", "baba", 0.2f, true, 39, 41);
	Renderer->CreateAnimation("Smove0", "baba", 0.2f, true, 45, 47);
	Renderer->CreateAnimation("Smove1", "baba", 0.2f, true, 48, 50);
	Renderer->CreateAnimation("Smove2", "baba", 0.2f, true, 51, 53);
	Renderer->CreateAnimation("Smove3", "baba", 0.2f, true, 54, 56);
	SetActorScale3D(FVector(36.0f, 36.0f, -100.0f));
	SetActorLocation(FVector(612.0f, 342.0f, 0.0f));
	Renderer->ChangeAnimation("Dmove0");
	// ���ο��� ���÷��� ���� ã��
	Renderer->SetOrder(5);
	StateInit();
}

bool APlayer::TileAttribute(const std::string& _TileName, std::string _Attribute)
{
	return _TileName.find(_Attribute) != std::string::npos;
}

void APlayer::PushState(int _Column,int _Row,int _stack,std::string _Dir,char _Dir2)
{
	
	if(_Dir2 == '+')
	{ 
	if (_Dir == "Column")
	{
		Tilemap[_Column + _stack + 2][_Row] = Tilemap[_Column + _stack +1][_Row];
		if (_stack != -1)
		{
			visitTile.push_back(std::make_pair(_Column + _stack + 1, _Row));
		}
	}
	else if(_Dir == "Row")
	{
		Tilemap[_Column][_Row + _stack + 2] = Tilemap[_Column][_Row + _stack +1];
		if (_stack != -1) {
			visitTile.push_back(std::make_pair(_Column, _Row + _stack + 1));
		}
	}
	else
	{
		MsgBoxAssert("Ǫ���۾� �� ���� ���θ� �߸� �������ϴ�.���δ� Column ���δ� Row�� �����ֱ� �ٶ��ϴ�.");
	}
	}
	else if (_Dir2 == '-')
	{
		if (_Dir == "Column")
		{
			Tilemap[_Column - _stack - 2][_Row] = Tilemap[_Column - _stack - 1][_Row];
			if (_stack != -1) {
				visitTile.push_back(std::make_pair(_Column - _stack - 1, _Row));
			}
		}
		else if (_Dir == "Row")
		{
			Tilemap[_Column][_Row - _stack - 2] = Tilemap[_Column][_Row - _stack-1];
			if (_stack != -1) {
				visitTile.push_back(std::make_pair(_Column, _Row - _stack - 1));
			}
		}
		else
		{
			MsgBoxAssert("Ǫ���۾� �� ���� ���θ� �߸� �������ϴ�.���δ� Column ���δ� Row�� �����ֱ� �ٶ��ϴ�.");
		}
	}
	else
	{
		MsgBoxAssert("������ +�������� -�������� ����� �����ֽʽÿ�.");
	}
}
void APlayer::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	MoveOneBlock(_DeltaTime, MoveDir);
	DebugMessageFunction();
}
void APlayer::DebugMessageFunction()
{
	int TileY = 0;
	int TileX = 0;

	if (GetActorLocation().Y < 0)
	{
		TileY = -GetActorLocation().Y/TileSize;
	}
	if (GetActorLocation().X > 0)
	{
		TileX = GetActorLocation().X/TileSize;
	}
	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("Location : {},{}\n", TileX,TileY);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("Name : {}\n", Tilemap[TileY][TileX]);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("------------------------------");
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}
