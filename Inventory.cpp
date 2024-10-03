#include "Inventory.h"

void Inventory::AddItem()
{
	// currentItem을 Inventory에 넣어야함
	items[items.size() + 1] = new Item(
		ItemManager::GetInstance().GetItemName(),
		ItemManager::GetInstance().GetItemType(),
		ItemManager::GetInstance().GetItemAttack(),
		ItemManager::GetInstance().GetItemDefense(),
		ItemManager::GetInstance().GetItemHealth(),
		ItemManager::GetInstance().GetItemMoney());
}

void Inventory::DeleteItem(int slotIndex)
{
	for (int i = slotIndex;i < items.size();i++) {
		items[i] = items[i + 1];
	}
	items.erase(items.size());
}

int Inventory::GetItemNumber() const
{
	return items.size();
}

void Inventory::SetCurrentItem(int invenSlot)
{
	currentItem = items[invenSlot];
}

void Inventory::ShowItems() const
{
	if (currentItem == nullptr)cout << "비어있음\n";
	else currentItem->Print();
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

string Inventory::GetItemName() const
{
	return currentItem->GetName();
}

string Inventory::GetItemType() const
{
	return currentItem->GetType();
}

int Inventory::GetItemAttack() const
{
	return currentItem->GetAttack();
}

int Inventory::GetItemDefense() const
{
	return currentItem->GetDefense();
}

int Inventory::GetItemHealth() const
{
	return currentItem->GetHealth();
}

int Inventory::GetItemMoney() const
{
	return currentItem->GetMoney();
}

void Inventory::EquipItem(int index)
{
	equippedItems[index] = new Item(
		GetItemName(),
		GetItemType(),
		GetItemAttack(),
		GetItemDefense(),
		GetItemHealth(),
		GetItemMoney());
}

string Inventory::GetEquippedName(int index)
{
	currentEquipped = equippedItems[index];
	return currentEquipped->GetName();
}

string Inventory::GetEquippedType(int index)
{
	currentEquipped = equippedItems[index];
	return currentEquipped->GetType();
}

int Inventory::GetEquippedAttack(int index)
{
	currentEquipped = equippedItems[index];
	return currentEquipped->GetAttack();
}

int Inventory::GetEquippedDefense(int index)
{
	currentEquipped = equippedItems[index];
	return currentEquipped->GetDefense();
}

int Inventory::GetEquippedHealth(int index)
{
	currentEquipped = equippedItems[index];
	return currentEquipped->GetHealth();
}

int Inventory::GetEquippedMoney(int index)
{
	currentEquipped = equippedItems[index];
	return currentEquipped->GetMoney();
}

bool Inventory::IsEquippedWeapon() const
{
	return isEquippedWeapon;
}

bool Inventory::IsEquippedHelmet() const
{
	return isEquippedHelmet;
}

bool Inventory::IsEquippedChestplate() const
{
	return isEquippedChestplate;
}

bool Inventory::IsEquippedLeggings() const
{
	return isEquippedLeggings;
}

bool Inventory::IsEquippedBoots() const
{
	return isEquippedBoots;
}

void Inventory::SetIsEquipped(int index, bool is)
{
	if (index == 0)isEquippedWeapon = is;
	else if (index == 1)isEquippedHelmet = is;
	else if (index == 2)isEquippedChestplate = is;
	else if (index == 3)isEquippedLeggings = is;
	else isEquippedBoots = is;
}

void Inventory::UnEquipItem(int index)
{
	items[items.size() + 1] = new Item(
		GetEquippedName(index),
		GetEquippedType(index),
		GetEquippedAttack(index),
		GetEquippedDefense(index),
		GetEquippedHealth(index),
		GetEquippedMoney(index));
}
