#include "Player.h"
#include<conio.h>

Player::Player(const string& name)
{
	this->name = name;
	x = 1, y = 1;
	isChoice = false;
	attack = 3;
	health = 20;
	maxHealth = 20;
	experience = 0;
	maxExperience = 1000;
	level = 1;
}

int Player::GetX() const
{
	return x;
}

int Player::GetY() const
{
	return y;
}

bool Player::GetIsChoice()
{
	return isChoice;
}

void Player::SetIsChoice(bool is)
{
	isChoice = is;
}

void Player::SetMoveLine(int n)
{
	// 1번씬일 경우(시작 씬)
	if (n == 1) {
		if (y <= 1)y = 1;
		else if (y >= 2)y = 2;
	}
	else {
		if (x <= 0)x = 0;
		else if (x >= 16)x = 16;
		if (y <= 1)y = 1;
		else if (y >= 18)y = 18;
	}
}

void Player::SetXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Player::InputKey()
{
	key = _getch();
	switch (key) {
		// enter, spacebar
	case 13:
	case 32:
		isChoice = true;
		cout << "엔터를 쳤다\n";
		break;
		// 대,소문자 허용
	case 87:
	case 119:
		y--;
		cout << "상\n" << y;
		break;
	case 83:
	case 115:
		y++;
		cout << "하\n";
		break;
	case 65:
	case 97:
		x--;
		cout << "좌\n";
		break;
	case 68:
	case 100:
		x++;
		cout << "우\n";
		break;
		// J,j
	case 74:
	case 106:
		cout << "공격키\n";
		pressAttack = true;
		break;
	}
}

void Player::PrintStatus() const
{
	cout << "=============== " << name << " (Lv. " << level << ") =============== \n";
	cout << "체력 : " << health << "/" << maxHealth << "\n";
	cout << "공격력 : " << attack << "\n";
	cout << "경험치 : " << experience << "/" << maxExperience << "\n";
	cout << "=========================================== \n";
}

int Player::GetAttack()
{
	return attack;
}

int Player::GetHealth()
{
	return health;
}

bool Player::GetIsDeath() const
{
	return isDeath;
}

void Player::SetIsDeath(bool is)
{
	isDeath = is;
}

void Player::DeathCheck()
{
	if (health <= 0) {
		cout << name << "은 사망했습니다\n";
		isDeath = true;
	}
}

void Player::LevelUp() const
{
}

bool Player::GetPressAttack() const
{
	return pressAttack;
}

void Player::SetPressAttack(bool is)
{
	pressAttack = is;
}

void Player::Attacked(Player* other)
{
	health -= other->GetAttack();
}

void Player::Print() const
{
	cout << name << "가 x : " << x << ", y : " << y << "에 생성되었습니다.\n";
}