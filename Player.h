#pragma once
#include<iostream>
using namespace std;

class Player
{
	bool isChoice;
	char key;
	int experience;
	int level;
protected:
	string name;
	int x, y;
	int attack;
	int health;
public:
	Player() {}
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
	virtual void Print()const;
};