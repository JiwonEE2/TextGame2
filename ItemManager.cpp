#include "ItemManager.h"

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
}

void ItemManager::AddItem(int index, const string& name, int attack, int health)
{
	items[index] = new Item(name, attack, health);
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