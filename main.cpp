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
	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����", startDisp);
	SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������", townDisp);
	SceneManager::GetInstance().AddScene("��", "1. ������", forestDisp);

	SceneManager::GetInstance().SetCurrentScene("����");
	SceneManager::GetInstance().ShowCurrentScene();

	player.SetPosition(1);
	while (!player.GetIsChoice()) {
		system("cls");
		startDisp = displayMaker.GetStartDisp();
		SceneManager::GetInstance().RemoveScene();
		SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����", startDisp);
		SceneManager::GetInstance().SetCurrentScene("����");
		SceneManager::GetInstance().ShowCurrentScene();
		player.SetPosition(1);
	}
	player.SetIsChoice(false);

	if (player.GetY() == 1) {
		system("cls");
		SceneManager::GetInstance().RemoveScene();
		homeDisp = displayMaker.GetHomeDisp();
		SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������", homeDisp);
		SceneManager::GetInstance().SetCurrentScene("��");
		SceneManager::GetInstance().ShowCurrentScene();
		player.SetPosition(2);

		while (true) {
			system("cls");
			homeDisp = displayMaker.GetHomeDisp();
			SceneManager::GetInstance().RemoveScene();
			SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������", homeDisp);
			SceneManager::GetInstance().SetCurrentScene("��");
			SceneManager::GetInstance().ShowCurrentScene();
			player.SetPosition(2);
		}
	}
}