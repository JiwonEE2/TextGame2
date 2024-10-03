#include "Inventory.h"

void Inventory::AddItem()
{
	// currentItem을 Inventory에 넣어야함
	this->items[items.size() + 1] = new Item(
		ItemManager::GetInstance().GetItemName(),
		ItemManager::GetInstance().GetItemType(),
		ItemManager::GetInstance().GetItemAttack(),
		ItemManager::GetInstance().GetItemDefense(),
		ItemManager::GetInstance().GetItemHealth(),
		ItemManager::GetInstance().GetItemMoney());
}

int Inventory::GetItemNumber() const
{
	return items.size();
}

void Inventory::SetCurrentItem(int invenSlot)
{
	currentItem = items[invenSlot];
}

void Inventory::ShowItems(int i)
{
	if (items[i] == nullptr)cout << "비어있음\n";
	else items[i]->Print();
}

void Inventory::ToggleInven()
{
	if (isOpen == false) {
		isOpen = true;
		// cout << "인벤토리가 열렸습니다.\n";
	}
	else {
		isOpen = false;
		// cout << "인벤토리가 닫혔습니다.\n";
	}
}

bool Inventory::GetIsOpen() const
{
	return isOpen;
}

void Inventory::SetIsOpen(bool is)
{
	isOpen = is;
}