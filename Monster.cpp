#include "Monster.h"

Monster::Monster()
{
	name = "monster";
	attack = 0;
	health = 0;
	mx = 0;
	my = 0;
}

void Monster::Print() const
{
	cout << name << "�� x : " << mx << ", y : " << my << "�� �����Ǿ����ϴ�.\n";
}