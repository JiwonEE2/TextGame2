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
	// Ű�� ���⿡? enum����?
	
}

void Player::GetKey()
{
	key = _getch();
	switch (key) {
		// enter, spacebar
	case 13:
	case 32:
		cout << "���͸� �ƴ�\n";
		break;
		// ��,�ҹ��� ���
	case 87:
	case 119:
		cout << "��\n";
		break;
	case 83:
	case 115:
		cout << "��\n";
		break;
	case 65:
	case 97:
		cout << "��\n";
		break;
	case 68:
	case 100:
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