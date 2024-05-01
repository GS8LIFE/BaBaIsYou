#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/EngineDebugMsgWindow.h>
char APlayer::NowDir;
std::vector<std::tuple<int, int,int>> APlayer::visitTile;

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
	high = Tilemap[-_a][_b].size();
	Tilemap[-_a][_b].push_back(_c);
	CharName = _c;
}
void APlayer::BeginPlay()
{
	Super::BeginPlay();
	AnimationCollect();
	SetActorScale3D(FVector(50.0f, 50.0f, -50.0f));
	SetActorLocation(FVector(612.0f, 342.0f, 0.0f));
	// ���ο��� ���÷��� ���� ã��
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
		Tilemap[_Column + _stack + 2][_Row].push_back(Tilemap[_Column + _stack +1][_Row][high]);
		if (_stack != -1)
		{
			int stack = Tilemap[_Column + _stack + 2][_Row].size();
			for (int i = 0; i < stack; i++)
			{
				visitTile.push_back(std::make_tuple (_Column + _stack + 1, _Row,high));
			}
		}
	}
	else if(_Dir == "Row")
	{
		Tilemap[_Column][_Row + _stack + 2].push_back(Tilemap[_Column][_Row + _stack +1][high]);
		if (_stack != -1) {
			
			int stack = Tilemap[_Column][_Row + _stack + 2].size();
			for (int i = 0; i < stack; i++)
			{
			visitTile.push_back(std::make_tuple(_Column, _Row + _stack + 1, high));
			}
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
			int Prehigh = high;
			setTileMap(_Column - _stack - 2, _Row, Tilemap[_Column - _stack - 1][_Row][high]);
			if (_stack != -1) {
				int stack = Tilemap[_Column - _stack - 2][_Row].size();
				for (int i = 0; i < stack; i++)
				{
					visitTile.push_back(std::make_tuple(_Column - _stack - 1, _Row, Prehigh));
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

std::string APlayer::Pop_text(std::string _Tile, std::string _CharName)
{
	std::string erasetext = _CharName;

	int pos = _Tile.find(erasetext);
	if (pos != std::string::npos)
	{
		return _Tile.erase(pos, erasetext.length());
	}
}
std::string APlayer::GetName()
{
	return CharName;
}

void APlayer::AnimationCollect()
{
	//Ŀ��
	Renderer->CreateAnimation("Cursor", "Cursor", 0.2f);
	//�ٹ�
	Renderer->CreateAnimation("BabaDmove0", "baba", 0.2f, true, 0, 2);
	Renderer->CreateAnimation("BabaDmove1", "baba", 0.2f, true, 3, 5);
	Renderer->CreateAnimation("BabaDmove2", "baba", 0.2f, true, 6, 8);
	Renderer->CreateAnimation("BabaDmove3", "baba", 0.2f, true, 9, 11);
	Renderer->CreateAnimation("BabaWmove0", "baba", 0.2f, true, 12, 14);
	Renderer->CreateAnimation("BabaWmove1", "baba", 0.2f, true, 15, 17);
	Renderer->CreateAnimation("BabaWmove2", "baba", 0.2f, true, 18, 20);
	Renderer->CreateAnimation("BabaWmove3", "baba", 0.2f, true, 21, 23);
	Renderer->CreateAnimation("BabaAmove0", "baba", 0.2f, true, 30, 32);
	Renderer->CreateAnimation("BabaAmove1", "baba", 0.2f, true, 33, 35);
	Renderer->CreateAnimation("BabaAmove2", "baba", 0.2f, true, 36, 38);
	Renderer->CreateAnimation("BabaAmove3", "baba", 0.2f, true, 39, 41);
	Renderer->CreateAnimation("BabaSmove0", "baba", 0.2f, true, 45, 47);
	Renderer->CreateAnimation("BabaSmove1", "baba", 0.2f, true, 48, 50);
	Renderer->CreateAnimation("BabaSmove2", "baba", 0.2f, true, 51, 53);
	Renderer->CreateAnimation("BabaSmove3", "baba", 0.2f, true, 54, 56);
	//��
		Renderer->CreateAnimation("Rock", "Rock", 0.2f);

}