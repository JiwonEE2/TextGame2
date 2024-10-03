#include "Player.h"
#include<conio.h>
#include<Windows.h>

Player::Player()
{
	name = "New Player";
	x = 1, y = 1;
	pressEnter = false;
	attack = 3;
	health = 20;
	maxHealth = 20;
	experience = 0;
	maxExperience = 1000;
	level = 1;
	money = 2000;
	inventory;
}

void Player::SetPlayerName()
{
	string n;
	cout << "����� �̸��� : ";
	cin >> n;
	name = n;
	cout << name << "�̶�� �̸��� �� �����ϴ�^^\n";
	Sleep(2000);
	system("cls");
}

string Player::GetName()
{
	return name;
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
	return pressEnter;
}

void Player::SetIsChoice(bool is)
{
	pressEnter = is;
}

void Player::SetXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Player::InputKey(int n)
{
	pressAttack = false;
	pressEnter = false;
	key = _getch();
	switch (key) {
		// enter, spacebar
	case 13:
	case 32:
		pressEnter = true;
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
	case 73:
	case 105:
		// I,i
		cout << "�κ��丮Ű\n";
		inventory->ToggleInven();
		break;
	case 74:
	case 106:
		// J,j
		cout << "����Ű\n";
		pressAttack = true;
		break;
	}

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

	system("cls");
}

void Player::PrintStatus() const
{
	cout << "=============== " << name << " (Lv. " << level << ") =============== \n";
	cout << "ü�� : " << health << "/" << maxHealth << "\n";
	cout << "���ݷ� : " << attack << "\n";
	cout << "����ġ : " << experience << "/" << maxExperience << "\n";
	cout << "�� : " << money << "\n";
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

bool Player::GetIsDeath()
{
	if (health <= 0) {
		isDeath = true;
	}
	return isDeath;
}

void Player::SetIsDeath(bool is)
{
	isDeath = is;
}

int Player::GetExperience()
{
	return experience;
}

void Player::UpExperience(Player* other)
{
	experience += other->GetExperience();
	while (experience >= maxExperience) {
		level++;
		attack *= 2;
		maxHealth *= 2;
		health = maxHealth;
		cout << "������ !!!!!!\n";
		experience -= maxExperience;
	}
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

void Player::Heal()
{
	health = maxHealth;
}

int Player::GetMoney() const
{
	return money;
}

void Player::SetMoney(int m)
{
	money = m;
}

void Player::ShowInventory() const
{
	inventory->ShowItems();
}

void Player::AddItem() const
{
	inventory->AddItem();
}