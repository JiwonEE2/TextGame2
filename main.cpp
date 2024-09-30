#include"DisplayMaker.h"
#include"SceneManager.h"
#include"Player.h"
#include"EarthWorm.h"

int main() {
	Player player("Dori");
	DisplayMaker displayMaker(&player);
	string startDisp = displayMaker.GetStartDisp();
	string homeDisp;
	
	SceneManager::GetInstance().AddScene("집", "1. 회복, 2. 마을로", homeDisp);

	player.SetPosition(1);
	SceneManager::GetInstance().AddScene("시작", "1. 새 게임, 2. 게임 종료", startDisp);
	SceneManager::GetInstance().SetCurrentScene("시작");
	SceneManager::GetInstance().ShowCurrentScene();

	while (!player.GetIsChoice()) {
		system("cls");
		startDisp = displayMaker.GetStartDisp();
		SceneManager::GetInstance().EditScene(startDisp);
		SceneManager::GetInstance().ShowCurrentScene();
		player.InputKey();
		player.SetPosition(1);
	}

	player.SetIsChoice(false);
	SceneManager::GetInstance().SetCurrentScene("집");
	player.SetIsChoice(false);
	if (player.GetY() == 1) {
		system("cls");
		homeDisp = displayMaker.GetHomeDisp();
		SceneManager::GetInstance().EditScene(homeDisp);
		SceneManager::GetInstance().ShowCurrentScene();
		player.InputKey();
		player.SetPosition(2);

		while (true) {
			system("cls");
			homeDisp = displayMaker.GetHomeDisp();
			SceneManager::GetInstance().EditScene(homeDisp);
			SceneManager::GetInstance().ShowCurrentScene();
			player.InputKey();
			player.SetPosition(2);
			bool temp1 = player.GetIsChoice();
			bool temp2 = displayMaker.GetIsOut();
			if (temp1 && temp2) {
				cout << "나가자~~~~\n";
				player.SetIsChoice(false);
				break;
			}
		}
		system("cls");

		// 나온 상태
		player.SetXY(3, 5);
		string townDisp = displayMaker.GetTownDisp();
		SceneManager::GetInstance().AddScene("마을", "1. 집으로, 2. 숲으로", townDisp);
		SceneManager::GetInstance().SetCurrentScene("마을");
		SceneManager::GetInstance().ShowCurrentScene();
		player.SetIsChoice(false);
		displayMaker.SetIsOut(false);
		player.InputKey();
		while (!player.GetIsChoice() || !displayMaker.GetIsOut()) {
			player.SetPosition(3);
			system("cls");
			townDisp = displayMaker.GetTownDisp();
			SceneManager::GetInstance().EditScene(townDisp);
			SceneManager::GetInstance().ShowCurrentScene();
			player.InputKey();
		}

		// 몬스터 생성
		srand(time(0));
		int num = 5;
		EarthWorm* earthWorms = new EarthWorm[num];
		for (int i = 0; i < num; i++) {
			earthWorms[i].Print();
		}

		// 숲으로 가기
		player.SetXY(1, 7);
		string forestDisp = displayMaker.GetForestDisp();
		SceneManager::GetInstance().AddScene("숲", "1. 마을로", forestDisp);
		SceneManager::GetInstance().SetCurrentScene("숲");
		SceneManager::GetInstance().ShowCurrentScene();
		player.SetIsChoice(false);
		displayMaker.SetIsOut(false);
		player.InputKey();
		while (!player.GetIsChoice() || !displayMaker.GetIsOut()) {
			player.SetPosition(4);
			system("cls");
			forestDisp = displayMaker.GetForestDisp();
			SceneManager::GetInstance().EditScene(forestDisp);
			SceneManager::GetInstance().ShowCurrentScene();
			player.InputKey();
		}
	}
}