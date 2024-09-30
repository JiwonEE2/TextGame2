#pragma once
#include<iostream>
using namespace std;

class Player
{
	bool isChoice;
	char key;
	int experience;
	int maxExperience;
	int level;
protected:
	string name;
	int x, y;
	int attack;
	int health;
	int maxHealth;
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
	void PrintStatus()const;
	int GetAttack();
	void LevelUp()const;
	void Attack()const;
	void Attacked(Player other);
	virtual void Print()const;
};