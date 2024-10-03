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
	if (isOpen) {
		cout << "~~~ �κ��丮 ~~~\n";
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
		// cout << "�κ��丮�� ���Ƚ��ϴ�.\n";
	}
	else {
		isOpen = false;
		// cout << "�κ��丮�� �������ϴ�.\n";
	}
}