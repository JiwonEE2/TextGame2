#pragma once
#include<iostream>
#include"Player.h"
#include"EarthWorm.h"
using namespace std;
class Game
{
	string startDisp, homeDisp, townDisp, forestDisp;
	Player* pp;
	int go;
	EarthWorm* mp[];
public:
	Game(Player* player);
	string GetStartDisp();
	string GetHomeDisp();
	void IsBed()const;
	void GoTown();
	string GetTownDisp();
	void GoHome();
	void GoForest();
	string GetForestDisp(EarthWorm ew[]);
	void MonsterAttack(int i);
	int GetGo()const;
	void SetGo(int go);
};