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
	void DeleteItem(int slotIndex);
	int GetItemNumber()const;
	void SetCurrentItem(int invenSlot);
	void ShowItems()const;
	void ToggleInven();
	bool GetIsOpen()const;
	void SetIsOpen(bool is);

	string GetItemType()const;
	int GetItemAttack()const;
	int GetItemDefense()const;
	int GetItemHealth()const;
};