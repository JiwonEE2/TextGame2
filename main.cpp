#include"Game.h"
#include"SceneManager.h"
#include"Player.h"
#include"EarthWorm.h"

int main() {
	Player player;
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

	if (player.GetY() == 1) {
		// �̸� ���ϴ� ȭ��
		player.SetPlayerName();
		while (!player.GetIsDeath()) {
			// ���������� ���� ����
			switch (game.GetGo()) {
			case 1:
				SceneManager::GetInstance().SetCurrentScene("��");
				player.SetXY(9, 10);
				while (!player.GetIsChoice() || game.GetGo() == 1) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetHomeDisp());
					player.InputKey(2);
				}
				break;
			case 2:
				SceneManager::GetInstance().SetCurrentScene("����");
				player.SetXY(3, 5);
				while (!player.GetIsChoice() || game.GetGo() == 2) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetTownDisp());
					player.InputKey(2);
				}
				break;
			case 3:
				SceneManager::GetInstance().SetCurrentScene("��");
				player.SetXY(1, 7);
				while ((!player.GetIsChoice() || game.GetGo() == 3) && !player.GetIsDeath()) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetForestDisp(earthWorms));
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			}
		}
	}
}