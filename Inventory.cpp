#include "Inventory.h"

void Inventory::AddItem()
{
	// currentItem�� Inventory�� �־����
	this->items[items.size() + 1] = new Item(ItemManager::GetInstance().GetItemName(), ItemManager::GetInstance().GetItemAttack(), ItemManager::GetInstance().GetItemHealth(), ItemManager::GetInstance().GetItemMoney());
}

void Inventory::SetCurrentItem(int invenSlot)
{
	currentItem = items[invenSlot];
}

void Inventory::ShowItems()
{
	cout << "~~~ ���� ���� �����۵� ~~~\n";
	for (int i = 1; i < items.size() + 1; i++) {
		SetCurrentItem(i);
		items[i]->Print();
	}
}
