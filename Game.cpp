#include"Game.h"
#include"Player.h"
#include"Monster.h"

Game::Game(Player* player)
{
	pp = player;
	go = 1;
	// 0123~20
	// 21,22~2��
	// 41,42~2��
	startDisp =
		"-------------------\n"
		"   �� ����\n"
		"   ���� ����\n"
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

string Game::GetStartDisp()
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

string Game::GetHomeDisp()
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
	else if (x > 4 && x < 10 && y > 17)GoTown();
	return homeDisp;
}

void Game::IsBed() const
{
	if (pp->GetIsChoice() == true) {
		cout << "���� ��ϴ�...\n";
		pp->SetIsChoice(false);
	}
	cout << "Go to Sleep?\n";
}

void Game::GoTown()
{
	go = 2;
	cout << "������ ���ðڽ��ϱ�?\n";
}

string Game::GetTownDisp()
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

void Game::GoHome()
{
	go = 1;
	cout << "������ ���ðڽ��ϱ�?\n";
}

void Game::GoForest()
{
	go = 3;
	cout << "������ ���ðڽ��ϱ�?\n";
}

string Game::GetForestDisp(EarthWorm monster[])
{
	forestDisp =
		"------------------\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|_______|  |______|\n"
		"|town             |\n"
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
	int mx[5], my[5];
	for (int i = 0; i < 5; i++) {
		mp[i] = &monster[i];
		if (mp[i]->GetIsDeath())continue;
		mx[i] = mp[i]->GetX();
		my[i] = mp[i]->GetY();
		forestDisp.replace(mx[i] + 20 * my[i], 1, "~");
	}
	forestDisp.replace(x + 20 * y, 1, "*");
	for (int i = 0; i < 5; i++) {
		MonsterAttack(i);
	}
	if (x < 1 && (y == 6 || y == 7))GoTown();
	return forestDisp;
}

void Game::MonsterAttack(int i)
{
	if (mp[i]->GetX() - pp->GetX() <= 1
		&& mp[i]->GetX() - pp->GetX() >= -1
		&& mp[i]->GetY() - pp->GetY() <= 1
		&& mp[i]->GetY() - pp->GetY() >= -1) {
		if (!mp[i]->GetIsDeath()) {
			cout << i << "��° �����̿��� �¾ҽ��ϴ�\n";
			pp->Attacked(mp[i]);
			if (pp->GetPressAttack()) {
				mp[i]->Attacked(pp);
				cout << i << "��° �����̸� ���ȴ�!\n";
				cout << "������ ���� ü�� : " << mp[i]->GetHealth() << "\n";
			}
		}
	}
}

int Game::GetGo() const
{
	return go;
}

void Game::SetGo(int go)
{
	this->go = go;
}