#include"DisplayMaker.h"
#include"SceneManager.h"
#include"Player.h"

int main() {
	Player player("Dori");
	DisplayMaker displayMaker(&player);
	string startDisp = displayMaker.GetStartDisp();
	string homeDisp;
	string townDisp = displayMaker.GetTownDisp();
	string forestDisp = displayMaker.GetForestDisp();
	
	SceneManager::GetInstance().AddScene("집", "1. 회복, 2. 마을로", homeDisp);
	SceneManager::GetInstance().AddScene("마을", "1. 집으로, 2. 숲으로", townDisp);
	SceneManager::GetInstance().AddScene("숲", "1. 마을로", forestDisp);

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
			if (temp1&&temp2) {
				cout << "나가자~~~~\n";
				player.SetIsChoice(false);
				break;
			}
		}
	}
}