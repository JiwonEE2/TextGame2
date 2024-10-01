#include"Game.h"
#include"SceneManager.h"
#include"Player.h"
#include"EarthWorm.h"

int main() {
	Player player("Dori");
	Game game(&player);

	// ���� ����
	srand(time(0));
	int num = 5;
	EarthWorm earthWorms[5] = {};
	for (int i = 0; i < num; i++) {
		earthWorms[i].Print();
	}

	// �� ����
	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����");
	SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������");
	SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������");
	SceneManager::GetInstance().AddScene("��", "1. ������");
	
	// ����ȭ��
	SceneManager::GetInstance().SetCurrentScene("����");
	while (!player.GetIsChoice()) {
		SceneManager::GetInstance().EditShowCurrentScene(game.GetStartDisp());
		player.InputKey(1);
	}

	while (true) {
		// ��
		if (player.GetY() == 1) {
			SceneManager::GetInstance().SetCurrentScene("��");
			player.SetXY(9, 13);
			game.SetIsOut(false);
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				SceneManager::GetInstance().EditShowCurrentScene(game.GetHomeDisp());
				player.InputKey(2);
			}

			// ����ȭ��
			SceneManager::GetInstance().SetCurrentScene("����");
			player.SetXY(3, 5);
			game.SetIsOut(false);
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				SceneManager::GetInstance().EditShowCurrentScene(game.GetTownDisp());
				player.InputKey(2);
			}

			// ������ ����
			SceneManager::GetInstance().SetCurrentScene("��");
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