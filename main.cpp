#include"SceneManager.h"
int main() {
	SceneManager::GetInstance().AddScene("����", "1. �� ����, 2. ���� ����");
	SceneManager::GetInstance().AddScene("��", "1. ȸ��, 2. ������");
	SceneManager::GetInstance().AddScene("����", "1. ������, 2. ������");
	SceneManager::GetInstance().AddScene("��", "1. ������");

	SceneManager::GetInstance().SetCurrentScene("����");
	SceneManager::GetInstance().ShowCurrentScene();
}