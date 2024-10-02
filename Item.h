#pragma once
#include<iostream>
using namespace std;
class Item
{
	string name;
	int attack;
	int health;
public:
	Item(string n, int a, int h);
	void Print()const;
};