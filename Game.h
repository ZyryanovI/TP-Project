#pragma once
#include "AllClasses.h"
#include "Player.h"
#include <vector>

class CGame {
private:
	static CGame* _obj;
	CGame();
	~CGame();

public:
	std::vector<CPoint*> points;
	CPlayer player1;
	CPlayer player2;

	CGame(const CGame&) = delete;
	const CGame& operator=(const CGame&) = delete;

	static CGame* Instance();
	static void DeleteInstance();
};
