#include "Item.h"

Item::Item(string n, string t, int a, int d, int h, int m)
{
	name = n;
	type = t;
	attack = a;
	defense = d;
	health = h;
	money = m;
}

void Item::Print() const
{
	cout << "--- ������ ���� ---\n";
	cout << "�̸� : " << name << "\n";
	cout << "Ÿ�� : " << type << "\n";
	cout << "���ݷ� : " << attack << "\n";
	cout << "���� : " << defense << "\n";
	cout << "ü�� : " << health << "\n";
	cout << "���� : " << money << "\n";
}

string Item::GetName() const
{
	return name;
}

string Item::GetType() const
{
	return type;
}

int Item::GetAttack() const
{
	return attack;
}

int Item::GetDefense() const
{
	return defense;
}

int Item::GetHealth() const
{
	return health;
}

int Item::GetMoney() const
{
	return money;
}