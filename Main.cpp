#include "AllClasses.h"
#include "Tower.h"
#include "Game.h"
#include "Point.h"
#include "Producer.h"
#include <assert.h>
#include <iostream>
#include <string>

void test2() {
	CGame* game = CGame::Instance();
	CGame::DeleteInstance();
}

void test3() {
	IProducer* producer = new CProducer;
	shared_ptr<IFactory> fac = std::make_shared<CFactoryEnlarger>();
	CPlayer pl;
	CPoint po;

	producer->SetFactoryAndPlayer(&pl, fac);
	
	CTower* tower = producer->Create(&po);

	delete tower;
	delete producer;
}

int main() {
	test2();
	test3();
	std::cout << "Done!\n";
	std::string s;
	std::cin >> s;
}