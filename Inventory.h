#pragma once
#include<map>
#include"Item.h"
#include"ItemManager.h"
class Inventory
{
	map<int, Item*>items;
	map<int, Item*>equippedItems;
	Item* currentItem = nullptr;
	Item* currentEquipped = nullptr;
	bool isOpen = false;
	bool isEquippedWeapon = false;
	bool isEquippedHelmet = false;
	bool isEquippedChestplate = false;
	bool isEquippedLeggings = false;
	bool isEquippedBoots = false;
public:
	Inventory() {}
	~Inventory() {}
	void AddItem();
	void DeleteItem(int slotIndex);
	int GetItemNumber()const;
	void SetCurrentItem(int invenSlot);
	void ShowItems()const;
	void ToggleInven();
	bool GetIsOpen()const;
	void SetIsOpen(bool is);

	string GetItemName()const;
	string GetItemType()const;
	int GetItemAttack()const;
	int GetItemDefense()const;
	int GetItemHealth()const;
	int GetItemMoney()const;

	void EquipItem(int index);
	string GetEquippedName(int index);
	string GetEquippedType(int index);
	int GetEquippedAttack(int index);
	int GetEquippedDefense(int index);
	int GetEquippedHealth(int index);
	int GetEquippedMoney(int index);
	bool IsEquippedWeapon()const;
	bool IsEquippedHelmet()const;
	bool IsEquippedChestplate()const;
	bool IsEquippedLeggings()const;
	bool IsEquippedBoots()const;
	void SetIsEquipped(int index, bool is);
	void UnEquipItem(int index);
};