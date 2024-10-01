#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	for (auto& pair : scenes)
		delete pair.second;
}

void SceneManager::AddScene(const string& name, const string& desc)
{
	scenes[name] = new Scene(name, desc);
}

void SceneManager::SetCurrentScene(const string& name)
{
	player.SetIsChoice(false);
	if (scenes.find(name) != scenes.end()) {
		currentScene = scenes[name];
		cout << "���� ���� " << name << "���� �����Ͽ����ϴ�.\n";
	}
	else { cout << "���� ã�� �� �����ϴ�.\n"; }
}

void SceneManager::EditShowCurrentScene(const string& display)
{
	if (currentScene) {
		currentScene->SetPrintDisplay(display);
	}
	else { cout << "������ ���� �����ϴ�.\n"; }
}