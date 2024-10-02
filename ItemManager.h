#pragma once
#include<map>
#include"Singleton.h"
#include"Item.h"
class ItemManager :public Singleton<ItemManager>
{
	map<string, Item*>items;
	Item* currentItem = nullptr;
public:
	ItemManager();
	~ItemManager();
	void AddItem(const string& name, int attack, int health);
};