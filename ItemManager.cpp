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

string ItemManager::GetItemName() const
{
	return currentItem->GetName();
}

int ItemManager::GetItemAttack() const
{
	return currentItem->GetAttack();
}

int ItemManager::GetItemHealth() const
{
	return currentItem->GetHealth();
}

int ItemManager::GetItemMoney() const
{
	return currentItem->GetMoney();
}