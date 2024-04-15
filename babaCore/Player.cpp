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
			MoveTime = 0.0f;
			MoveDir = FVector::Zero;
			MoveActive = false;
		}
	}
}
APlayer::~APlayer()
{


}

void APlayer::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("baba", "baba", 0.2f,true,0,2);
	Renderer->CreateAnimation("move", "baba", 0.2f, true, 3, 5);
	Renderer->CreateAnimation("move1", "baba", 0.2f, true, 6, 8);
	Renderer->CreateAnimation("move2", "baba", 0.2f, true, 9, 11);
	SetActorScale3D(FVector(32.0f, 32.0f, -100.0f));
	SetActorLocation(FVector(-612.0f, 342.0f, 0.0f));
	Renderer->ChangeAnimation("baba");
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

}
