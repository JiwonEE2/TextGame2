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
	cout << name << "�� x : " << mx << ", y : " << my << "�� �����Ǿ����ϴ�.\n";
}