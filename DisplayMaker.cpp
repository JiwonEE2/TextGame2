#include"DisplayMaker.h"
#include"Player.h"

DisplayMaker::DisplayMaker()
{
	startDisp =
		"--------------------\n"
		"|  �� ����          |\n"
		"|  ���� ����        |\n"
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
	// 0123~20
	// 21,22~2��
	// 41,42~2��
	startDisp =
		"--------------------\n"
		"|  �� ����          |\n"
		"|  ���� ����        |\n"
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
	int n = pp->GetY();
	if (n == 2) {
		startDisp.replace(22, 2, "  ");
		startDisp.replace(42, 2, "��");
	}
	else {
		startDisp.replace(42, 2, "  ");
		startDisp.replace(22, 2, "��");
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