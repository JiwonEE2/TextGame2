#include"Game.h"
#include"Player.h"

Game::Game(Player* player)
{
	pp = player;
	// start �� ���� ȭ��
	go = Go::SHOP;
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
		"|  shop |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"|       |  |      |\n"
		"------------------\n";
	shopDisp =
		"------------------\n"
		"|     SHOP        |\n"
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
}

Game::~Game()
{
	delete pp;
	delete[] * mp;
	pp = nullptr;
	*mp = nullptr;
}

string Game::GetStartDisp()
{
	string display = startDisp;
	int n = pp->GetY();
	if (n == 1) {
		display.replace(21, 1, "*");
	}
	else {
		display.replace(32, 1, "*");
	}
	return display;
}

string Game::GetHomeDisp()
{
	string display = homeDisp;
	int x = pp->GetX();
	int y = pp->GetY();
	display.replace(homeToTown[0] + homeToTown[1] * 20, 1, "0");
	display.replace(x + 20 * y, 1, "*");
	if (x > 4 && x < 11 && y > 5 && y < 8)IsBed();
	else if (x == homeToTown[0] && y == homeToTown[1])GoTown();
	else go = Go::HOME;
	return display;
}

string Game::GetTownDisp()
{
	string display = townDisp;
	int x = pp->GetX();
	int y = pp->GetY();
	display.replace(townToHome[0] + townToHome[1] * 20, 1, "0");
	display.replace(townToShop[0] + townToShop[1] * 20, 1, "0");
	display.replace(townToForest[0] + townToForest[1] * 20, 1, "0");
	display.replace(x + 20 * y, 1, "*");
	if (x == townToHome[0] && y == townToHome[1])GoHome();
	else if (x == townToShop[0] && y == townToShop[1])GoShop();
	else if (x == townToForest[0] && y == townToForest[1])GoForest();
	else go = Go::TOWN;
	return display;
}

string Game::GetShopDisp()
{
	string display = shopDisp;
	int x = pp->GetX();
	int y = pp->GetY();
	int itemY[10];
	for (int i = 1; i < ItemManager::GetInstance().GetItemNumber() + 1; i++) {
		itemY[i] = i;
		display.replace((itemY[i] + 3) * 20 + 3, 1, "+");
	}
	display.replace(shopToTown[0] + shopToTown[1] * 20, 1, "0");
	display.replace(x + 20 * y, 1, "*");
	for (int i = 1; i < ItemManager::GetInstance().GetItemNumber() + 1; i++) {
		if (x == 3 && y == itemY[i] + 3)PrintItem(i);
	}
	// �κ��丮 �����ֱ�
	pp->ShowInventory();
	if (x == shopToTown[0] && y == shopToTown[1])GoTown();
	else go = Go::SHOP;
	return display;
}

string Game::GetForestDisp(EarthWorm monster[])
{
	string display = forestDisp;
	int x = pp->GetX();
	int y = pp->GetY();
	display.replace(forestToTown[0] + forestToTown[1] * 20, 1, "0");
	int mx[5], my[5];
	for (int i = 0; i < 5; i++) {
		mp[i] = &monster[i];
		if (mp[i]->GetIsDeath())continue;
		mx[i] = mp[i]->GetX();
		my[i] = mp[i]->GetY();
		display.replace(mx[i] + 20 * my[i], 1, "~");
	}
	display.replace(x + 20 * y, 1, "*");
	for (int i = 0; i < 5; i++) {
		MonsterAttack(i);
	}
	if (x == forestToTown[0] && y == forestToTown[1])GoTown();
	else go = Go::FOREST;
	return display;
}

void Game::GoHome()
{
	go = Go::HOME;
	cout << "������ ���ðڽ��ϱ�?\n";
}

void Game::GoTown()
{
	go = Go::TOWN;
	cout << "������ ���ðڽ��ϱ�?\n";
}

void Game::GoShop()
{
	go = Go::SHOP;
	cout << "�������� ���ðڽ��ϱ�?\n";
}

void Game::GoForest()
{
	go = Go::FOREST;
	cout << "������ ���ðڽ��ϱ�?\n";
}

void Game::PrintItem(int i)
{
	ItemManager::GetInstance().SetCurrentItem(i);
	cout << "~~~ ������ �����۵� ~~~\n";
	ItemManager::GetInstance().ShowItem();
	// i ������ ��ġ���� ����
	if (pp->GetIsChoice()) {
		cout << "������ �����Ͻðڽ��ϱ�?\n";
		pp->PrintStatus();
		pp->InputKey(2);
		// �缱�� ���� ��
		if (pp->GetIsChoice()) {
			// ���� ���ٸ�
			if (pp->GetMoney() < ItemManager::GetInstance().GetItemMoney()) {
				cout << "���� �����Ͽ� �������� ���߽��ϴ�.\n";
			}
			// ������ ����
			else {
				pp->SetMoney(pp->GetMoney() - ItemManager::GetInstance().GetItemMoney());
				cout << ItemManager::GetInstance().GetItemName() << "�� �����Ͽ����ϴ�.\n";
				// ����ִ� ���� �־�� �ϴµ�..
				pp->AddItem();
			}
		}
	}
}

Go Game::GetGo() const
{
	return go;
}

void Game::SetGo(Go go)
{
	this->go = go;
}

void Game::IsBed() const
{
	if (pp->GetIsChoice() == true) {
		cout << "���� ��ϴ�...\n";
		pp->SetIsChoice(false);
		pp->Heal();
	}
	cout << "Go to Sleep?\n";
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
				if (mp[i]->GetIsDeath()) {
					cout << mp[i]->GetName() << "�� ����߽��ϴ�\n";
					pp->UpExperience(mp[i]);
					pp->SetMoney(pp->GetMoney() + mp[i]->GetMoney());
					cout << mp[i]->GetMoney() << "���� �ֿ���!!!\n";
				}
			}
		}
	}
}