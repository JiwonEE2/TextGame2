#include "EarthWorm.h"

EarthWorm::EarthWorm()
{
	name = "earthWorm";
	attack = 1;
	health = 5;
	mx = rand() % 18 + 1;
	my = rand() % 18 + 1;
}

void EarthWorm::Print() const
{
	cout << name << "�� x : " << mx << ", y : " << my << "�� �����Ǿ����ϴ�.\n";
}