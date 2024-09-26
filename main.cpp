#include"SceneManager.h"
int main() {
	SceneManager::GetInstance().AddScene("시작", "1. 새 게임, 2. 게임 종료");
	SceneManager::GetInstance().AddScene("집", "1. 회복, 2. 마을로");
	SceneManager::GetInstance().AddScene("마을", "1. 집으로, 2. 숲으로");
	SceneManager::GetInstance().AddScene("숲", "1. 마을로");

	SceneManager::GetInstance().SetCurrentScene("시작");
	SceneManager::GetInstance().ShowCurrentScene();
}