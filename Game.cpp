#include"Game.h"

Game::Game()
{
	// start 씬 다음 화면
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

	// 아이템 생성
	ItemManager::GetInstance().AddItem(1, "단검", "무기", 5, 0, 0, 500);
	ItemManager::GetInstance().AddItem(2, "대검", "무기", 10, 0, 0, 1000);
	ItemManager::GetInstance().AddItem(3, "낡은모자", "모자", 0, 1, 0, 100);
	ItemManager::GetInstance().AddItem(4, "튼튼한모자", "모자", 0, 2, 0, 200);
	ItemManager::GetInstance().AddItem(5, "낡은갑옷", "갑옷", 0, 5, 0, 500);
	ItemManager::GetInstance().AddItem(6, "튼튼한갑옷", "갑옷", 0, 10, 0, 1000);
	ItemManager::GetInstance().AddItem(7, "낡은바지", "바지", 0, 3, 0, 300);
	ItemManager::GetInstance().AddItem(8, "튼튼한바지", "바지", 0, 6, 0, 600);
	ItemManager::GetInstance().AddItem(9, "낡은부츠", "부츠", 0, 2, 0, 200);
	ItemManager::GetInstance().AddItem(10, "튼튼한부츠", "부츠", 0, 4, 0, 400);
	ItemManager::GetInstance().AddItem(11, "데일밴드", "소모품", 0, 0, 5, 50);
	ItemManager::GetInstance().AddItem(12, "상처약", "소모품", 0, 0, 10, 100);

	// 씬 세팅
	SceneManager::GetInstance().AddScene("시작", "1. 새 게임, 2. 게임 종료");
	SceneManager::GetInstance().AddScene("집", "1. 회복, 2. 마을로");
	SceneManager::GetInstance().AddScene("마을", "1. 집으로, 2. 숲으로");
	SceneManager::GetInstance().AddScene("상점", "1. 마을로");
	SceneManager::GetInstance().AddScene("숲", "1. 마을로");
	SceneManager::GetInstance().AddScene("인벤토리", "1. 이전화면으로");
}

Game::~Game()
{
	delete[] * mp;
	*mp = nullptr;
}

