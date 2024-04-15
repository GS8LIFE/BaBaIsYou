#include "PreCompile.h"
#include "Player.h"
#include "Tile.h"
#include <EngineCore/SpriteRenderer.h>

int movestack = 0; // ������ Ƚ��

//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void APlayer::StateInit()
{
	// ������Ʈ �����
	State.CreateState("Idle");
	State.CreateState("move");

	// �Լ��� �����ϰ�
	State.SetUpdateFunction("Idle", std::bind(&APlayer::Idle, this, std::placeholders::_1));

	// �ݹ�[0]  �ݹ�[1]   �ݹ�[2][3][4][5][6] [7] �ݹ�8

	//Renderer->SetFrameCallback("Run", 0, [=]
	//	{
	//		int a = 0;
	//	});


	// �Ｎ �Լ�
	// = [ ����ĸ�� Renderer]
	// {
	//    �Լ� ����
	// }

	// ����ĸó�� ����ȿ� =�� ����
	// ���� ���ÿ��� ��밡���� ���纻�� �����.
	// �޸𸮸� �Ҵ��ؼ� Renderer�� ���� �̸����� �����Ѵ�.

	State.SetStartFunction("Idle", [this]()
		{
			// this->Renderer->ChangeAnimation("Idle");
		});

	
	State.SetUpdateFunction("move", std::bind(&APlayer::move, this, std::placeholders::_1));

	State.SetStartFunction("move", std::bind(&APlayer::moveStart, this));





	// ü����
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
