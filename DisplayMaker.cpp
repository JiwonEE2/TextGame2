#include"DisplayMaker.h"
#include"Player.h"

DisplayMaker::DisplayMaker()
{
	startDisp =
		"-------------------\n"
		"   �� ����\n"
		"   ���� ����\n"
		"-------------------\n";
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
	// 0123~20
	// 21,22~2��
	// 41,42~2��
	startDisp =
		"-------------------\n"
		"   �� ����\n"
		"   ���� ����\n"
		"-------------------\n";
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