void Game::StartGame()
{
	// 몬스터 생성
	srand(time(0));
	int num = 5;
	EarthWorm earthWorms[5] = {};
	for (int i = 0; i < num; i++) {
		earthWorms[i].Print();
	}
	// 시작화면
	SceneManager::GetInstance().SetCurrentScene("시작");
	while (!player.GetIsChoice()) {
		SceneManager::GetInstance().EditShowCurrentScene(GetStartDisp());
		player.InputKey(1);
	}

	if (player.GetY() == 1) {
		// 이름 정하는 화면
		player.SetPlayerName();

		// 집에서부터 게임 시작
		go = Go::SHOP;
		preGo=Go::HOME;
		while (!player.GetIsDeath()) {
			player.SetIsChoice(false);
			switch (go)
			{
			case Go::HOME:
				SceneManager::GetInstance().SetCurrentScene("집");
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
				SceneManager::GetInstance().SetCurrentScene("마을");
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
				SceneManager::GetInstance().SetCurrentScene("상점");
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
				SceneManager::GetInstance().SetCurrentScene("숲");
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
				SceneManager::GetInstance().SetCurrentScene("인벤토리");
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

	// home 뿐만 아니라 모든 곳에서 플레이어가 인벤오픈키를 눌렀는지 받는다.
	// 만약 true라면 바로 인벤으로 간다.
	if (player.GetInvenOpen()) {
		go = Go::INVENTORY;
		cout << "인벤을 열려고 한다ㅏ..\n";
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
	// home 뿐만 아니라 모든 곳에서 플레이어가 인벤오픈키를 눌렀는지 받는다.
	// 만약 true라면 바로 인벤으로 간다.
	if (player.GetInvenOpen()) {
		go = Go::INVENTORY;
		cout << "인벤을 열려고 한다ㅏ..\n";
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
	// home 뿐만 아니라 모든 곳에서 플레이어가 인벤오픈키를 눌렀는지 받는다.
	// 만약 true라면 바로 인벤으로 간다.
	if (player.GetInvenOpen()) {
		go = Go::INVENTORY;
		cout << "인벤을 열려고 한다ㅏ..\n";
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
	// home 뿐만 아니라 모든 곳에서 플레이어가 인벤오픈키를 눌렀는지 받는다.
	// 만약 true라면 바로 인벤으로 간다.
	if (player.GetInvenOpen()) {
		go = Go::INVENTORY;
		cout << "인벤을 열려고 한다ㅏ..\n";
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
	// 인벤이 닫혔다는 신호를 확인하고
	if (!player.GetInvenOpen()) {
		go = preGo;
		cout << "인벤을 닫으려고 한다..\n";
	}
	else go = Go::INVENTORY;
	return display;
}

void Game::GoHome()
{
	go = Go::HOME;
	cout << "집으로 가시겠습니까?\n";
}

void Game::GoTown()
{
	go = Go::TOWN;
	cout << "마을로 가시겠습니까?\n";
}

void Game::GoShop()
{
	go = Go::SHOP;
	cout << "상점으로 가시겠습니까?\n";
}

void Game::GoForest()
{
	go = Go::FOREST;
	cout << "숲으로 가시겠습니까?\n";
}

void Game::Quest()
{
	cout << "==== 퀘스트 ====\n";
	cout << "약한 지렁이 " << qAll << "마리를 사살하라\n";
	cout << "보상 : " << qMoney << "원\n";
	cout << "진행 : " << qNow << "/" << qAll << "\n";
	if (qNow == qAll) {
		if (!qComplete) {
			player.SetMoney(player.GetMoney() + qMoney);
			cout << "잘하셨습니다^^ " << qMoney << "원 지급ㅎ\n";
			qComplete = true;
		}
		else {
			cout << "이미 받아서 또 못받는다.\n";
		}
	}
	cout << "===============\n";
}

void Game::PrintItem(int i)
{
	ItemManager::GetInstance().SetCurrentItem(i);
	cout << "~~~ 상점의 아이템들 ~~~\n";
	ItemManager::GetInstance().ShowItem();
	// i 아이템 위치에서 선택
	if (player.GetIsChoice()) {
		cout << "아이템 구매하시겠습니까?\n";
		player.PrintStatus();
		player.InputKey(2);
		// 재선택 했을 시
		if (player.GetIsChoice()) {
			// 돈이 없다면
			if (player.GetMoney() < ItemManager::GetInstance().GetItemMoney()) {
				cout << "돈이 부족하여 구매하지 못했습니다.\n";
			}
			// 아이템 구매
			else {
				player.SetMoney(player.GetMoney() - ItemManager::GetInstance().GetItemMoney());
				cout << ItemManager::GetInstance().GetItemName() << "을 구매하였습니다.\n";
				// 비어있는 곳에 넣어야 하는데..
				player.AddItem();
			}
		}
	}
}

void Game::IsBed()
{
	if (player.GetIsChoice() == true) {
		cout << "잠을 잡니다...\n";
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
			cout << i << "번째 지렁이에게 맞았습니다\n";
			player.Attacked(mp[i]);
			if (player.GetPressAttack()) {
				mp[i]->Attacked(&player);
				cout << i << "번째 지렁이를 때렸다!\n";
				cout << "지렁이 남은 체력 : " << mp[i]->GetHealth() << "\n";
				if (mp[i]->GetIsDeath()) {
					cout << mp[i]->GetName() << "는 사망했습니다\n";
					player.UpExperience(mp[i]);
					player.SetMoney(player.GetMoney() + mp[i]->GetMoney());
					qNow++;
					cout << mp[i]->GetMoney() << "원을 주웠다!!!\n";
				}
			}
		}
	}
}