#include "AllClasses.h"
#include "Tower.h"
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

int main() {
	test();

	std::string s;
	std::cin >> s;
}