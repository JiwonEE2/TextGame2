#include"Game.h"

Game::Game()
{
	// start �� ���� ȭ��
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
		"|  /_\\  |  | quest|\n"
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
	inventoryDisp =
		"------------------\n"
		"|   INVENTORY     |\n"
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

	// ������ ����
	ItemManager::GetInstance().AddItem(1, "�ܰ�", "����", 5, 0, 0, 500);
	ItemManager::GetInstance().AddItem(2, "���", "����", 10, 0, 0, 1000);
	ItemManager::GetInstance().AddItem(3, "��������", "����", 0, 1, 0, 100);
	ItemManager::GetInstance().AddItem(4, "ưư�Ѹ���", "����", 0, 2, 0, 200);
	ItemManager::GetInstance().AddItem(5, "��������", "����", 0, 5, 0, 500);
	ItemManager::GetInstance().AddItem(6, "ưư�Ѱ���", "����", 0, 10, 0, 1000);
	ItemManager::GetInstance().AddItem(7, "��������", "����", 0, 3, 0, 300);
	ItemManager::GetInstance().AddItem(8, "ưư�ѹ���", "����", 0, 6, 0, 600);
	ItemManager::GetInstance().AddItem(9, "��������", "����", 0, 2, 0, 200);
	ItemManager::GetInstance().AddItem(10, "ưư�Ѻ���", "����", 0, 4, 0, 400);
	ItemManager::GetInstance().AddItem(11, "���Ϲ��", "�Ҹ�ǰ", 0, 0, 5, 50);
	ItemManager::GetInstance().AddItem(12, "��ó��", "�Ҹ�ǰ", 0, 0, 10, 100);

	// �� ����
	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����");
	SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������");
	SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������");
	SceneManager::GetInstance().AddScene("����", "1. ������");
	SceneManager::GetInstance().AddScene("��", "1. ������");
	SceneManager::GetInstance().AddScene("�κ��丮", "1. ����ȭ������");
}

Game::~Game()
{
	delete[] * mp;
	*mp = nullptr;
}

