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
		cout << "���� ���� " << name << "���� �����Ͽ����ϴ�.\n";
	}
	else { cout << "���� ã�� �� �����ϴ�.\n"; }
}

void SceneManager::ShowCurrentScene() const
{
	if (currentScene) {
		currentScene->Print();
	}
	else { cout << "������ ���� �����ϴ�.\n"; }
}