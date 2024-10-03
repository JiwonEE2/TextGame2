#pragma once
#include<iostream>
using namespace std;
class Item
{
	string name;
	string type;
	int attack;
	int defense;
	int health;
	int money;
public:
	Item(string n, string t, int a, int d, int h, int m);
	void Print()const;

	string GetName()const;
	string GetType()const;
	int GetAttack()const;
	int GetDefense()const;
	int GetHealth()const;
	int GetMoney()const;
};