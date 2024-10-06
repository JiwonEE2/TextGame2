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
		//cout << "엔터를 쳤다\n";
		break;
		// 대,소문자 허용
	case 87:
	case 119:
		y--;
		//cout << "상\n" << y;
		break;
	case 83:
	case 115:
		y++;
		//cout << "하\n";
		break;
	case 65:
	case 97:
		x--;
		//cout << "좌\n";
		break;
	case 68:
	case 100:
		x++;
		//cout << "우\n";
		break;
	case 73:
	case 105:
		// I,i
		//cout << "인벤토리키\n";
		// 이때 인벤이 열리거나 닫혀야 함. (인벤씬으로 가거나 나와야함)
		inventory->ToggleInven();
		break;
	case 74:
	case 106:
		// J,j
		//cout << "공격키\n";
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
	cout << "방어력 : " << defense << "\n";
	cout << "경험치 : " << experience << "/" << maxExperience << "\n";
	cout << "돈 : " << money << "\n";
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
		cout << "아이템을 작창(사용)하시겠습니까?\n";
		InputKey(2);
		// 재선택했을 시
		if (pressEnter) {
			// 소모품 선택
			if (inventory->GetItemType() == "소모품") {
				attack += inventory->GetItemAttack();
				defense += inventory->GetItemDefense();
				health += inventory->GetItemHealth();
				if (health >= maxHealth)health = maxHealth;
				inventory->DeleteItem(i);
			}
			// weapon 선택
			else if (inventory->GetItemType() == "무기") {
				// weapon 장착되어 있을 시
				if (inventory->IsEquippedWeapon()) {
					cout << inventory->GetEquippedName(0) << "와 변경되었습니다\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(0);
					defense -= inventory->GetEquippedDefense(0);
					health -= inventory->GetEquippedHealth(0);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// 원래 장착하고 있던 아이템 인벤토리 뒤쪽에 추가
					inventory->UnEquipItem(0);
					// 장착
					inventory->EquipItem(0);
					// 인벤에서 장착한 아이템 삭제
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "을 장착하였습니다.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// 장착0번(무기)에 현재 선택된 아이템 추가
					inventory->EquipItem(0);
					inventory->SetIsEquipped(0, true);
					inventory->DeleteItem(i);
				}
			}
			// helmet 선택
			else if (inventory->GetItemType() == "모자") {
				// helmet 장착되어 있을 시
				if (inventory->IsEquippedHelmet()) {
					cout << inventory->GetEquippedName(1) << "와 변경되었습니다\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(1);
					defense -= inventory->GetEquippedDefense(1);
					health -= inventory->GetEquippedHealth(1);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// 원래 장착하고 있던 아이템 인벤토리 뒤쪽에 추가
					inventory->UnEquipItem(1);
					// 장착
					inventory->EquipItem(1);
					// 인벤에서 장착한 아이템 삭제
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "을 장착하였습니다.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					inventory->EquipItem(1);
					inventory->SetIsEquipped(1, true);
					inventory->DeleteItem(i);
				}
			}
			// chestplate 선택
			else if (inventory->GetItemType() == "갑옷") {
				// 장착되어 있을 시
				if (inventory->IsEquippedChestplate()) {
					cout << inventory->GetEquippedName(2) << "와 변경되었습니다\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(2);
					defense -= inventory->GetEquippedDefense(2);
					health -= inventory->GetEquippedHealth(2);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// 원래 장착하고 있던 아이템 인벤토리 뒤쪽에 추가
					inventory->UnEquipItem(2);
					// 장착
					inventory->EquipItem(2);
					// 인벤에서 장착한 아이템 삭제
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "을 장착하였습니다.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					inventory->EquipItem(2);
					inventory->SetIsEquipped(2, true);
					inventory->DeleteItem(i);
				}
			}
			// leggings 선택
			else if (inventory->GetItemType() == "바지") {
				// 장착되어 있을 시
				if (inventory->IsEquippedLeggings()) {
					cout << inventory->GetEquippedName(3) << "와 변경되었습니다\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(3);
					defense -= inventory->GetEquippedDefense(3);
					health -= inventory->GetEquippedHealth(3);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// 원래 장착하고 있던 아이템 인벤토리 뒤쪽에 추가
					inventory->UnEquipItem(3);
					// 장착
					inventory->EquipItem(3);
					// 인벤에서 장착한 아이템 삭제
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "을 장착하였습니다.\n";
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					inventory->EquipItem(3);
					inventory->SetIsEquipped(3, true);
					inventory->DeleteItem(i);
				}
			}
			// boot 선택
			else if (inventory->GetItemType() == "부츠") {
				// 장착되어 있을 시
				if (inventory->IsEquippedBoots()) {
					cout << inventory->GetEquippedName(4) << "와 변경되었습니다\n";
					Sleep(1000);
					attack -= inventory->GetEquippedAttack(4);
					defense -= inventory->GetEquippedDefense(4);
					health -= inventory->GetEquippedHealth(4);
					attack += inventory->GetItemAttack();
					defense += inventory->GetItemDefense();
					health += inventory->GetItemHealth();
					if (health >= maxHealth)health = maxHealth;
					// 원래 장착하고 있던 아이템 인벤토리 뒤쪽에 추가
					inventory->UnEquipItem(4);
					// 장착
					inventory->EquipItem(4);
					// 인벤에서 장착한 아이템 삭제
					inventory->DeleteItem(i);
				}
				else {
					cout << inventory->GetItemName() << "을 장착하였습니다.\n";
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