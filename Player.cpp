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
	cout << "당신의 이름은 : ";
	cin >> n;
	name = n;
	cout << name << "이라는 이름은 참 좋습니다^^\n";
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
	case 73:
	case 105:
		// I,i
		cout << "인벤토리키\n";
		inventory->ToggleInven();
		break;
	case 74:
	case 106:
		// J,j
		cout << "공격키\n";
		pressAttack = true;
		break;
	}

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

	system("cls");
}

void Player::PrintStatus() const
{
	cout << "=============== " << name << " (Lv. " << level << ") =============== \n";
	cout << "체력 : " << health << "/" << maxHealth << "\n";
	cout << "공격력 : " << attack << "\n";
	cout << "경험치 : " << experience << "/" << maxExperience << "\n";
	cout << "돈 : " << money << "\n";
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
		cout << "레벨업 !!!!!!\n";
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
	cout << name << "가 x : " << x << ", y : " << y << "에 생성되었습니다.\n";
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