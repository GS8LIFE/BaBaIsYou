#include "PreCompile.h"
#include "Player.h"
#include "Tile.h"
#include <EngineCore/SpriteRenderer.h>

int movestack = 0; // 움직인 횟수

//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void APlayer::StateInit()
{
	// 스테이트 만들고
	State.CreateState("Idle");
	State.CreateState("move");

	// 함수들 세팅하고
	State.SetUpdateFunction("Idle", std::bind(&APlayer::Idle, this, std::placeholders::_1));

	// 콜백[0]  콜백[1]   콜백[2][3][4][5][6] [7] 콜백8

	//Renderer->SetFrameCallback("Run", 0, [=]
	//	{
	//		int a = 0;
	//	});


	// 즉석 함수
	// = [ 람다캡쳐 Renderer]
	// {
	//    함수 내용
	// }

	// 람다캡처의 내용안에 =을 쓰면
	// 현재 스택에서 사용가능한 복사본을 만든다.
	// 메모리를 할당해서 Renderer를 같은 이름으로 복사한다.

	State.SetStartFunction("Idle", [this]()
		{
			// this->Renderer->ChangeAnimation("Idle");
		});

	
	State.SetUpdateFunction("move", std::bind(&APlayer::move, this, std::placeholders::_1));

	State.SetStartFunction("move", std::bind(&APlayer::moveStart, this));





	// 체인지
	State.ChangeState("Idle");
}


void APlayer::Idle(float _Update)
{
	if ( true == IsDown('D'))
	{
		State.ChangeState("move");
		return;
	}
	if (true == IsDown('A'))
	{
		State.ChangeState("move");
		return;
	}
	if (true == IsDown('S'))
	{
		State.ChangeState("move");
		return;
	}
	if (true == IsDown('W'))
	{
		State.ChangeState("move");
		return;
	}
}

void APlayer::moveStart()
{
	if (movestack >= 4)
	{
		movestack = 0;
	}
	switch (movestack)
	{
	case 0:
		if (true == IsUp('D'))
		{
			Renderer->ChangeAnimation("Dmove0");
			return;
		}
		if (true == IsUp('A'))
		{
			Renderer->ChangeAnimation("Amove0");
			return;
		}
		if (true == IsUp('S'))
		{
			Renderer->ChangeAnimation("Smove0");
			return;
		}
		if (true == IsUp('W'))
		{
			Renderer->ChangeAnimation("Wmove0");
			return;
		}
		break;
	case 1:
		if (true == IsUp('D'))
		{
			Renderer->ChangeAnimation("Dmove1");
			return;
		}
		if (true == IsUp('A'))
		{
			Renderer->ChangeAnimation("Amove1");
			return;
		}
		if (true == IsUp('S'))
		{
			Renderer->ChangeAnimation("Smove1");
			return;
		}
		if (true == IsUp('W'))
		{
			Renderer->ChangeAnimation("Wmove1");
			return;
		}
		break;
	case 2:
		if (true == IsUp('D'))
		{
			Renderer->ChangeAnimation("Dmove2");
			return;
		}
		if (true == IsUp('A'))
		{
			Renderer->ChangeAnimation("Amove2");
			return;
		}
		if (true == IsUp('S'))
		{
			Renderer->ChangeAnimation("Smove2");
			return;
		}
		if (true == IsUp('W'))
		{
			Renderer->ChangeAnimation("Wmove2");
			return;
		}
		break;	
	case 3:
		if (true == IsUp('D'))
		{
			Renderer->ChangeAnimation("Dmove3");
			return;
		}
		if (true == IsUp('A'))
		{
			Renderer->ChangeAnimation("Amove3");
			return;
		}
		if (true == IsUp('S'))
		{
			Renderer->ChangeAnimation("Smove3");
			return;
		}
		if (true == IsUp('W'))
		{
			Renderer->ChangeAnimation("Wmove3");
			return;
		}
		break;
	default:
		break;
	}
}

void APlayer::move(float _DeltaTime)
{
	//if (true == Renderer->IsCurAnimationEnd())
	//{
	//	int a = 0;
	//}
	if (true == IsUp('A'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {-TileSize, 0.0f};
		State.ChangeState("move");
		movestack++;
	}
	if (Tilemap[0][1] != ' ')
	{
		if (Tilemap[0][2] != 'D') 
		{
			if (true == IsUp('D'))
			{
				Tile::SetMove(true);
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {TileSize, 0.0f};
				State.ChangeState("move");
				movestack++;
			}
		}
	}
	if (true == IsUp('W'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {0.0f, TileSize};
		State.ChangeState("move");
		movestack++;
	}

	if (true == IsUp('S'))
	{
		MoveActive = true;
		MoveDir = GetActorLocation();
		MoveDir += {0.0f, -TileSize};
		State.ChangeState("move");
		movestack++;
	}

	if (true == IsPress(VK_NUMPAD1))
	{
		// AddActorRotation(float4{0.0f, 0.0f, 1.0f} * 360.0f * _DeltaTime);
		// Color.X += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD2))
	{
		Color.X -= _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD4))
	{
		Color.Y += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD5))
	{
		Color.Y -= _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD7))
	{
		Color.Z += _DeltaTime;
	}

	if (true == IsPress(VK_NUMPAD8))
	{
		Color.Z -= _DeltaTime;
	}


	//float4 Pos = GetActorLocation();


	//Pos /= UContentsConstValue::TileSize;
	//Pos.Y = -Pos.Y;

	//Color8Bit Color = Tex->GetColor(Pos, Color8Bit::Black);

	//if (Color != Color8Bit::Black)
	//{
	//	AddActorLocation(float4::Down * _DeltaTime * 100.0f);
	//}


}
