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
	void AddItem(int index, const string& name, const string& type, int attack, int defense, int health, int money);
	int GetItemNumber()const;
	void ShowItem()const;
	void SetCurrentItem(int index);
	string GetItemName()const;
	string GetItemType()const;
	int GetItemAttack()const;
	int GetItemDefense()const;
	int GetItemHealth()const;
	int GetItemMoney()const;
};