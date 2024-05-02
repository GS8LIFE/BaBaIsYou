#include "PreCompile.h"
#include "Player.h"
#include "fade.h"
#include "Tile.h"
#include "Stage0.h"
#include "Stage1.h"
#include <EngineCore/SpriteRenderer.h>



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
	State.ChangeState("move");
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
	if(CharName != "Cursor")
	{ 
	if (movestack >= 4)
	{
		movestack = 0;
	}
	switch (movestack)
	{
	case 0:
		if (NowDir == 'D')
		{
			CharName = "BabaDmove0";
			return;
		}
		if (NowDir == 'A')
		{
			CharName = "BabaAmove0";
			return;
		}
		if (NowDir == 'S')
		{
			CharName = "BabaSmove0";
			return;
		}
		if (NowDir == 'W')
		{
			CharName = "BabaWmove0";
			return;
		}
		break;
	case 1:
		if (NowDir == 'D')
		{
			CharName = "BabaDmove1";
			return;
		}
		if (NowDir == 'A')
		{
			CharName = "BabaAmove1";
			return;
		}
		if (NowDir == 'S')
		{
			CharName = "BabaSmove1";
			return;
		}
		if (NowDir == 'W')
		{
			CharName = "BabaWmove1";
			return;
		}
		break;
	case 2:
		if (NowDir == 'D')
		{
			CharName = "BabaDmove2";
			return;
		}
		if (NowDir == 'A')
		{
			CharName = "BabaAmove2";
			return;
		}
		if (NowDir == 'S')
		{
			CharName = "BabaSmove2";
			return;
		}
		if (NowDir == 'W')
		{
			CharName = "BabaWmove2";
			return;
		}
		break;	
	case 3:
		if (NowDir == 'D')
		{
			CharName = "BabaDmove3";
			return;
		}
		if (NowDir == 'A')
		{
			CharName = "BabaAmove3";
			return;
		}
		if (NowDir == 'S')
		{
			CharName = "BabaSmove3";
			return;
		}
		if (NowDir == 'W')
		{
			CharName = "BabaWmove3";
			return;
		}
		break;
	default:
		break;
	}
	}
}

