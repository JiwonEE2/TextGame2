#include "ItemManager.h"

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
	for (auto& pair : items)delete pair.second;
}

void ItemManager::AddItem(const string& name, int attack, int health)
{
	items[name] = new Item(name, attack, health);
}