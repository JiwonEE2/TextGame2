#pragma once
#include<iostream>
#include"Player.h"
using namespace std;
class DisplayMaker
{
	string startDisp, homeDisp, townDisp, forestDisp;
	Player* pp;
	bool isOut = false;
	Player mp[5];
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
	string GetForestDisp(Player monster[]);
	void MonsterAttack(int i);
};