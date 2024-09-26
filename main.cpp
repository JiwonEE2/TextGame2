#include"SceneManager.h"
#include"Key.h"

int main() {
	string startDisp =
		"-------------------------\n"
		"|\t�� ����\t\t|\n"
		"|\t���� ����\t|\n"
		"-------------------------\n";
	string homeDisp =
		"--------\n"
		"|home	|\n"
		"--------\n";
	string townDisp =
		"--------\n"
		"|town	|\n"
		"--------\n";
	string forestDisp =
		"--------\n"
		"|forest|\n"
		"--------\n";

	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����", startDisp);
	SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������", homeDisp);
	SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������", townDisp);
	SceneManager::GetInstance().AddScene("��", "1. ������", forestDisp);

	SceneManager::GetInstance().SetCurrentScene("����");
	SceneManager::GetInstance().ShowCurrentScene();

	Key key;

	while (true) {
		key.GetKey();
	}
}