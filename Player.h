#pragma once
#include<iostream>
#include"Inventory.h"
#include"ItemManager.h"
using namespace std;

class Player
{
	bool pressEnter;
	char key;
	int maxExperience;
	int level;
	bool pressAttack = false;
protected:
	string name;
	int x, y;
	int attack;
	int defense;
	int health;
	int maxHealth;
	bool isDeath = false;
	int experience;
	int money;
	Inventory* inventory = new Inventory;
public:
	Player();
	void SetPlayerName();
	string GetName();
	int GetX()const;
	int GetY()const;
	bool GetIsChoice();
	void SetIsChoice(bool is);
	void SetXY(int x, int y);
	void InputKey(int n);
	void PrintStatus()const;

	int GetAttack()const;
	int GetDefense()const;
	int GetHealth()const;

	bool GetIsDeath();
	void SetIsDeath(bool is);
	virtual int GetExperience();
	void UpExperience(Player* other);
	bool GetPressAttack()const;
	void SetPressAttack(bool is);
	void Attacked(Player* other);
	virtual void Print()const;
	void Heal();
	int GetMoney()const;
	void SetMoney(int m);

	bool GetInvenOpen()const;
	int GetItemNumber()const;
	void ShowInventoryItem(int i)const;
	void AddItem()const;
};