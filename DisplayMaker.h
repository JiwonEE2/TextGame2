#pragma once
#include<iostream>
#include"Player.h"
using namespace std;
class DisplayMaker
{
	string startDisp, homeDisp, townDisp, forestDisp;
	Player* pp;
	bool isOut = false;
public:
	DisplayMaker(Player* player);
	string GetStartDisp();
	string GetHomeDisp();
	void IsBed()const;
	bool GetIsOut();
	void IsOut();
	string GetTownDisp();
	string GetForestDisp();
};