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
	State.CreateState("Actmove");

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

	State.SetUpdateFunction("Actmove", std::bind(&APlayer::Actmove, this, std::placeholders::_1));



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
	if (IsPlayer)
	{
		if (CharName != "Cursor")
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
					CharName = "BabaDmove0" + ActorRule;
					return;
				}
				if (NowDir == 'A')
				{
					CharName = "BabaAmove0" + ActorRule;
					return;
				}
				if (NowDir == 'S')
				{
					CharName = "BabaSmove0" + ActorRule;
					return;
				}
				if (NowDir == 'W')
				{
					CharName = "BabaWmove0" + ActorRule;
					return;
				}
				break;
			case 1:
				if (NowDir == 'D')
				{
					CharName = "BabaDmove1" + ActorRule;
					return;
				}
				if (NowDir == 'A')
				{
					CharName = "BabaAmove1" + ActorRule;
					return;
				}
				if (NowDir == 'S')
				{
					CharName = "BabaSmove1" + ActorRule;
					return;
				}
				if (NowDir == 'W')
				{
					CharName = "BabaWmove1" + ActorRule;
					return;
				}
				break;
			case 2:
				if (NowDir == 'D')
				{
					CharName = "BabaDmove2" + ActorRule;
					return;
				}
				if (NowDir == 'A')
				{
					CharName = "BabaAmove2" + ActorRule;
					return;
				}
				if (NowDir == 'S')
				{
					CharName = "BabaSmove2" + ActorRule;
					return;
				}
				if (NowDir == 'W')
				{
					CharName = "BabaWmove2" + ActorRule;
					return;
				}
				break;
			case 3:
				if (NowDir == 'D')
				{
					CharName = "BabaDmove3" + ActorRule;
					return;
				}
				if (NowDir == 'A')
				{
					CharName = "BabaAmove3" + ActorRule;
					return;
				}
				if (NowDir == 'S')
				{
					CharName = "BabaSmove3" + ActorRule;
					return;
				}
				if (NowDir == 'W')
				{
					CharName = "BabaWmove3" + ActorRule;
					return;
				}
				break;
			default:
				break;
			}
		}
	}
}

