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
	// 1������ ���(���� ��)
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
		cout << "���͸� �ƴ�\n";
		break;
		// ��,�ҹ��� ���
	case 87:
	case 119:
		y--;
		cout << "��\n" << y;
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
		pressAttack = true;
		break;
	}
}

void Player::PrintStatus() const
{
	cout << "=============== " << name << " (Lv. " << level << ") =============== \n";
	cout << "ü�� : " << health << "/" << maxHealth << "\n";
	cout << "���ݷ� : " << attack << "\n";
	cout << "����ġ : " << experience << "/" << maxExperience << "\n";
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
		cout << name << "�� ����߽��ϴ�\n";
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
	cout << name << "�� x : " << x << ", y : " << y << "�� �����Ǿ����ϴ�.\n";
}