#include "Key.h"
#include<iostream>
#include<conio.h>
using namespace std;

void Key::GetKey()
{
	key = _getch();
	if (key == 224) {
		key = _getch();
		switch (key) {
		// enter, spacebar
		case 13:
		case 32:
			Enter();
			break;
		// ��,�ҹ��� ���
		case 87:
		case 119:
			Up();
			break;
		case 83:
		case 115:
			Down();
			break;
		case 65:
		case 97:
			Left();
			break;
		case 68:
		case 100:
			Right();
			break;
		// J,j
		case 74:
		case 106:
			Attack();
			break;
		}
	}
}

void Key::Enter() const
{
	cout << "����\n";
}

void Key::Up() const
{
	cout << "��\n";
}

void Key::Down() const
{
	cout << "��\n";
}

void Key::Left() const
{
	cout << "��\n";
}

void Key::Right() const
{
	cout << "��\n";
}

void Key::Attack() const
{
	cout << "����Ű\n";
}