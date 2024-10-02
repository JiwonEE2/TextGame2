#pragma once
#include<iostream>
using namespace std;
class Item
{
	string name;
	int attack;
	int health;
	int money;
public:
	Item(string n, int a, int h, int m);
	void Print()const;
	int GetAttack();
	int GetHealth();
	int GetMoney();
};