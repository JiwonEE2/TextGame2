#include "Item.h"

Item::Item(string n, int a, int h)
{
	name = n;
	attack = a;
	health = h;
}

void Item::Print() const
{
	cout << "--- ������ ���� ---\n";
	cout << "�̸� : " << name << "\n";
	cout << "���ݷ� : " << attack << "\n";
	cout << "ü�� : " << health << "\n";
}

int Item::GetAttack()
{
	return attack;
}

int Item::GetHealth()
{
	return health;
}
