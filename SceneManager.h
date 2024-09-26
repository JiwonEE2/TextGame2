#pragma once
#include<map>
#include"Singleton.h"
#include"Scene.h"

class SceneManager :public Singleton<SceneManager>
{
	map<string, Scene*>scenes;
	Scene* currentScene = nullptr;
public:
	SceneManager();
	~SceneManager();
	void AddScene(const string& name, const string& desc, const string& disp);
	void SetCurrentScene(const string& name);
	void ShowCurrentScene()const;
};