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
	cout << "--- 아이템 정보 ---\n";
	cout << "이름 : " << name << "\n";
	cout << "공격력 : " << attack << "\n";
	cout << "체력 : " << health << "\n";
	cout << "가격 : " << money << "\n";
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