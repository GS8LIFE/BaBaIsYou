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
		std::string rules;
		for (const auto& rule : helper::Rule) 
		{
		rules += rule + ", ";
		}
		rules = rules.substr(0, rules.size() - 2); // 마지막 쉼표와 공백 제거
		std::string Msg = std::format("Rule : {}\n", rules);
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
	{
		std::string Msg = std::format("------------------------------");
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}
