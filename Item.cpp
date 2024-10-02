#include "Item.h"

Item::Item(string n, int a, int h, int m)
{
	name = n;
	attack = a;
	health = h;
	money = m;
}

void Item::Print() const
{
	cout << "--- ������ ���� ---\n";
	cout << "�̸� : " << name << "\n";
	cout << "���ݷ� : " << attack << "\n";
	cout << "ü�� : " << health << "\n";
	cout << "���� : " << money << "\n";
}

string Item::GetName()
{
	return name;
}

int Item::GetAttack()
{
	return attack;
}

int Item::GetHealth()
{
	return health;
}

int Item::GetMoney()
{
	return money;
}