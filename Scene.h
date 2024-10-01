#pragma once
#include<iostream>
using namespace std;

class Scene
{
	string name;
	string desc;
	string disp;
public:
	Scene(const string& name, const string& desc) :name(name), desc(desc) {}
	void SetPrintDisplay(const string& display);
};