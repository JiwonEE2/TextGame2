#include "Scene.h"

void Scene::Print() const
{
	cout << "�̸� : " << name << "\n";
	cout << "���� : " << desc << "\n";
	cout << "========= ��µǴ� ȭ�� =========\n" << disp;
}

void Scene::SetDisplay(const string& display)
{
	disp = display;
}