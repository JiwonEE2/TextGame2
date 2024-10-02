#include"Game.h"
#include"SceneManager.h"
#include"ItemManager.h"
#include"Player.h"
#include"EarthWorm.h"
#include"Go.h"

int main() {
	Player player;
	Game game(&player);

	// ������ ����
	ItemManager::GetInstance().AddItem(1, "Į", 5, 0, 500);
	ItemManager::GetInstance().AddItem(2, "ȸ����", 0, 5, 100);
	ItemManager::GetInstance().AddItem(3, "����", 10, 10, 1000);

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
	SceneManager::GetInstance().AddScene("����", "1. ������");
	SceneManager::GetInstance().AddScene("��", "1. ������");

	// ����ȭ��
	player.SetIsChoice(false);
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
			player.SetIsChoice(false);
			switch (game.GetGo()) {
			case Go::HOME:
				SceneManager::GetInstance().SetCurrentScene("��");
				player.SetXY(9, 10);
				while (!player.GetIsChoice() || game.GetGo() == Go::HOME) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetHomeDisp());
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			case Go::TOWN:
				SceneManager::GetInstance().SetCurrentScene("����");
				player.SetXY(3, 5);
				while (!player.GetIsChoice() || game.GetGo() == Go::TOWN) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetTownDisp());
					player.PrintStatus();
					player.InputKey(2);
				}
				break;
			case Go::SHOP:
				SceneManager::GetInstance().SetCurrentScene("����");
				player.SetXY(1, 1);
				while (!player.GetIsChoice() || game.GetGo() == Go::SHOP) {
					SceneManager::GetInstance().EditShowCurrentScene(game.GetShopDisp());
					player.InputKey(3);
				}
				break;
			case Go::FOREST:
				SceneManager::GetInstance().SetCurrentScene("��");
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