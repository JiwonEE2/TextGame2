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

	string startDisp = game.GetStartDisp();
	string homeDisp = game.GetHomeDisp();
	string townDisp = game.GetTownDisp();
	string forestDisp = game.GetForestDisp(earthWorms);

	player.SetMoveLine(1);
	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����", startDisp);
	SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������", homeDisp);
	SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������", townDisp);
	SceneManager::GetInstance().AddScene("��", "1. ������", forestDisp);
	
	// ����ȭ��
	SceneManager::GetInstance().SetCurrentScene("����");
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
		// ��
		if (player.GetY() == 1) {
			SceneManager::GetInstance().SetCurrentScene("��");
			while (true) {
				system("cls");
				homeDisp = game.GetHomeDisp();
				SceneManager::GetInstance().EditScene(homeDisp);
				SceneManager::GetInstance().ShowCurrentScene();
				player.InputKey();
				player.SetMoveLine(2);
				if (player.GetIsChoice() && game.GetIsOut()) {
					cout << "������~~~~\n";
					break;
				}
			}
			system("cls");

			// ����ȭ��
			player.SetXY(3, 5);
			townDisp = game.GetTownDisp();
			SceneManager::GetInstance().SetCurrentScene("����");
			game.SetIsOut(false);
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				SceneManager::GetInstance().ShowCurrentScene();
				player.InputKey();
				player.SetMoveLine(3);
				system("cls");
				townDisp = game.GetTownDisp();
				SceneManager::GetInstance().EditScene(townDisp);
			}

			// ������ ����
			player.SetXY(1, 7);
			forestDisp = game.GetForestDisp(earthWorms);
			SceneManager::GetInstance().SetCurrentScene("��");
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