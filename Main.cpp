#include "AllClasses.h"
#include "Tower.h"
#include "Game.h"
#include <assert.h>
#include <iostream>
#include <string>

void test() {
	IFactory* fac = new CFactoryNormal;
	CTower* tower = fac->Create();
	std::cout << "Done!";
	delete fac;
	delete tower;
}

void test2() {
	CGame* game = CGame::Instance();
	CGame::DeleteInstance();
}

int main() {
	test();
	test2();

	std::string s;
	std::cin >> s;
}