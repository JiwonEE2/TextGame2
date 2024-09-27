#pragma once
#include<iostream>
using namespace std;

class Player
{
	string name;
	int x, y;
	char key;
	int attack;
	int health;
	int experience;
	int level;
public:
	Player(const string& name);
	void SetPosition();
	void GetKey();
	void LevelUp()const;
	void Attack()const;
	void Attacked()const;
};