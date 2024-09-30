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
	cout << name << "가 x : " << mx << ", y : " << my << "에 생성되었습니다.\n";
}