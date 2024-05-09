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
void APlayer::setTileMap(int _y, int _x, std::string _c)
{
	prehigh = high;
	high = Tilemap[-_y][_x].size();
	Tilemap[-_y][_x].push_back(_c);
	CharName = _c;
}
void APlayer::setTileMap(int _y, int _x,int _y2,int _x2,std::string _c)
{
	prehigh = high;
	high = Tilemap[-_y][_x].size();
	if (Tile::containsString(helper::AllTile,Tilemap[_y2][_x2]))
	{
		Tilemap[-_y][_x][0]=(_c);
	}
	else
	{
		Tilemap[-_y][_x].push_back(_c);
	}
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
void APlayer::PlayerOrObject()
{
		if (IsPlayer)
		{
			State.ChangeState("move");
		}
		else
		{
			State.ChangeState("Actmove");
		}
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

std::string APlayer::texterase(std::string _text)
{
	std::string erasetext = "Text";

	int pos = _text.find(erasetext);
	if (pos != std::string::npos)
	{
		return _text.erase(pos, erasetext.length());
	}
}

std::string APlayer::earse_Text(const std::string& strings, std::vector<std::string> target) {
	for (auto tag : target)
	{
		auto it = std::search(strings.begin(), strings.end(), tag.begin(), tag.end());
		if (it != strings.end())
		{
			return tag;
		}
	}
	return strings;
}

std::string APlayer::Checkearse_Text(const std::string& strings, std::vector<std::string> target) {
	for (auto tag : target)
	{
		tag = texterase(tag);
		auto it = std::search(strings.begin(), strings.end(), tag.begin(), tag.end());
		if (it != strings.end())
		{
			return tag;
		}
	}
	return strings;
}

std::string APlayer::earse_Text(const std::string& strings, std::string target) {
	
		auto it = std::search(strings.begin(), strings.end(), target.begin(), target.end());
		if (it != strings.end())
		{
			return target;
		}
	return strings;
}

std::string APlayer::earse_Text(const std::vector<std::string>& strings, std::string target) {
	for (auto tag : strings)
	{
		auto it = std::search(tag.begin(), tag.end(), target.begin(), target.end());
		if (it != tag.end())
		{
			return tag;
		}
	}
	return target;
}
bool APlayer::PlayerCheck(const std::string& strings, std::string target) {

	auto it = std::search(strings.begin(), strings.end(), target.begin(), target.end());
	if (it != strings.end())
	{
		return true;
	}
	return false;
}

std::string APlayer::GetRule(const std::string& strings, std::vector<std::string> target){
	ActorRule.clear();
	for (auto tag : target)
	{
		auto it = std::search(strings.begin(), strings.end(), tag.begin(), tag.end());
		if (it != strings.end())
		{
			ActorRule += tag;
		}
	}
	return ActorRule;
}

int APlayer::isTile(int _x,int _y)
{
	if (Tile::containsString(helper::AllTile, Tilemap[_y][_x]))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void APlayer::PushState(int _Column,int _Row,int _stack,std::string _Dir,char _Dir2)
{
	
	if(_Dir2 == '+')
	{ 
	if (_Dir == "Column")
	{
		setTileMap(-(_Column + _stack + 2), _Row , _Column + _stack + 1, _Row , Tilemap[_Column + _stack + 1][_Row ][isTile(_Row, _Column + _stack + 1)]);
		if (_stack != -1)
		{
			visitTile.push_back(std::make_tuple(_Column + _stack + 1, _Row , 0));
		}
		if (Tile::containsString(helper::AllTile, Tilemap[_Column + _stack + 1][_Row ]))
		{
			TilePop_text(Tilemap[_Column + _stack + 1][_Row ]);
		}
		else
		{
			Pop_text(Tilemap[_Column + _stack + 1][_Row ]);
		}
	}
	else if(_Dir == "Row")
	{
		setTileMap(-_Column, _Row + _stack + 2, _Column, _Row + _stack + 1, Tilemap[_Column][_Row + _stack + 1][isTile(_Row+_stack+1,_Column)]);
		if (_stack != -1)
		{
			visitTile.push_back(std::make_tuple(_Column, _Row + _stack + 1, 0));
		}
		if (Tile::containsString(helper::AllTile, Tilemap[_Column][_Row + _stack + 1]))
		{
			TilePop_text(Tilemap[_Column][_Row + _stack + 1]);
		}
		else
		{
			Pop_text(Tilemap[_Column][_Row + _stack + 1]);
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
			setTileMap(-(_Column - _stack - 2), _Row, _Column - _stack - 1, _Row, Tilemap[_Column - _stack - 1][_Row][isTile(_Row , _Column - _stack - 1)]);
			if (_stack != -1)
			{
				visitTile.push_back(std::make_tuple(_Column - _stack - 1, _Row, 0));
			}
			if (Tile::containsString(helper::AllTile, Tilemap[_Column - _stack - 1][_Row]))
			{
				TilePop_text(Tilemap[_Column - _stack - 1][_Row]);
			}
			else
			{
				Pop_text(Tilemap[_Column - _stack - 1][_Row]);
			}
		}
		else if (_Dir == "Row")
		{
			setTileMap(-_Column, _Row - _stack - 2, _Column, _Row - _stack - 1, Tilemap[_Column][_Row - _stack - 1][isTile(_Row - _stack - 1, _Column)]);
			if (_stack != -1)
			{
				visitTile.push_back(std::make_tuple(_Column, _Row - _stack - 1, 0));
			}
			if (Tile::containsString(helper::AllTile, Tilemap[_Column][_Row - _stack - 1]))
			{
				TilePop_text(Tilemap[_Column][_Row - _stack - 1]);
			}
			else
			{
				Pop_text(Tilemap[_Column][_Row - _stack - 1]);
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
	
void APlayer::PlayerChecker()
{
	if (CharName == "Cursor")
	{
		IsPlayer = true;
		return;
	}
	if (PlayerCheck(earse_Text(Rule, "You"), Checkearse_Text(CharName, helper::Nouns)))
	{
		IsPlayer = true;
	}
	else
	{
		IsPlayer = false;
	}
}

void APlayer::RuleChecker()
{

}

bool APlayer::NotContainString(int _y, int _x,std::string _string)
{
	bool retrunValue = true;
	bool value = false;
	for (size_t i = 0; i < Tilemap[_y][_x].size(); i++)
	{
		value = Tilemap[_y][_x][i] == _string;
		if (value == true)
		{
			return false;
		}
	}
	return retrunValue;
}

bool APlayer::equalContainString(int _y, int _x, std::string _string)
{
	bool value = false;
	if (Tilemap[_y][_x].size() == 1)
	{
		for (size_t i = 0; i < 1; i++)
		{
			value = Tilemap[_y][_x][i] == _string;
			if (value == true)
			{
				return value;
			}
		}
	}
	else
	{
		return value;
	}
	return value;
}
void APlayer::Pop_text(std::vector<std::string>& _Tile)
{
	_Tile.erase(_Tile.end() - 1);
}
void APlayer::TilePop_text(std::vector<std::string>& _Tile)
{
	_Tile[0] = " ";
}
std::string APlayer::GetName()
{
	return CharName;
}



void APlayer::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);

	PlayerChecker();
	GetRule(CharName,helper::State);

	State.Update(_DeltaTime);
	MoveOneBlock(_DeltaTime, MoveDir);
	Renderer->ChangeAnimation(earse_Text(CharName, helper::AnimationState));
	DebugMessageFunction();


	PlayerOrObject();
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
	//��
	Renderer->CreateAnimation("Wall", "Wall", 0.2f,true,0,2);
}