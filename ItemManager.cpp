#include "ItemManager.h"

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
}

void ItemManager::AddItem(int index, const string& name, int attack, int health, int money)
{
	items[index] = new Item(name, attack, health, money);
}

int ItemManager::GetItemNumber() const
{
	return items.size();
}

void ItemManager::ShowItem() const
{
	currentItem->Print();
}

void ItemManager::SetCurrentItem(int index)
{
	currentItem = items[index];
}

int ItemManager::GetItemMoney() const
{
	return currentItem->GetMoney();
}