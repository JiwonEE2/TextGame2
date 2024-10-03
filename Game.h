#pragma once
#include<iostream>
#include"Player.h"
#include"EarthWorm.h"
#include"Go.h"
#include"SceneManager.h"
#include"ItemManager.h"
using namespace std;

class Game
{
	string startDisp, homeDisp, townDisp, shopDisp, forestDisp, inventoryDisp;
	Player player;
	Go go;
	Go preGo;
	int homeToTown[2] = { 7,17 };
	int townToHome[2] = { 3,4 };
	int townToShop[2] = { 3,15 };
	int townToForest[2] = { 16,7 };
	int shopToTown[2] = { 16,16 };
	int forestToTown[2] = { 1,7 };
	int quest[2] = { 13,4 };
	int qMoney = 10000, qNow = 0, qAll = 5;
	bool qComplete = false;
	EarthWorm* mp[];
public:
	Game();
	~Game();
	void StartGame();
	string GetStartDisp();
	string GetHomeDisp();
	string GetTownDisp();
	string GetShopDisp();
	string GetForestDisp(EarthWorm monster[]);
	string GetInvenDisp();

	void GoHome();
	void GoTown();
	void GoShop();
	void GoForest();
	void Quest();
	void PrintItem(int i);

	void IsBed();
	void MonsterAttack(int i);
};