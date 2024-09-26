#include "Scene.h"

void Scene::Print() const
{
	cout << "이름 : " << name << "\n";
	cout << "설명 : " << desc << "\n";
	cout << "========= 출력되는 화면 =========\n" << disp;
}