#include"DisplayMaker.h"
#include"SceneManager.h"
#include"Player.h"

int main() {
	DisplayMaker displayMaker;
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

	Player player("Dori");

	while (true) {
		player.GetKey();
	}
}