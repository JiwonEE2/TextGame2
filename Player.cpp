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
	// 1������ ���(���� ��)
	if (n == 1) {
		GetKey();
		x = 1;
		if (y <= 1)y = 1;
		else if (y >= 2)y = 2;
		if (isChoice == true) {
			cout << x <<", " << y << "�� ����\n";
			isChoice = false;
		}
	}	
}

void Player::GetKey()
{
	key = _getch();
	switch (key) {
		// enter, spacebar
	case 13:
	case 32:
		isChoice = true;
		cout << "���͸� �ƴ�\n";
		break;
		// ��,�ҹ��� ���
	case 87:
	case 119:
		y--;
		cout << "��\n"<<y;
		break;
	case 83:
	case 115:
		y++;
		cout << "��\n";
		break;
	case 65:
	case 97:
		x--;
		cout << "��\n";
		break;
	case 68:
	case 100:
		x++;
		cout << "��\n";
		break;
		// J,j
	case 74:
	case 106:
		cout << "����Ű\n";
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