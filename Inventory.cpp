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
	if (isOpen) {
		cout << "~~~ 인벤토리 ~~~\n";
		for (int i = 1; i < items.size() + 1; i++) {
			SetCurrentItem(i);
			items[i]->Print();
		}
		cout << "~~~~~~~~~~~~~~~~\n";
	}
}

void Inventory::ToggleInven()
{
	if (!isOpen) {
		isOpen = true;
		// cout << "인벤토리가 열렸습니다.\n";
	}
	else {
		isOpen = false;
		// cout << "인벤토리가 닫혔습니다.\n";
	}
}