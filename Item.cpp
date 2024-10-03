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
	cout << "--- 아이템 정보 ---\n";
	cout << "이름 : " << name << "\n";
	cout << "타입 : " << type << "\n";
	cout << "공격력 : " << attack << "\n";
	cout << "방어력 : " << defense << "\n";
	cout << "체력 : " << health << "\n";
	cout << "가격 : " << money << "\n";
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