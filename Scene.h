#pragma once
#include<iostream>
using namespace std;

class Scene
{
	string name;
	string desc;
public:
	Scene(const string& name, const string& desc) :name(name), desc(desc) {}
	void Print()const;
};