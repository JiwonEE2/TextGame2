#include"DisplayMaker.h"
#include"Player.h"

DisplayMaker::DisplayMaker()
{
	startDisp =
		"--------------------\n"
		"|  새 게임          |\n"
		"|  게임 종료        |\n"
		"--------------------\n";
	homeDisp =
		"--------\n"
		"|home	|\n"
		"--------\n";
	townDisp =
		"--------\n"
		"|town	|\n"
		"--------\n";
	forestDisp =
		"--------\n"
		"|forest|\n"
		"--------\n";
}

DisplayMaker::DisplayMaker(Player* player)
{
	pp = player;
	startDisp =
		"--------------------\n"
		"|  새 게임          |\n"
		"|  게임 종료        |\n"
		"--------------------\n";
	homeDisp =
		"--------\n"
		"|home	|\n"
		"--------\n";
	townDisp =
		"--------\n"
		"|town	|\n"
		"--------\n";
	forestDisp =
		"--------\n"
		"|forest|\n"
		"--------\n";
}

string DisplayMaker::GetStartDisp()
{
	int x = pp->GetX();
	int y = pp->GetY();
	int n = x * 20 + y;
	startDisp.replace(n, 2, "▶");
	return startDisp;
}

string DisplayMaker::GetHomeDisp()
{
	return homeDisp;
}

string DisplayMaker::GetTownDisp()
{
	return townDisp;
}

string DisplayMaker::GetForestDisp()
{
	return forestDisp;
}