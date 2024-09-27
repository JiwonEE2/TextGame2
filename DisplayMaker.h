#pragma once
#include<iostream>
#include"Player.h"
using namespace std;
class DisplayMaker
{
	string startDisp, homeDisp, townDisp, forestDisp;
	Player* pp;
public:
	DisplayMaker();
	DisplayMaker(Player* player);
	string GetStartDisp();
	string GetHomeDisp();
	string GetTownDisp();
	string GetForestDisp();
};