#pragma once
#include<iostream>
#include"Player.h"
#include"EarthWorm.h"
using namespace std;
class DisplayMaker
{
	string startDisp, homeDisp, townDisp, forestDisp;
	Player* pp;
	bool isOut = false;
	EarthWorm* earthWorms;
public:
	DisplayMaker(Player* player);
	string GetStartDisp();
	string GetHomeDisp();
	void IsBed()const;
	bool GetIsOut();
	void SetIsOut(bool is);
	void IsOut();
	string GetTownDisp();
	void GoHome();
	void GoForest();
	string GetForestDisp();
};