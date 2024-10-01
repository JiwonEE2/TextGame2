#include"Game.h"
#include"SceneManager.h"
#include"Player.h"
#include"EarthWorm.h"

int main() {
	Player player("Dori");
	Game game(&player);

	// 몬스터 생성
	srand(time(0));
	int num = 5;
	EarthWorm earthWorms[5] = {};
	for (int i = 0; i < num; i++) {
		earthWorms[i].Print();
	}

	string startDisp = game.GetStartDisp();
	string homeDisp = game.GetHomeDisp();
	string townDisp = game.GetTownDisp();
	string forestDisp = game.GetForestDisp(earthWorms);

	player.SetMoveLine(1);
	SceneManager::GetInstance().AddScene("시작", "1. 새 게임, 2. 게임 종료", startDisp);
	SceneManager::GetInstance().AddScene("집", "1. 회복, 2. 마을로", homeDisp);
	SceneManager::GetInstance().AddScene("마을", "1. 집으로, 2. 숲으로", townDisp);
	SceneManager::GetInstance().AddScene("숲", "1. 마을로", forestDisp);
	
	// 시작화면
	SceneManager::GetInstance().SetCurrentScene("시작");
	SceneManager::GetInstance().ShowCurrentScene();
	while (!player.GetIsChoice()) {
		system("cls");
		startDisp = game.GetStartDisp();
		SceneManager::GetInstance().EditScene(startDisp);
		SceneManager::GetInstance().ShowCurrentScene();
		player.InputKey();
		player.SetMoveLine(1);
	}

	while (true) {
		// 집
		if (player.GetY() == 1) {
			SceneManager::GetInstance().SetCurrentScene("집");
			while (true) {
				system("cls");
				homeDisp = game.GetHomeDisp();
				SceneManager::GetInstance().EditScene(homeDisp);
				SceneManager::GetInstance().ShowCurrentScene();
				player.InputKey();
				player.SetMoveLine(2);
				if (player.GetIsChoice() && game.GetIsOut()) {
					cout << "나가자~~~~\n";
					break;
				}
			}
			system("cls");

			// 마을화면
			player.SetXY(3, 5);
			townDisp = game.GetTownDisp();
			SceneManager::GetInstance().SetCurrentScene("마을");
			game.SetIsOut(false);
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				SceneManager::GetInstance().ShowCurrentScene();
				player.InputKey();
				player.SetMoveLine(3);
				system("cls");
				townDisp = game.GetTownDisp();
				SceneManager::GetInstance().EditScene(townDisp);
			}

			// 숲으로 가기
			player.SetXY(1, 7);
			forestDisp = game.GetForestDisp(earthWorms);
			SceneManager::GetInstance().SetCurrentScene("숲");
			system("cls");
			SceneManager::GetInstance().ShowCurrentScene();
			player.PrintStatus();
			game.SetIsOut(false);
			player.InputKey();
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				player.SetMoveLine(4);
				system("cls");
				forestDisp = game.GetForestDisp(earthWorms);
				SceneManager::GetInstance().EditScene(forestDisp);
				SceneManager::GetInstance().ShowCurrentScene();
				player.PrintStatus();
				player.DeathCheck();
				if (player.GetIsDeath())break;
				player.InputKey();
			}
		}
		break;
	}
}