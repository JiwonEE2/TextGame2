#include"SceneManager.h"
int main() {
	string startDisp =
		"--------\n"
		"|start	|\n"
		"--------\n";
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

	SceneManager::GetInstance().AddScene("시작", "1. 새 게임, 2. 게임 종료", startDisp);
	SceneManager::GetInstance().AddScene("집", "1. 회복, 2. 마을로", homeDisp);
	SceneManager::GetInstance().AddScene("마을", "1. 집으로, 2. 숲으로", townDisp);
	SceneManager::GetInstance().AddScene("숲", "1. 마을로", forestDisp);

	SceneManager::GetInstance().SetCurrentScene("시작");
	SceneManager::GetInstance().ShowCurrentScene();
}