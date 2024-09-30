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
	cout << name << "가 x : " << mx << ", y : " << my << "에 생성되었습니다.\n";
}