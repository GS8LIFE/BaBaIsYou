#include "Player.h"
#include "Tile.h"
#include <EngineCore/EngineDebugMsgWindow.h>

void APlayGameMode::DebugMessageFunction()
{
	std::string Msg;
	for (size_t YY = 0; YY < 19; YY++)
	{
		for (size_t XX = 0; XX < 34; XX++)
		{
			{
				Msg += std::format("map : {} = {},{}\n", Tilemap[YY][XX], YY, XX);
			}
		}
	}
	UEngineDebugMsgWindow::PushMsg(Msg);
}


void Tile::DebugMessageFunction()
{
	{
		std::string Msg = std::format("{} Location : {},{}\n", TileName, TileX, TileY);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("Name : {}\n", TileName);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("TileType : {}\n", Type);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("------------------------------");
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}


void APlayer::DebugMessageFunction()
{
	int TileY = 0;
	int TileX = 0;

	if (GetActorLocation().Y < 0)
	{
		TileY = -GetActorLocation().Y / TileSize;
	}
	if (GetActorLocation().X > 0)
	{
		TileX = GetActorLocation().X / TileSize;
	}
	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("Location : {},{}\n", TileX, TileY);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("Name : {}\n", Tilemap[TileY][TileX]);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("------------------------------");
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}