void APlayer::move(float _DeltaTime) {
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
				if (NotContainString(Column, Row - 1, "/")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
				{
					{
						MoveActive = true;
						MoveDir = GetActorLocation();
						MoveDir += {-TileSize, 0.0f};
						setTileMap(-Column, Row - 1, CharName);
						Pop_text(Tilemap[Column][Row]);
						movestack++;
					}
				}
				return;
			}
			if (Tile::containsString("Push", Tilemap[Column][Row - 1]))
				//Tilemap[GetActorLocation().Y/TileSize][(GetActorLocation().X / TileSize) + 1] << 현재 엑터의 오른쪽을 체크
			{
				while (Tile::containsString("Push", Tilemap[Column][Row - stack - 2]))
				{
					if (Tilemap[Column][Row + (stack + 2)][Tilemap[Column][Row + (stack + 2)].size() - 1] == "/")
					{
						return;
					}
					stack++;
				}
				while (stack >= -1)
				{
					PushState(Column, Row, stack, "Row", '-');
					stack--;
				}
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {-TileSize, 0.0f};
				PlayerOrObject();
				movestack++;
			}
			else if (NotContainString(Column, Row - 1, "Push")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
			{
				{
					MoveActive = true;
					MoveDir = GetActorLocation();
					MoveDir += {-TileSize, 0.0f};
					PlayerOrObject();
					setTileMap(-Column, Row - 1, CharName);
					Pop_text(Tilemap[Column][Row]);
					movestack++;
				}
			}
		}
		if (true == IsUp('D') && Row != 34)
		{
			NowDir = 'D';
			int stack = 0;
			if (CharName == "Cursor")
			{
				if (NotContainString(Column, Row + 1, "/")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
				{
					{
						MoveActive = true;
						MoveDir = GetActorLocation();
						MoveDir += {TileSize, 0.0f};
						State.ChangeState("move");
						setTileMap(-Column, Row + 1, CharName);
						Pop_text(Tilemap[Column][Row]);
						movestack++;
					}
				}
				return;
			}
			if (Tile::containsString("Push", Tilemap[Column][Row + 1]))
				//Tilemap[GetActorLocation().Y/TileSize][(GetActorLocation().X / TileSize) + 1] << 현재 엑터의 오른쪽을 체크
			{
				while (Tile::containsString("Push", Tilemap[Column][Row + (stack + 2)]))
				{
					if (Tilemap[Column][Row + (stack + 2)][Tilemap[Column][Row + (stack + 2)].size() - 1] == "/")
					{
						return;
					}
					stack++;
				}
				while (stack >= -1)
				{
					PushState(Column, Row, stack, "Row", '+');
					stack--;
				}
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {TileSize, 0.0f};
				State.ChangeState("move");
				movestack++;
			}
			else if (NotContainString(Column, Row + 1, "Push")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
			{
				{
					MoveActive = true;
					MoveDir = GetActorLocation();
					MoveDir += {TileSize, 0.0f};
					State.ChangeState("move");
					setTileMap(-Column, Row + 1, CharName);
					Pop_text(Tilemap[Column][Row]);
					movestack++;
				}
			}
		}
		if (true == IsUp('W') && Column != 0)
		{
			NowDir = 'W';
			int stack = 0;
			if (CharName == "Cursor")
			{
				if (NotContainString(Column - 1, Row, "/")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
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
				return;
			}
			if (Tile::containsString("Push", Tilemap[Column - 1][Row]))
				//Tilemap[GetActorLocation().Y/TileSize][(GetActorLocation().X / TileSize) + 1] << 현재 엑터의 오른쪽을 체크
			{
				while (Tile::containsString("Push", Tilemap[Column - (stack + 2)][Row]))
				{
					if (Tilemap[Column - (stack + 2)][Row][Tilemap[Column - (stack + 2)][Row].size() - 1] == "/")
					{
						return;
					}
					stack++;
				}
				while (stack >= -1)
				{
					PushState(Column, Row, stack, "Column", '-');
					stack--;
				}
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {0.0f, TileSize};
				PlayerOrObject();

				movestack++;
			}
			else if (NotContainString(Column - 1, Row, "Push")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
			{
				{
					MoveActive = true;
					MoveDir = GetActorLocation();
					MoveDir += {0.0f, TileSize};
					PlayerOrObject();
					setTileMap(-(Column - 1), Row, CharName);
					Pop_text(Tilemap[Column][Row]);
					movestack++;
				}
			}
		}
		if (true == IsUp('S') && Column != 19)
		{
			NowDir = 'S';
			int stack = 0;
			if (CharName == "Cursor")
			{
				if (NotContainString(Column + 1, Row, "/")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
				{
					{
						MoveActive = true;
						MoveDir = GetActorLocation();
						MoveDir += {0.0f, -TileSize};
						State.ChangeState("move");
						setTileMap(-(Column + 1), Row, CharName);
						Pop_text(Tilemap[Column][Row]);
						movestack++;
					}
				}
				return;
			}
			if (Tile::containsString("Push", Tilemap[Column + 1][Row]))
				//Tilemap[GetActorLocation().Y/TileSize][(GetActorLocation().X / TileSize) + 1] << 현재 엑터의 오른쪽을 체크
			{
				while (Tile::containsString("Push", Tilemap[Column + (stack + 2)][Row]))
				{
					if (Tilemap[Column + (stack + 2)][Row][Tilemap[Column - (stack + 2)][Row].size() - 1] == "/")
					{
						return;
					}
					stack++;
				}
				while (stack >= -1)
				{
					PushState(Column, Row, stack, "Column", '+');
					stack--;
				}
				MoveActive = true;
				MoveDir = GetActorLocation();
				MoveDir += {0.0f, -TileSize};
				State.ChangeState("move");

				movestack++;
			}
			else if (NotContainString(Column + 1, Row, "Push")) //가고자 하는 곳에 아무것도 없음 (정확히는 Empty존재)
			{
				{
					MoveActive = true;
					MoveDir = GetActorLocation();
					MoveDir += {0.0f, -TileSize};
					State.ChangeState("move");
					setTileMap(-(Column + 1), Row, CharName);
					Pop_text(Tilemap[Column][Row]);
					movestack++;
				}
			}
		}
}

void APlayer::Actmove(float _DeltaTime)
{
	//if (true == Renderer->IsCurAnimationEnd())
	//{
	//	int a = 0;
	//}
	if (IsUp('A') || IsUp('D') || IsUp('W') || IsUp('S'))
	{
		int Column = GetActorLocation().Y * -1 / TileSize;
		int Row = GetActorLocation().X / TileSize;
		std::pair Tilepair = std::make_pair(Column, Row);
		for (std::tuple<int, int, int> tuple : APlayer::visitTile) {

			if (std::get<0>(tuple) == Tilepair.first)
			{
				if (std::get<1>(tuple) == Tilepair.second)
				{
					IsMove = true;
					APlayer::visitTile.erase(std::find(APlayer::visitTile.begin(), APlayer::visitTile.end(), tuple));
					break;
				}
			}
		}
	}
	if (IsMove == true)
	{
		if (true == IsUp('A'))
		{
			MoveActive = true;
			MoveDir = GetActorLocation();
			MoveDir += {-TileSize, 0.0f};
		}

		else if (true == IsUp('D'))
		{
			MoveActive = true;
			MoveDir = GetActorLocation();
			MoveDir += {TileSize, 0.0f};
		}

		else if (true == IsUp('W'))
		{
			MoveActive = true;
			MoveDir = GetActorLocation();
			MoveDir += {0.0f, TileSize};
		}

		else if (true == IsUp('S'))
		{
			MoveActive = true;
			MoveDir = GetActorLocation();
			MoveDir += {0.0f, -TileSize};
		}


		IsMove = false;
		//float4 Pos = GetActorLocation();


		//Pos /= UContentsConstValue::TileSize;
		//Pos.Y = -Pos.Y;

		//Color8Bit Color = Tex->GetColor(Pos, Color8Bit::Black);

		//if (Color != Color8Bit::Black)
		//{
		//	AddActorLocation(float4::Down * _DeltaTime * 100.0f);
		//}
	}
}