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
	Tilemap[-_a][_b] = _c;
	CharName = _c;
}
void APlayer::BeginPlay()
{
	Super::BeginPlay();
	AnimationCollect();
	SetActorScale3D(FVector(50.0f, 50.0f, -50.0f));
	SetActorLocation(FVector(612.0f, 342.0f, 0.0f));
	// 내부에서 샘플러도 같이 찾을
	Renderer->SetOrder(5);
	StateInit();
}

bool APlayer::TileAttribute(const std::string& _TileName, std::string _Attribute)
{
	return _TileName.find(_Attribute) != std::string::npos;
}


int APlayer::TileStack(std::vector<std::string> _strings,std::string _text)
{
	int stack = 0;
	std::string TempText = _text;
	for (std::string str : _strings)
	{
		int pos = TempText.find(str);
		if (pos != std::string::npos)
		{
			TempText.erase(pos, str.length());
			stack++;
		}
	}
	return stack;
}

bool APlayer::ContainString(std::vector<std::string> _strings, std::string _text)
{
	int stack = 0;
	std::string TempText = _text;
	for (std::string str : _strings)
	{
		int pos = TempText.find(str);
		if (pos != std::string::npos)
		{
			return true;
		}
	}
	return false;
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
			int stack = TileStack(AllTile, Tilemap[_Column + _stack + 2][_Row]);
			for (int i = 0; i < stack; i++)
			{
			visitTile.push_back(std::make_pair(_Column + _stack + 1, _Row));
			}
		}
	}
	else if(_Dir == "Row")
	{
		Tilemap[_Column][_Row + _stack + 2] = Tilemap[_Column][_Row + _stack +1];
		if (_stack != -1) {
			int stack = TileStack(AllTile, Tilemap[_Column][_Row + _stack + 2]);
			for (int i = 0; i < stack; i++)
			{
			visitTile.push_back(std::make_pair(_Column, _Row + _stack + 1));
			}
		}
	}
	else
	{
		MsgBoxAssert("푸쉬작업 중 가로 세로를 잘못 적었습니다.세로는 Column 가로는 Row로 적어주길 바랍니다.");
	}
	}
	else if (_Dir2 == '-')
	{
		if (_Dir == "Column")
		{
			Tilemap[_Column - _stack - 2][_Row] = Tilemap[_Column - _stack - 1][_Row];
			if (_stack != -1) {
				int stack = TileStack(AllTile, Tilemap[_Column - _stack - 2][_Row]);
				for (int i = 0; i < stack; i++)
				{
					visitTile.push_back(std::make_pair(_Column - _stack - 1, _Row));
				}
			}
		}
		else if (_Dir == "Row")
		{
			Tilemap[_Column][_Row - _stack - 2] = Tilemap[_Column][_Row - _stack-1];
			if (_stack != -1) {
				int stack = TileStack(AllTile, Tilemap[_Column][_Row - _stack - 2]);
				for (int i = 0; i < stack; i++)
				{
					visitTile.push_back(std::make_pair(_Column, _Row - _stack - 1));
				}
			}
		}
		else
		{
			MsgBoxAssert("푸쉬작업 중 가로 세로를 잘못 적었습니다.세로는 Column 가로는 Row로 적어주길 바랍니다.");
		}
	}
	else
	{
		MsgBoxAssert("방향이 +방향인지 -방향인지 제대로 적어주십시오.");
	}
}



void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	MoveOneBlock(_DeltaTime, MoveDir);
	Renderer->ChangeAnimation(CharName);
	DebugMessageFunction();
	

	if (GetActorLocation().Y < 0)
	{
		TileY = -GetActorLocation().Y / TileSize;
	}
	if (GetActorLocation().X > 0)
	{
		TileX = GetActorLocation().X / TileSize;
	}
}



void APlayer::AnimationCollect()
{
	//커서
	Renderer->CreateAnimation("Cursor", "Cursor", 0.2f);
	//바바
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
	//돌
		Renderer->CreateAnimation("Rock", "Rock", 0.2f);

}