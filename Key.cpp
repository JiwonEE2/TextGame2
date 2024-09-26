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
		// 대,소문자 허용
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
	cout << "엔터\n";
}

void Key::Up() const
{
	cout << "상\n";
}

void Key::Down() const
{
	cout << "하\n";
}

void Key::Left() const
{
	cout << "좌\n";
}

void Key::Right() const
{
	cout << "우\n";
}

void Key::Attack() const
{
	cout << "공격키\n";
}