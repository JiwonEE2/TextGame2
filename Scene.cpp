#include "Scene.h"

string Scene::GetName()
{
	return name;
}

void Scene::SetPrintDisplay(const string& display)
{
	disp = display;
	/*cout << "이름 : " << name << "\n";
	cout << "설명 : " << desc << "\n";
	cout << "========= 출력되는 화면 =========\n";*/
	cout << disp;
}