#include"Game.h"
#include"SceneManager.h"
#include"Player.h"
#include"EarthWorm.h"

int main() {
	Player player("Dori");
	Game game(&player);
	string startDisp = game.GetStartDisp();
	string homeDisp;

	SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������", homeDisp);

	player.SetPosition(1);
	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����", startDisp);
	SceneManager::GetInstance().SetCurrentScene("����");
	SceneManager::GetInstance().ShowCurrentScene();

	while (!player.GetIsChoice()) {
		system("cls");
		startDisp = game.GetStartDisp();
		SceneManager::GetInstance().EditScene(startDisp);
		SceneManager::GetInstance().ShowCurrentScene();
		player.InputKey();
		player.SetPosition(1);
	}

	while (true) {
		// ��
		player.SetIsChoice(false);
		SceneManager::GetInstance().SetCurrentScene("��");
		player.SetIsChoice(false);
		if (player.GetY() == 1) {
			system("cls");
			homeDisp = game.GetHomeDisp();
			SceneManager::GetInstance().EditScene(homeDisp);
			SceneManager::GetInstance().ShowCurrentScene();
			player.InputKey();
			player.SetPosition(2);

			while (true) {
				system("cls");
				homeDisp = game.GetHomeDisp();
				SceneManager::GetInstance().EditScene(homeDisp);
				SceneManager::GetInstance().ShowCurrentScene();
				player.InputKey();
				player.SetPosition(2);
				bool temp1 = player.GetIsChoice();
				bool temp2 = game.GetIsOut();
				if (temp1 && temp2) {
					cout << "������~~~~\n";
					player.SetIsChoice(false);
					break;
				}
			}
			system("cls");

			// ���� ����
			player.SetXY(3, 5);
			string townDisp = game.GetTownDisp();
			SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������", townDisp);
			SceneManager::GetInstance().SetCurrentScene("����");
			SceneManager::GetInstance().ShowCurrentScene();
			player.SetIsChoice(false);
			game.SetIsOut(false);
			player.InputKey();
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				player.SetPosition(3);
				system("cls");
				townDisp = game.GetTownDisp();
				SceneManager::GetInstance().EditScene(townDisp);
				SceneManager::GetInstance().ShowCurrentScene();
				player.InputKey();
			}

			// ���� ����
			srand(time(0));
			int num = 5;
			EarthWorm earthWorms[5] = {};
			for (int i = 0; i < num; i++) {
				earthWorms[i].Print();
			}

			// ������ ����
			player.SetXY(1, 7);
			string forestDisp = game.GetForestDisp(earthWorms);
			SceneManager::GetInstance().AddScene("��", "1. ������", forestDisp);
			SceneManager::GetInstance().SetCurrentScene("��");
			system("cls");
			SceneManager::GetInstance().ShowCurrentScene();
			player.PrintStatus();
			player.SetIsChoice(false);
			game.SetIsOut(false);
			player.InputKey();
			while (!player.GetIsChoice() || !game.GetIsOut()) {
				player.SetPosition(4);
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
	}
}