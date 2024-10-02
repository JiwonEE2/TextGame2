#include "Item.h"

Item::Item(string n, int a, int h)
{
	name = n;
	attack = a;
	health = h;
}

void Item::Print() const
{
	cout << "--- 아이템 정보 ---\n";
	cout << "이름 : " << name << "\n";
	cout << "공격력 : " << attack << "\n";
	cout << "체력 : " << health << "\n";
}