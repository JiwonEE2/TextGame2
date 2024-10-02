#pragma once
#include<map>
#include"Singleton.h"
#include"Item.h"
class ItemManager :public Singleton<ItemManager>
{
	map<int, Item*>items;
	Item* currentItem = nullptr;
public:
	ItemManager();
	~ItemManager();
	void AddItem(int index, const string& name, int attack, int health, int money);
	int GetItemNumber()const;
	void ShowItem()const;
	void SetCurrentItem(int index);
	string GetItemName()const;
	int GetItemAttack()const;
	int GetItemHealth()const;
	int GetItemMoney()const;
};