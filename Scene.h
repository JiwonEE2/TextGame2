#pragma once
#include<iostream>
using namespace std;

class Scene
{
	string name;
	string desc;
	string disp;
public:
	Scene(const string& name, const string& desc, const string& disp) :name(name), desc(desc), disp(disp) {}
	void Print()const;
	void SetDisplay(const string& display);
};