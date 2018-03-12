#include "Towers.h"
#include <assert.h>
#include <iostream>

void test() {
	IFactory* fac = new CFactoryNormal;
	ITower* tower = fac->Create();
	std::cout << "Done!";
	delete fac;
	delete tower;
}

int main() {
	test();

	system("pause");
}