void APlayer::move(float _DeltaTime)
{
	int Column = (-GetActorLocation().Y / TileSize);
	int Row = (GetActorLocation().X / TileSize);
	//if (true == Renderer->IsCurAnimationEnd())
	//{
	//	int a = 0;
	//}
	if (CharName == "Cursor" && IsUp(VK_SPACE))
	{
		switch (TileY)
		{
		case 16:
			switch (TileX)
			{
			case 10:
			{
				helper::StageLevel = 0;
				GEngine->CreateLevel<Stage0>("stage0");
				InputOff();
				break;
			}
			default:
				break;
			}
			break;
		case 14:
			switch (TileX)
			{
			case 11:
			{
			}
				break;
			case 12:
				GEngine->ChangeLevel("");
				break;
			default:
				break;
			}
			break;
		case 13:
			switch (TileX)
			{
			case 11:
				GEngine->ChangeLevel("");
				break;
			case 12:
				GEngine->ChangeLevel("");
				break;
			case 13:
				GEngine->ChangeLevel("");
				break;
			default:
				break;
			}
			break;
		case 12:
			switch (TileX)
			{
			case 11:
				GEngine->ChangeLevel("");
				break;
			case 12:
				GEngine->ChangeLevel("");
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	if (true == IsUp('A') && Row != 0)
	{
		NowDir = 'A';
		int stack = 0;
		if (CharName == "Cursor")
		{	
			if (Tilemap[Column][Row - 1][1] != "/") //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
			{
				{
					MoveActive = true;
					MoveDir = GetActorLocation();
					MoveDir += {-TileSize, 0.0f};
					State.ChangeState("move");
					setTileMap(-Column, Row - 1, CharName);
					Pop_text(Tilemap[Column][Row]);
					movestack++;
				}
			}
			return;
		}
		if (Tilemap[Column][Row - 1][1] == "") //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
		{
			{
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {-TileSize, 0.0f};
				State.ChangeState("move");
				setTileMap(-Column,Row - 1, CharName);
				Pop_text(Tilemap[-Column][Row]);
				movestack++;
			}
		}
		else if (Tile::containsString(helper::AllTile, Tilemap[Column][Row - 1][1]))
			//Tilemap[GetActorLocation().Y/TileSize][(GetActorLocation().X / TileSize) + 1] << 현재 엑터의 오른쪽을 체크
		{
			while (Tilemap[Column][Row - (stack + 2)][1] != "")
			{
				if (Tilemap[Column][Row - (stack + 2)][1] == "/")
				{
					return;
				}
				stack++;
			}
			while (stack >= -1)
			{
				PushState(-Column, Row, stack, "Row", '-');
				stack--;
			}
			MoveActive = true;
			MoveDir = GetActorLocation();
			MoveDir += {-TileSize, 0.0f};
			State.ChangeState("move");
			movestack++;
		}
	}
	if (true == IsUp('D') && Row != 34)
	{
		NowDir = 'D';
		int stack = 0;
		if (CharName == "Cursor")
		{
			if (ContainString(Column,Row+1, "/")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
			{
				{
					MoveActive = true;
					MoveDir = GetActorLocation();
					MoveDir += {TileSize, 0.0f};
					State.ChangeState("move");
					setTileMap(-Column,Row + 1,CharName);
					Pop_text(Tilemap[Column][Row]);
					movestack++;
				}
			}
			return;
		}
		if (Tilemap[Column][Row + 1][1] == "") //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
		{
			{
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {TileSize, 0.0f};
				State.ChangeState("move");
				setTileMap(-Column,Row + 1,CharName);
				Pop_text(Tilemap[Column][Row]);
				movestack++;
			}
		}
		else if (Tile::containsString(helper::AllTile, Tilemap[Column][Row+1][1]))
			//Tilemap[GetActorLocation().Y/TileSize][(GetActorLocation().X / TileSize) + 1] << 현재 엑터의 오른쪽을 체크
		{
			while (Tilemap[Column][Row + (stack+2)][1] != "")
			{
				if (Tilemap[Column][Row + (stack + 2)][1] == "/")
				{
					return;
				}
				stack++;
			}
			while (stack >= -1)
			{
				PushState(-Column, Row, stack, "Row", '+');
				stack--;
			} 
			MoveActive = true;
			MoveDir = GetActorLocation();
			MoveDir += {TileSize, 0.0f};
			State.ChangeState("move");
			movestack++;
		}
	}
	if (true == IsUp('W') && Column != 0)
	{
		NowDir = 'W';
		int stack = 0;
		if (CharName == "Cursor")
		{
			if (Tilemap[Column - 1][Row][1] != "/") //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
			{
				{
					MoveActive = true;
					MoveDir = GetActorLocation();
					MoveDir += {0.0f,TileSize};
					State.ChangeState("move");
					setTileMap(-(Column - 1),Row,CharName);
					Pop_text(Tilemap[Column][Row]);
					movestack++;
				}
			}
			return;
		}
		if (Tilemap[Column - 1][Row][1] == "") //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
		{
			{
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {0.0f, TileSize};
				State.ChangeState("move");
				setTileMap(-(Column - 1), Row, CharName);
				Pop_text(Tilemap[Column][Row]);
				movestack++;
			}
		}
		else if (APlayer::ContainString(helper::AllTile, Tilemap[Column-1][Row][0]))
			//Tilemap[GetActorLocation().Y/TileSize][(GetActorLocation().X / TileSize) + 1] << 현재 엑터의 오른쪽을 체크
		{
			while (Tilemap[Column - (stack + 2)][Row][0] != "")
			{
				if (Tilemap[Column - (stack + 2)][Row][0] == "/")
				{
					return;
				}
				stack++;
			}
			while (stack >= -1)
			{
				PushState(-Column, Row, stack, "Column", '-');
				stack--;
			}
			MoveActive = true;
			MoveDir = GetActorLocation();
			MoveDir += {0.0f, TileSize};
			State.ChangeState("move");

			movestack++;
		}
	}
	if (true == IsUp('S') && Column != 19)
	{
		NowDir = 'S';
		int stack = 0;
		if (CharName == "Cursor")
		{
			if (Tilemap[Column + 1][Row][1] != "/") //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
			{
				{
					MoveActive = true;
					MoveDir = GetActorLocation();
					MoveDir += {0.0f,-TileSize};
					State.ChangeState("move");
					setTileMap(-(Column + 1),Row,CharName);
					Pop_text(Tilemap[Column][Row]);
					movestack++;
				}
			}
			return;
		}
		if (Tilemap[Column + 1][Row][1] == "") //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
		{
			{
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {0.0f, -TileSize};
				State.ChangeState("move");
				setTileMap(-(Column + 1),Row,CharName);
				Pop_text(Tilemap[Column][Row]);
				movestack++;
			}
		}
		else if (APlayer::ContainString(helper::AllTile, Tilemap[Column + 1][Row][0]))
			//Tilemap[GetActorLocation().Y/TileSize][(GetActorLocation().X / TileSize) + 1] << 현재 엑터의 오른쪽을 체크
		{
			while (Tilemap[Column + (stack + 2)][Row][0] != "")
			{
				if (Tilemap[Column + (stack + 2)][Row][0] == "/")
				{
					return;
				}
				stack++;
			}
			while (stack >= -1)
			{
				PushState(-Column, Row, stack, "Column", '+');
				stack--;
			}
			MoveActive = true;
			MoveDir = GetActorLocation();
			MoveDir += {0.0f, -TileSize};
			State.ChangeState("move");

			movestack++;
		}
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
