#include "Scene.h"

void Scene::SetPrintDisplay(const string& display)
{
	disp = display;
	cout << "�̸� : " << name << "\n";
	cout << "���� : " << desc << "\n";
	cout << "========= ��µǴ� ȭ�� =========\n" << disp;
}