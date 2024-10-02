#pragma once
#include<iostream>
#include"Player.h"
#include"EarthWorm.h"
#include"Go.h"
#include"ItemManager.h"
using namespace std;

class Game
{
	string startDisp, homeDisp, townDisp, shopDisp, forestDisp;
	Player* pp;
	Go go;
	int homeToTown[2] = { 7,17 };
	int townToHome[2] = { 3,4 };
	int townToShop[2] = { 3,15 };
	int townToForest[2] = { 16,7 };
	int shopToTown[2] = { 16,16 };
	int forestToTown[2] = { 1,7 };
	EarthWorm* mp[];
public:
	Game(Player* player);
	~Game();
	string GetStartDisp();
	string GetHomeDisp();
	string GetTownDisp();
	string GetShopDisp();
	string GetForestDisp(EarthWorm monster[]);
	void GoHome();
	void GoTown();
	void GoShop();
	void GoForest();
	void PrintItem(int i);
	Go GetGo()const;
	void SetGo(Go go);

	void IsBed()const;
	void MonsterAttack(int i);
};