#include "Inventory.h"

void Inventory::AddItem()
{
	// currentItem�� Inventory�� �־����
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
	if (items[i] == nullptr)cout << "�������\n";
	else items[i]->Print();
}

void Inventory::ToggleInven()
{
	if (isOpen == false) {
		isOpen = true;
		// cout << "�κ��丮�� ���Ƚ��ϴ�.\n";
	}
	else {
		isOpen = false;
		// cout << "�κ��丮�� �������ϴ�.\n";
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