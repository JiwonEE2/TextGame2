#pragma once
#include<iostream>
using namespace std;

class Player
{
	bool pressEnter;
	char key;
	int experience;
	int maxExperience;
	int level;
	bool pressAttack = false;
protected:
	string name;
	int x, y;
	int attack;
	int health;
	int maxHealth;
	bool isDeath = false;
public:
	Player() {}
	Player(const string& name);
	int GetX()const;
	int GetY()const;
	bool GetIsChoice();
	void SetIsChoice(bool is);
	void SetXY(int x, int y);
	void InputKey(int n);
	void PrintStatus()const;
	int GetAttack();
	int GetHealth();
	bool GetIsDeath();
	void SetIsDeath(bool is);
	void LevelUp()const;
	bool GetPressAttack()const;
	void SetPressAttack(bool is);
	void Attacked(Player* other);
	virtual void Print()const;
};