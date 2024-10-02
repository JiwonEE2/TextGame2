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
	int money;
protected:
	string name;
	int x, y;
	int attack;
	int health;
	int maxHealth;
	bool isDeath = false;
	int experience;
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
	int GetAttack();
	int GetHealth();
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
	void ShowInventory()const;
	void AddItem()const;
};