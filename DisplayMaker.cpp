#include"DisplayMaker.h"
#include"Player.h"

DisplayMaker::DisplayMaker(Player* player)
{
	pp = player;
	// 0123~20
	// 21,22~2개
	// 41,42~2개
	startDisp =
		"-------------------\n"
		"   새 게임\n"
		"   게임 종료\n"
		"-------------------\n";
	homeDisp =
		"------------------\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"------------------\n";
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
	int n = pp->GetY();
	if (n == 1) {
		startDisp.replace(21, 1, "*");
		startDisp.replace(32, 1, " ");
	}
	else {
		startDisp.replace(21, 1, " ");
		startDisp.replace(32, 1, "*");
	}
	return startDisp;
}

string DisplayMaker::GetHomeDisp()
{
	homeDisp =
		"------------------\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|    ________     |\n"
		"|    |  BED |     |\n"
		"|    |______|     |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"|                 |\n"
		"------------------\n";
	int x = pp->GetX();
	int y = pp->GetY();
	homeDisp.replace(x + 20 * y, 1, "*");
	if (x > 4 && x < 11 && y>5 && y < 8)IsBed();
	return homeDisp;
}

void DisplayMaker::IsBed() const
{
	cout << "Go to Sleep?\n";
}

string DisplayMaker::GetTownDisp()
{
	return townDisp;
}

string DisplayMaker::GetForestDisp()
{
	return forestDisp;
}