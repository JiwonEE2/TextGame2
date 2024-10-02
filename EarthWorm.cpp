#include "EarthWorm.h"

EarthWorm::EarthWorm()
{
	name = "earthWorm";
	attack = 1;
	health = 5;
	x = rand() % 15 + 1;
	y = rand() % 17 + 1;
	experience = 700;
}

void EarthWorm::Print() const
{
	cout << name << "가 x : " << x << ", y : " << y << "에 생성되었습니다.\n";
}

int EarthWorm::GetExperience()
{
	return experience;
}