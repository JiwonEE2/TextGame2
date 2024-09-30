#pragma once
#include<iostream>
using namespace std;

class Monster
{
	string name;
	int attack;
	int health;
	int mx;
	int my;
public:
	Monster(const string& name, int attack, int health);
	void Print()const;
};