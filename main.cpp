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

	// 씬 세팅
	SceneManager::GetInstance().AddScene("시작", "1. 새 게임, 2. 게임 종료");
	SceneManager::GetInstance().AddScene("집", "1. 회복, 2. 마을로");
	SceneManager::GetInstance().AddScene("마을", "1. 집으로, 2. 숲으로");
	SceneManager::GetInstance().AddScene("숲", "1. 마을로");
	
	// 시작화면
	SceneManager::GetInstance().SetCurrentScene("시작");
	while (!player.GetIsChoice()) {
		SceneManager::GetInstance().EditShowCurrentScene(game.GetStartDisp());
		player.InputKey(1);
	}

	while (true) {
		// 집
		if (player.GetY() == 1) {
			SceneManager::GetInstance().SetCurrentScene("집");
			player.SetXY(9, 13);
			game.SetIsOut(false);
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				SceneManager::GetInstance().EditShowCurrentScene(game.GetHomeDisp());
				player.InputKey(2);
			}

			// 마을화면
			SceneManager::GetInstance().SetCurrentScene("마을");
			player.SetXY(3, 5);
			game.SetIsOut(false);
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				SceneManager::GetInstance().EditShowCurrentScene(game.GetTownDisp());
				player.InputKey(2);
			}

			// 숲으로 가기
			SceneManager::GetInstance().SetCurrentScene("숲");
			player.SetXY(1, 7);
			game.SetIsOut(false);
			while ((!player.GetIsChoice() || !game.GetIsOut()) && !player.GetIsDeath()) {
				SceneManager::GetInstance().EditShowCurrentScene(game.GetForestDisp(earthWorms));
				player.PrintStatus();
				player.InputKey(2);
			}
		}
		break;
	}
}