void Game::StartGame()
{
	// ���� ����
	srand(time(0));
	int num = 5;
	EarthWorm earthWorms[5] = {};
	for (int i = 0; i < num; i++) {
		earthWorms[i].Print();
	}
	// ����ȭ��
	SceneManager::GetInstance().SetCurrentScene("����");
	while (!player.GetIsChoice()) {
		SceneManager::GetInstance().EditShowCurrentScene(GetStartDisp());
		player.InputKey(1);
	}

	if (player.GetY() == 1) {
		// �̸� ���ϴ� ȭ��
		player.SetPlayerName();

		// ���������� ���� ����
		go = Go::SHOP;
		preGo=Go::HOME;
		while (!player.GetIsDeath()) {
			player.SetIsChoice(false);
			switch (go)
			{
			case Go::HOME:
				SceneManager::GetInstance().SetCurrentScene("��");
				player.SetXY(9, 10);
				while (!player.GetIsChoice() || go == Go::HOME) {
					SceneManager::GetInstance().EditShowCurrentScene(GetHomeDisp());
					if (go == Go::INVENTORY) {
						system("cls");
						break;
					}
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			case Go::TOWN:
				SceneManager::GetInstance().SetCurrentScene("����");
				player.SetXY(3, 5);
				while (!player.GetIsChoice() || go == Go::TOWN) {
					SceneManager::GetInstance().EditShowCurrentScene(GetTownDisp());
					if (go == Go::INVENTORY) {
						system("cls");
						break;
					}
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			case Go::SHOP:
				SceneManager::GetInstance().SetCurrentScene("����");
				player.SetXY(1, 1);
				while (!player.GetIsChoice() || go == Go::SHOP) {
					SceneManager::GetInstance().EditShowCurrentScene(GetShopDisp());
					if (go == Go::INVENTORY) {
						system("cls");
						break;
					}
					player.InputKey(3);
				}
				break;
			case Go::FOREST:
				SceneManager::GetInstance().SetCurrentScene("��");
				player.SetXY(1, 7);
				while ((!player.GetIsChoice() || go == Go::FOREST) && !player.GetIsDeath()) {
					SceneManager::GetInstance().EditShowCurrentScene(GetForestDisp(earthWorms));
					if (go == Go::INVENTORY) {
						system("cls");
						break;
					}
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			case Go::INVENTORY:
				SceneManager::GetInstance().SetCurrentScene("�κ��丮");
				player.SetXY(1, 1);
				while (!player.GetIsChoice() || go == Go::INVENTORY) {
					SceneManager::GetInstance().EditShowCurrentScene(GetInvenDisp());
					if (go != Go::INVENTORY) {
						system("cls");
						go = preGo;
						break;
					}
					player.InputKey(4);
				}
				break;
			default:
				break;
			}
		}
	}
}

string Game::GetStartDisp()
{
	string display = startDisp;
	int n = player.GetY();
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
	int x = player.GetX();
	int y = player.GetY();
	display.replace(homeToTown[0] + homeToTown[1] * 20, 1, "0");
	display.replace(x + 20 * y, 1, "*");

	// home �Ӹ� �ƴ϶� ��� ������ �÷��̾ �κ�����Ű�� �������� �޴´�.
	// ���� true��� �ٷ� �κ����� ����.
	if (player.GetInvenOpen()) {
		go = Go::INVENTORY;
		cout << "�κ��� ������ �Ѵ٤�..\n";
		preGo = Go::HOME;
	}
	else if (x > 4 && x < 11 && y > 5 && y < 8)IsBed();
	else if (x == homeToTown[0] && y == homeToTown[1])GoTown();
	else go = Go::HOME;
	return display;
}

string Game::GetTownDisp()
{
	string display = townDisp;
	int x = player.GetX();
	int y = player.GetY();
	display.replace(townToHome[0] + townToHome[1] * 20, 1, "0");
	display.replace(townToShop[0] + townToShop[1] * 20, 1, "0");
	display.replace(quest[0] + quest[1] * 20, 1, "0");
	display.replace(townToForest[0] + townToForest[1] * 20, 1, "0");
	display.replace(x + 20 * y, 1, "*");
	// home �Ӹ� �ƴ϶� ��� ������ �÷��̾ �κ�����Ű�� �������� �޴´�.
	// ���� true��� �ٷ� �κ����� ����.
	if (player.GetInvenOpen()) {
		go = Go::INVENTORY;
		cout << "�κ��� ������ �Ѵ٤�..\n";
		preGo = Go::TOWN;
	}
	else if (x == townToHome[0] && y == townToHome[1])GoHome();
	else if (x == townToShop[0] && y == townToShop[1])GoShop();
	else if (x == townToForest[0] && y == townToForest[1])GoForest();
	else if (x == quest[0] && y == quest[1])Quest();
	else go = Go::TOWN;
	return display;
}

string Game::GetShopDisp()
{
	string display = shopDisp;
	int x = player.GetX();
	int y = player.GetY();
	int itemY[100];
	for (int i = 1; i < ItemManager::GetInstance().GetItemNumber() + 1; i++) {
		itemY[i] = i;
		display.replace((itemY[i] + 3) * 20 + 3, 1, "+");
	}
	display.replace(shopToTown[0] + shopToTown[1] * 20, 1, "0");
	display.replace(x + 20 * y, 1, "*");
	for (int i = 1; i < ItemManager::GetInstance().GetItemNumber() + 1; i++) {
		if (x == 3 && y == itemY[i] + 3)PrintItem(i);
	}
	// home �Ӹ� �ƴ϶� ��� ������ �÷��̾ �κ�����Ű�� �������� �޴´�.
	// ���� true��� �ٷ� �κ����� ����.
	if (player.GetInvenOpen()) {
		go = Go::INVENTORY;
		cout << "�κ��� ������ �Ѵ٤�..\n";
		preGo = Go::SHOP;
	}
	else if (x == shopToTown[0] && y == shopToTown[1])GoTown();
	else go = Go::SHOP;
	return display;
}

string Game::GetForestDisp(EarthWorm monster[])
{
	string display = forestDisp;
	int x = player.GetX();
	int y = player.GetY();
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
	// home �Ӹ� �ƴ϶� ��� ������ �÷��̾ �κ�����Ű�� �������� �޴´�.
	// ���� true��� �ٷ� �κ����� ����.
	if (player.GetInvenOpen()) {
		go = Go::INVENTORY;
		cout << "�κ��� ������ �Ѵ٤�..\n";
		preGo = Go::FOREST;
	}
	else if (x == forestToTown[0] && y == forestToTown[1])GoTown();
	else go = Go::FOREST;
	return display;
}

string Game::GetInvenDisp()
{
	string display = inventoryDisp;
	int x = player.GetX();
	int y = player.GetY();
	int itemY[100];
	for (int i = 1; i < player.GetItemNumber() + 1; i++) {
		itemY[i] = i;
		display.replace((itemY[i] + 3) * 20 + 3, 1, "+");
	}
	display.replace(x + 20 * y, 1, "*");
	for (int i = 1; i < ItemManager::GetInstance().GetItemNumber() + 1; i++) {
		if (x == 3 && y == itemY[i] + 3) {
			player.ShowInventoryItem(i);
		}
	}
	// �κ��� �����ٴ� ��ȣ�� Ȯ���ϰ�
	if (!player.GetInvenOpen()) {
		go = preGo;
		cout << "�κ��� �������� �Ѵ�..\n";
	}
	else go = Go::INVENTORY;
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

void Game::Quest()
{
	cout << "==== ����Ʈ ====\n";
	cout << "���� ������ " << qAll << "������ ����϶�\n";
	cout << "���� : " << qMoney << "��\n";
	cout << "���� : " << qNow << "/" << qAll << "\n";
	if (qNow == qAll) {
		if (!qComplete) {
			player.SetMoney(player.GetMoney() + qMoney);
			cout << "���ϼ̽��ϴ�^^ " << qMoney << "�� ���ޤ�\n";
			qComplete = true;
		}
		else {
			cout << "�̹� �޾Ƽ� �� ���޴´�.\n";
		}
	}
	cout << "===============\n";
}

void Game::PrintItem(int i)
{
	ItemManager::GetInstance().SetCurrentItem(i);
	cout << "~~~ ������ �����۵� ~~~\n";
	ItemManager::GetInstance().ShowItem();
	// i ������ ��ġ���� ����
	if (player.GetIsChoice()) {
		cout << "������ �����Ͻðڽ��ϱ�?\n";
		player.PrintStatus();
		player.InputKey(2);
		// �缱�� ���� ��
		if (player.GetIsChoice()) {
			// ���� ���ٸ�
			if (player.GetMoney() < ItemManager::GetInstance().GetItemMoney()) {
				cout << "���� �����Ͽ� �������� ���߽��ϴ�.\n";
			}
			// ������ ����
			else {
				player.SetMoney(player.GetMoney() - ItemManager::GetInstance().GetItemMoney());
				cout << ItemManager::GetInstance().GetItemName() << "�� �����Ͽ����ϴ�.\n";
				// ����ִ� ���� �־�� �ϴµ�..
				player.AddItem();
			}
		}
	}
}

void Game::IsBed()
{
	if (player.GetIsChoice() == true) {
		cout << "���� ��ϴ�...\n";
		player.SetIsChoice(false);
		player.Heal();
	}
	cout << "Go to Sleep?\n";
}

void Game::MonsterAttack(int i)
{
	if (mp[i]->GetX() - player.GetX() <= 1
		&& mp[i]->GetX() - player.GetX() >= -1
		&& mp[i]->GetY() - player.GetY() <= 1
		&& mp[i]->GetY() - player.GetY() >= -1) {
		if (!mp[i]->GetIsDeath()) {
			cout << i << "��° �����̿��� �¾ҽ��ϴ�\n";
			player.Attacked(mp[i]);
			if (player.GetPressAttack()) {
				mp[i]->Attacked(&player);
				cout << i << "��° �����̸� ���ȴ�!\n";
				cout << "������ ���� ü�� : " << mp[i]->GetHealth() << "\n";
				if (mp[i]->GetIsDeath()) {
					cout << mp[i]->GetName() << "�� ����߽��ϴ�\n";
					player.UpExperience(mp[i]);
					player.SetMoney(player.GetMoney() + mp[i]->GetMoney());
					qNow++;
					cout << mp[i]->GetMoney() << "���� �ֿ���!!!\n";
				}
			}
		}
	}
}