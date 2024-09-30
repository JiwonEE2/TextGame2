#pragma once
#include<iostream>
using namespace std;

class Player
{
	string name;
	int x, y;
	bool isChoice;
	char key;
	int attack;
	int health;
	int experience;
	int level;
public:
	Player(const string& name);
	int GetX()const;
	int GetY()const;
	bool GetIsChoice();
	void SetIsChoice(bool is);
	void SetPosition(int n);
	void SetXY(int x, int y);
	void InputKey();
	void LevelUp()const;
	void Attack()const;
	void Attacked()const;
};