#include"DisplayMaker.h"
#include"SceneManager.h"
#include"Player.h"

int main() {
	Player player("Dori");

	DisplayMaker displayMaker(&player);
	string startDisp = displayMaker.GetStartDisp();
	string homeDisp = displayMaker.GetHomeDisp();
	string townDisp = displayMaker.GetTownDisp();
	string forestDisp = displayMaker.GetForestDisp();

	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����", startDisp);
	SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������", homeDisp);
	SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������", townDisp);
	SceneManager::GetInstance().AddScene("��", "1. ������", forestDisp);

	SceneManager::GetInstance().SetCurrentScene("����");
	SceneManager::GetInstance().ShowCurrentScene();

	while (true) {
		player.SetPosition(1);
		displayMaker.GetStartDisp();
	}
}