#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/EngineDebugMsgWindow.h>

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
		MoveTime += _DeltaTime + MoveTimeWeight;
		FVector CurLocation = GetActorLocation();

		FVector NextPos = FVector::LerpClamp(CurLocation, _MoveDir, MoveTime);
		SetActorLocation(NextPos);

		if (MoveTime >= 1.0f)
		{
			Tile::SetMove(false);
			MoveTime = 0.0f;
			MoveDir = FVector::Zero;
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
	SetActorLocation(FVector(-612.0f, 342.0f, 0.0f));
	Renderer->ChangeAnimation("Dmove0");
	// 내부에서 샘플러도 같이 찾을
	Renderer->SetOrder(5);
	StateInit();
}

void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	MoveOneBlock(_DeltaTime, MoveDir);
	DebugMessageFunction();
}
void APlayer::DebugMessageFunction()
{
	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MoveTime : {}\n", MoveTime);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MoveTime : {}\n", helper::IsMove);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}
