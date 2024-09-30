#include"DisplayMaker.h"
#include"SceneManager.h"
#include"Player.h"

int main() {
	Player player("Dori");
	DisplayMaker displayMaker(&player);
	string startDisp = displayMaker.GetStartDisp();
	string homeDisp;

	string forestDisp = displayMaker.GetForestDisp();

	SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������", homeDisp);

	SceneManager::GetInstance().AddScene("��", "1. ������", forestDisp);

	player.SetPosition(1);
	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����", startDisp);
	SceneManager::GetInstance().SetCurrentScene("����");
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
	SceneManager::GetInstance().SetCurrentScene("��");
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
				cout << "������~~~~\n";
				player.SetIsChoice(false);
				break;
			}
		}
		system("cls");

		// ���� ����
		player.SetXY(3, 5);
		string townDisp = displayMaker.GetTownDisp();
		SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������", townDisp);
		SceneManager::GetInstance().SetCurrentScene("����");
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
	}
}