#include "Scene.h"

string Scene::GetName()
{
	return name;
}

void Scene::SetPrintDisplay(const string& display)
{
	disp = display;
	/*cout << "�̸� : " << name << "\n";
	cout << "���� : " << desc << "\n";
	cout << "========= ��µǴ� ȭ�� =========\n";*/
	cout << disp;
}