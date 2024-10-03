#pragma once
#include<map>
#include"Item.h"
#include"ItemManager.h"
class Inventory
{
	map<int, Item*>items;
	Item* currentItem = nullptr;
	bool isOpen = false;
public:
	Inventory() {}
	~Inventory() {}
	void AddItem();
	void SetCurrentItem(int invenSlot);
	void ShowItems();
	void ToggleInven();
};