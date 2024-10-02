#include"Game.h"
#include"SceneManager.h"
#include"ItemManager.h"
#include"Player.h"
#include"EarthWorm.h"
#include"Go.h"

int main() {
	Player player;
	Game game(&player);

	// 아이템 생성
	ItemManager::GetInstance().AddItem(1, "칼", 5, 0, 500);
	ItemManager::GetInstance().AddItem(2, "회복약", 0, 5, 100);
	ItemManager::GetInstance().AddItem(3, "마약", 10, 10, 1000);

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
	SceneManager::GetInstance().AddScene("상점", "1. 마을로");
	SceneManager::GetInstance().AddScene("숲", "1. 마을로");

	// 시작화면
	player.SetIsChoice(false);
	SceneManager::GetInstance().SetCurrentScene("시작");
	while (!player.GetIsChoice()) {
		SceneManager::GetInstance().EditShowCurrentScene(game.GetStartDisp());
		player.InputKey(1);
	}

	if (player.GetY() == 1) {
		// 이름 정하는 화면
		player.SetPlayerName();
		while (!player.GetIsDeath()) {
			// 집에서부터 게임 시작
			player.SetIsChoice(false);
			switch (game.GetGo()) {
			case Go::HOME:
				SceneManager::GetInstance().SetCurrentScene("집");
				player.SetXY(9, 10);
				while (!player.GetIsChoice() || game.GetGo() == Go::HOME) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetHomeDisp());
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			case Go::TOWN:
				SceneManager::GetInstance().SetCurrentScene("마을");
				player.SetXY(3, 5);
				while (!player.GetIsChoice() || game.GetGo() == Go::TOWN) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetTownDisp());
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			case Go::SHOP:
				SceneManager::GetInstance().SetCurrentScene("상점");
				player.SetXY(1, 1);
				while (!player.GetIsChoice() || game.GetGo() == Go::SHOP) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetShopDisp());
					player.InputKey(3);
				}
				break;
			case Go::FOREST:
				SceneManager::GetInstance().SetCurrentScene("숲");
				player.SetXY(1, 7);
				while ((!player.GetIsChoice() || game.GetGo() == Go::FOREST) && !player.GetIsDeath()) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetForestDisp(earthWorms));
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			}
		}
	}
}