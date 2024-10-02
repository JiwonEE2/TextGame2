#pragma once
#include<map>
#include"Item.h"
#include"ItemManager.h"
class Inventory
{
	map<int, Item*>items;
	Item* currentItem = nullptr;
public:
	Inventory() {}
	~Inventory() {}
	void AddItem();
	void SetCurrentItem(int invenSlot);
	void ShowItems();
};