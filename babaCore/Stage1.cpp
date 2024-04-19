#include "PreCompile.h"
#include "ContentsConstValue.h"
#include "Stage1.h"
Stage1::Stage1() 
{
	for (size_t YY = 0; YY < 19; YY++)
	{
		for (size_t XX = 0; XX < 34; XX++)
		{
			{
				Tilemap[YY][XX] = " ";
			}
		}
	}

	for (int t = 0; t < 20; t++)   //타일맵 초기화 가로35,세로20
	{
		if (t == 0 || t == 19)
		{
			for (int i = 0; i < 35; ++i)
			{
				Tilemap[t][i] = "/";
			}
		}
		else {
			for (int i = 0; i < 6; ++i)
			{
				Tilemap[t][i] = "/";
			}
			for (int i = 6; i < 30; ++i)
			{
				Tilemap[t][i] = " ";
			}
			for (int i = 30; i < 35; ++i)
			{
				Tilemap[t][i] = "/";
			}
		}
	}
}

Stage1::~Stage1() 
{
}

void Stage1::BeginPlay()
{


}
void Stage1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
