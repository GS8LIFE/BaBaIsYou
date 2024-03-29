#include "PreCompile.h"
#include "babaCore.h"
#include "PlayGameMode.h"
babaCore::babaCore()
{
}

babaCore::~babaCore()
{
}

void babaCore::Initialize()
{
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");
}