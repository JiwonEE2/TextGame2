#include "EarthWorm.h"

EarthWorm::EarthWorm()
{
	name = "earthWorm";
	attack = 1;
	health = 5;
	x = rand() % 15 + 1;
	y = rand() % 17 + 1;
}

void EarthWorm::Print() const
{
	cout << name << "�� x : " << x << ", y : " << y << "�� �����Ǿ����ϴ�.\n";
}