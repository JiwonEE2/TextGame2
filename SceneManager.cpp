#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	for (auto& pair : scenes)delete pair.second;
}

void SceneManager::AddScene(const string& name, const string& desc)
{
	scenes[name] = new Scene(name, desc);
}

void SceneManager::SetCurrentScene(const string& name)
{
	if (scenes.find(name) != scenes.end()) {
		currentScene = scenes[name];
		cout << "현재 씬을 " << name << "으로 설정하였습니다.\n";
	}
	else { cout << "씬을 찾을 수 없습니다.\n"; }
}

void SceneManager::ShowCurrentScene() const
{
	if (currentScene) {
		currentScene->Print();
	}
	else { cout << "설정된 씬이 없습니다.\n"; }
}