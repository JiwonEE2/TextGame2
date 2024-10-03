#include "ItemManager.h"

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
}

void ItemManager::AddItem(int index, const string& name, const string& type, int attack, int defense, int health, int money)
{
	items[index] = new Item(name, type, attack, defense, health, money);
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

string ItemManager::GetItemType() const
{
	return currentItem->GetType();
}

int ItemManager::GetItemAttack() const
{
	return currentItem->GetAttack();
}

int ItemManager::GetItemDefense() const
{
	return currentItem->GetDefense();
}

int ItemManager::GetItemHealth() const
{
	return currentItem->GetHealth();
}

int ItemManager::GetItemMoney() const
{
	return currentItem->GetMoney();
}