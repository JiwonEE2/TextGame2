#include "Player.h"
#include<conio.h>

Player::Player(const string& name)
{
	this->name = name;
	x = 1, y = 1;
	attack = 10;
	health = 100;
	experience = 0;
	level = 1;
}

void Player::SetPosition()
{
	// 키를 여기에? enum으로?
	
}

void Player::GetKey()
{
	key = _getch();
	switch (key) {
		// enter, spacebar
	case 13:
	case 32:
		cout << "엔터를 쳤다\n";
		break;
		// 대,소문자 허용
	case 87:
	case 119:
		cout << "상\n";
		break;
	case 83:
	case 115:
		cout << "하\n";
		break;
	case 65:
	case 97:
		cout << "좌\n";
		break;
	case 68:
	case 100:
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