#include "Monster.h"

Monster::Monster(const string& name, int attack, int health)
{
	this->name = name;
	this->attack = attack;
	this->health = health;
	mx = rand() % 18 + 1;
	my = rand() % 18 + 1;
}

void Monster::Print() const
{
	cout << name << "가 x : " << mx << ", y : " << my << "에 생성되었습니다.\n";
}