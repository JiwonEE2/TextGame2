#pragma once
#include<iostream>
using namespace std;
class DisplayMaker
{
	string startDisp, homeDisp, townDisp, forestDisp;
public:
	DisplayMaker();
	string GetStartDisp();
	string GetHomeDisp();
	string GetTownDisp();
	string GetForestDisp();
};