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

	SceneManager::GetInstance().AddScene("시작", "1. 새 게임, 2. 게임 종료", startDisp);
	SceneManager::GetInstance().AddScene("집", "1. 회복, 2. 마을로", homeDisp);
	SceneManager::GetInstance().AddScene("마을", "1. 집으로, 2. 숲으로", townDisp);
	SceneManager::GetInstance().AddScene("숲", "1. 마을로", forestDisp);

	SceneManager::GetInstance().SetCurrentScene("시작");
	SceneManager::GetInstance().ShowCurrentScene();

	while (true) {
		player.SetPosition(1);
		displayMaker.GetStartDisp();
	}
}