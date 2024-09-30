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
		"|    | OUT |      |\n"
		"------------------\n";
	int x = pp->GetX();
	int y = pp->GetY();
	homeDisp.replace(x + 20 * y, 1, "*");
	if (x > 4 && x < 11 && y > 5 && y < 8)IsBed();
	else if (x > 4 && x < 10 && y > 17)IsOut();
	return homeDisp;
}

void DisplayMaker::IsBed() const
{
	if (pp->GetIsChoice() == true) {
		cout << "잠을 잡니다...\n";
		pp->SetIsChoice(false);
	}
	cout << "Go to Sleep?\n";
}

bool DisplayMaker::GetIsOut()
{
	return isOut;
}

void DisplayMaker::SetIsOut(bool is)
{
	isOut = is;
}

void DisplayMaker::IsOut()
{
	cout << "나가나?\n";
	isOut = true;
}

string DisplayMaker::GetTownDisp()
{
	townDisp =
		"------------------\n"
		"|       |  |      |\n"
		"| home  |  |      |\n"
		"|  /_\\  |  |      |\n"
		"|  |_|  |  |      |\n"
		"|_______|  |______|\n"
		"|           forest|\n"
		"|_______    ______|\n"
		"|       |  |      |\n"
		"|       |  |   /\\ |\n"
		"|       |  |   || |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"------------------\n";
	int x = pp->GetX();
	int y = pp->GetY();
	townDisp.replace(x + 20 * y, 1, "*");
	if (x == 3 && y == 4)GoHome();
	else if (x > 15 && (y == 7 || y == 6))GoForest();
	return townDisp;
}

void DisplayMaker::GoHome()
{
	cout << "집으로 가시겠습니까?\n";
}

void DisplayMaker::GoForest()
{
	cout << "숲으로 가시겠습니까?\n";
	isOut = true;
}

string DisplayMaker::GetForestDisp()
{
	forestDisp =
		"------------------\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|_______|  |______|\n"
		"|home             |\n"
		"|_______    ______|\n"
		"|       |  |      |\n"
		"|       |  |   /\\ |\n"
		"|       |  |   || |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"------------------\n";
	int x = pp->GetX();
	int y = pp->GetY();
	forestDisp.replace(x + 20 * y, 1, "*");
	if (x == 3 && y == 6)GoHome();
	else if (x > 15 && (y == 7 || y == 6))GoForest();
	return forestDisp;
}