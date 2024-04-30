#include "Player.h"
#include "Tile.h"
#include <EngineCore/EngineDebugMsgWindow.h>




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
		std::string Msg = std::format("Name : {}\n", Tilemap[TileY][TileX]);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("------------------------------");
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}


void APlayer::DebugMessageFunction()
{


	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}


	{
		std::string Msg = std::format("Location : {},{}\n", TileX, TileY);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("Name : {}\n", CharName);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
	{
		std::string Msg = std::format("TileName : {}\n", Tilemap[TileY][TileX]);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
	{
		std::string Msg = std::format("------------------------------");
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}
