#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	for (auto& pair : scenes)delete pair.second;
}

void SceneManager::AddScene(const string& name, const string& desc, const string& disp)
{
	scenes[name] = new Scene(name, desc, disp);
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

void SceneManager::EditScene(const string& display)
{
	currentScene->SetDisplay(display);
}

void SceneManager::RemoveScene()
{
	delete currentScene;
}