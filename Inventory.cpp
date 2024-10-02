#include "Inventory.h"

void Inventory::AddItem()
{
	// currentItem을 Inventory에 넣어야함
	this->items[items.size() + 1] = new Item(ItemManager::GetInstance().GetItemName(), ItemManager::GetInstance().GetItemAttack(), ItemManager::GetInstance().GetItemHealth(), ItemManager::GetInstance().GetItemMoney());
}

void Inventory::SetCurrentItem(int invenSlot)
{
	currentItem = items[invenSlot];
}

void Inventory::ShowItems()
{
	cout << "~~~ 내가 가진 아이템들 ~~~\n";
	for (int i = 1; i < items.size() + 1; i++) {
		SetCurrentItem(i);
		items[i]->Print();
	}
}
