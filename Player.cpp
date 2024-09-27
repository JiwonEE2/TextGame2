#include "Player.h"
#include<conio.h>

Player::Player(const string& name)
{
	this->name = name;
	x = 1, y = 1;
	isChoice = false;
	attack = 10;
	health = 100;
	experience = 0;
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

void Player::SetPosition(int n)
{
	if (n == 1) {
		GetKey();
		x = 1;
		if (y <= 1)y = 1;
		else if (y >= 2)y = 2;
		if (isChoice == true) {
			cout << x <<", " << y << "를 선택\n";
			isChoice = false;
		}
	}
	// 키를 여기에? enum으로?
	
}

void Player::GetKey()
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
		cout << "상\n"<<y;
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
		break;
	}
}

void Player::LevelUp() const
{
}

void Player::Attack() const
{
}

void Player::Attacked() const
{
}