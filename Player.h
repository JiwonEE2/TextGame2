#pragma once
#include<iostream>
using namespace std;

class Player
{
	string name;
	int attack;
	int health;
	int experience;
	int level;
public:
	Player(const string& name);
	void Move()const;
	void LevelUp()const;
	void Attack()const;
	void Attacked()const;
};