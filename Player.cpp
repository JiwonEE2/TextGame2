#include "Player.h"
#include<conio.h>
#include<Windows.h>

Player::Player()
{
	name = "New Player";
	x = 1, y = 1;
	pressEnter = false;
	attack = 3;
	defense = 3;
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
		//cout << "���͸� �ƴ�\n";
		break;
		// ��,�ҹ��� ���
	case 87:
	case 119:
		y--;
		//cout << "��\n" << y;
		break;
	case 83:
	case 115:
		y++;
		//cout << "��\n";
		break;
	case 65:
	case 97:
		x--;
		//cout << "��\n";
		break;
	case 68:
	case 100:
		x++;
		//cout << "��\n";
		break;
	case 73:
	case 105:
		// I,i
		//cout << "�κ��丮Ű\n";
		// �̶� �κ��� �����ų� ������ ��. (�κ������� ���ų� ���;���)
		inventory->ToggleInven();
		break;
	case 74:
	case 106:
		// J,j
		//cout << "����Ű\n";
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
	cout << "���� : " << defense << "\n";
	cout << "����ġ : " << experience << "/" << maxExperience << "\n";
	cout << "�� : " << money << "\n";
	cout << "=========================================== \n";
}

int Player::GetAttack() const
{
	return attack;
}

int Player::GetDefense() const
{
	return defense;
}

int Player::GetHealth() const
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
		defense *= 2;
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

bool Player::GetInvenOpen() const
{
	return inventory->GetIsOpen();
}

int Player::GetItemNumber() const
{
	return inventory->GetItemNumber();
}

void Player::ShowInventoryItem(int i)
{
	inventory->SetCurrentItem(i);
	inventory->ShowItems();
	if (pressEnter) {
		cout << "�������� ��â(���)�Ͻðڽ��ϱ�?\n";
		InputKey(2);
		// �缱������ ��
		if (pressEnter) {
			// �Ҹ�ǰ ����
			if (inventory->GetItemType() == "�Ҹ�ǰ") {
				attack += inventory->GetItemAttack();
				defense += inventory->GetItemDefense();
				health += inventory->GetItemHealth();
				if (health >= maxHealth)health = maxHealth;
				inventory->DeleteItem(i);
			}
			// weapon ����
			else if (inventory->GetItemType() == "����") {
				// weapon �����Ǿ� ���� ��
				if (inventory->IsEquippedWeapon()) {
					cout << inventory->GetEquippedName(0) << "�� ����Ǿ����ϴ�\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(0);
					defense -= inventory->GetEquippedDefense(0);
					health -= inventory->GetEquippedHealth(0);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// ���� �����ϰ� �ִ� ������ �κ��丮 ���ʿ� �߰�
					inventory->UnEquipItem(0);
					// ����
					inventory->EquipItem(0);
					// �κ����� ������ ������ ����
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "�� �����Ͽ����ϴ�.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// ����0��(����)�� ���� ���õ� ������ �߰�
					inventory->EquipItem(0);
					inventory->SetIsEquipped(0, true);
					inventory->DeleteItem(i);
				}
			}
			// helmet ����
			else if (inventory->GetItemType() == "����") {
				// helmet �����Ǿ� ���� ��
				if (inventory->IsEquippedHelmet()) {
					cout << inventory->GetEquippedName(1) << "�� ����Ǿ����ϴ�\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(1);
					defense -= inventory->GetEquippedDefense(1);
					health -= inventory->GetEquippedHealth(1);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// ���� �����ϰ� �ִ� ������ �κ��丮 ���ʿ� �߰�
					inventory->UnEquipItem(1);
					// ����
					inventory->EquipItem(1);
					// �κ����� ������ ������ ����
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "�� �����Ͽ����ϴ�.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					inventory->EquipItem(1);
					inventory->SetIsEquipped(1, true);
					inventory->DeleteItem(i);
				}
			}
			// chestplate ����
			else if (inventory->GetItemType() == "����") {
				// �����Ǿ� ���� ��
				if (inventory->IsEquippedChestplate()) {
					cout << inventory->GetEquippedName(2) << "�� ����Ǿ����ϴ�\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(2);
					defense -= inventory->GetEquippedDefense(2);
					health -= inventory->GetEquippedHealth(2);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// ���� �����ϰ� �ִ� ������ �κ��丮 ���ʿ� �߰�
					inventory->UnEquipItem(2);
					// ����
					inventory->EquipItem(2);
					// �κ����� ������ ������ ����
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "�� �����Ͽ����ϴ�.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					inventory->EquipItem(2);
					inventory->SetIsEquipped(2, true);
					inventory->DeleteItem(i);
				}
			}
			// leggings ����
			else if (inventory->GetItemType() == "����") {
				// �����Ǿ� ���� ��
				if (inventory->IsEquippedLeggings()) {
					cout << inventory->GetEquippedName(3) << "�� ����Ǿ����ϴ�\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(3);
					defense -= inventory->GetEquippedDefense(3);
					health -= inventory->GetEquippedHealth(3);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// ���� �����ϰ� �ִ� ������ �κ��丮 ���ʿ� �߰�
					inventory->UnEquipItem(3);
					// ����
					inventory->EquipItem(3);
					// �κ����� ������ ������ ����
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "�� �����Ͽ����ϴ�.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					inventory->EquipItem(3);
					inventory->SetIsEquipped(3, true);
					inventory->DeleteItem(i);
				}
			}
			// boot ����
			else if (inventory->GetItemType() == "����") {
				// �����Ǿ� ���� ��
				if (inventory->IsEquippedBoots()) {
					cout << inventory->GetEquippedName(4) << "�� ����Ǿ����ϴ�\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(4);
					defense -= inventory->GetEquippedDefense(4);
					health -= inventory->GetEquippedHealth(4);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// ���� �����ϰ� �ִ� ������ �κ��丮 ���ʿ� �߰�
					inventory->UnEquipItem(4);
					// ����
					inventory->EquipItem(4);
					// �κ����� ������ ������ ����
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "�� �����Ͽ����ϴ�.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					inventory->EquipItem(4);
					inventory->SetIsEquipped(4, true);
					inventory->DeleteItem(i);
				}
			}
		}
	}
}

void Player::AddItem() const
{
	inventory->AddItem();
}