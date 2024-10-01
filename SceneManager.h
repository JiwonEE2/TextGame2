#pragma once
#include<map>
#include"Singleton.h"
#include"Scene.h"
#include"Player.h"

class SceneManager :public Singleton<SceneManager>
{
	map<string, Scene*>scenes;
	Scene* currentScene = nullptr;
	Player player;
public:
	SceneManager();
	~SceneManager();
	void AddScene(const string& name, const string& desc, const string& disp);
	void SetCurrentScene(const string& name);
	void ShowCurrentScene()const;
	void EditScene(const string& display);
};