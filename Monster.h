#pragma once
#include<iostream>
using namespace std;

class Monster
{
protected:
	string name;
	int attack;
	int health;
	int mx;
	int my;
public:
	Monster();
	virtual void Print()const;
};